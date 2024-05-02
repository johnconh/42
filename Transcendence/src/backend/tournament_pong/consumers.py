import json
import uuid
import asyncio
import math
from asgiref.sync import sync_to_async


from channels.generic.websocket import AsyncWebsocketConsumer
from asgiref.sync import async_to_sync
from .game import Game, Player
from .models import Game as GameModel
from .views import SaveGameDataView
from .game import players

class GameConsumer(AsyncWebsocketConsumer):

    games = {}
    banned_ids = []

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    async def connect(self):
        self.game_id = self.scope["url_route"]["kwargs"]["game_id"]
        self.game_group_name = "game_%s" % self.game_id
        self.playername = self.scope["url_route"]["kwargs"]["playername"]
        print("Game ID: ", self.playername)

        # Create a new game instance if it doesn't exist
        if self.game_id not in self.games:
            self.games[self.game_id] = Game(self.game_id, self.channel_layer, self.game_group_name)

        game = self.games[self.game_id]

        # Identify each player when they connect:
        self.player_id = str(uuid.uuid4())
        player = Player(self, self.playername, self.player_id)
        if not await game.add_player(player):
            return

        await self.accept()

        players.append(player)

        await self.channel_layer.group_add(
            self.game_group_name,
            self.channel_name
        )
        

        # Print connection information
        print("------------------------")
        print("Player " + self.player_id + " has been connected to group " + self.game_group_name)
        print(self.games)
        print(self.games[self.game_id].players)

        # Send the uuid assigned to the player
        await self.send(
            text_data=json.dumps({"type": "playerId", "playerId": self.player_id})
        )

        # If 2 players are connected launch the game_loop
        i = 0;
        while len(game.players) != game.REQUIRED_CONNECTIONS:
            await asyncio.sleep(1)
            print("Waiting for players to connect")
            i += 1
            if i == 3:
                break
        if len(game.players) == game.REQUIRED_CONNECTIONS or i == 3:
            await asyncio.sleep(0.5)
            asyncio.create_task(game.game_loop())

    async def disconnect(self, close_code):
        game = self.games.get(self.game_id)
        print("DISCNNECT")
        if game:
            player = game.get_player(self.player_id)
            await game.disconnect_player(player)
            if (game.winner):
                print("--GAME FNISH")
                game.end_game()
                await game.remove_player(self.player_id)
                for p in players:
                    if p.player_id == self.player_id:
                        players.remove(p)

        await self.channel_layer.group_discard(
            self.game_group_name, self.channel_name
        )
        if len(self.banned_ids) > 20:
            self.banned_ids.clear()
        self.banned_ids.append(self.game_id)

    async def receive(self, text_data):
        game = self.games.get(self.game_id)
        if not game:
            return
        text_data_json = json.loads(text_data)
        player_id = text_data_json.get("playerId")
        print("player_id: " + player_id)
        message_type = text_data_json.get("type")

        player = game.get_player(player_id)

        if message_type == "up":
            await game.move_paddle(player, 1)
        elif message_type == "down":
            await game.move_paddle(player, -1)

    # Captures the event thrown to the group and forwards it to all members
    async def state_update(self, event):
        # for index, player in enumerate(players):
        #     if index == 0:
        #         player1 = player.user_name
        #     elif index == 1:
        #         player2 = player.user_name
        await self.send(
            text_data=json.dumps(
                {
                    "type": "stateUpdate",
                    "objects": event["objects"],
                    # "player1": player1,
                    # "player2": player2,
                }
            )
        )

    def save_gama_info(self):
        pass

    async def get_winner(self, event):
        for player in players:
            # print("player.player_id: " + player.player_id + " event[winner]: " + event["winner"])
            if player.player_id == event["winner"]:
                return player.user_name

    async def save_game(self, event):
        print("save_game called " + str(event))
        game = GameModel.objects.create(
            game_id=event["game_id"],
            player_1=event["players"][0],
            player_2=event["players"][1],
            score_1=event["score"][0],
            score_2=event["score"][1],
        )
        game.save()

    async def finish_game(self, event):
        print("finish_game called ", event)
        # SaveGameDataView.save_game(event)
        winner = await self.get_winner(event)
        await self.send(
            text_data=json.dumps(
                {
                    "type": "finish_game",
                    "winner": winner,
                }
            )
        )
        await self.close()
