import asyncio
from asgiref.sync import sync_to_async
from .serializers import SaveGameDataSerializer
from .models import Game as GameModel

players = []

class Player:
    def __init__(self, consumer, user_name, id):
        self.consumer = consumer
        self.user_name = user_name
        self.player_id = id
class Game:
    # Game parameters:
    BALL_SPEED = 0.5
    PADDLE_SPEED = 4
    PADDLE_WIDTH = 8
    PADDLE_LENGHT = 24
    REQUIRED_CONNECTIONS = 2
    WIDTH = 120
    HEIGHT = 80
    RADIO = 2

    def __init__(self, game_id, channel_layer, game_group_name):
        # Game information
        self.game_id = game_id
        self.players = [] # just player uuids
        self.update_lock = asyncio.Lock()
        self.channel_layer = channel_layer
        self.game_group_name = game_group_name
        # Game attributes
        self.ball_x = 0
        self.ball_y = 0
        self.ball_dx = 1
        self.ball_dy = 1
        self.p1_y = 0
        self.p2_y = 0
        self.score_1 = 0
        self.score_2 = 0
        self.winner = ""

    async def add_player(self, Player):
        if len(self.players) >= self.REQUIRED_CONNECTIONS:
            return False
        self.players.append(Player.player_id)
        return True

    async def remove_player(self, player_id):
        if player_id in self.players:
            self.players.remove(player_id)

    def restart_game(self):
        self.ball_x = 0
        self.ball_y = 0
        self.p1_y = 0
        self.p2_y = 0

    async def game_loop(self):
        await asyncio.sleep(1)
        if len(self.players) != self.REQUIRED_CONNECTIONS:
            await self.channel_layer.group_send(
            self.game_group_name,
            {"type": "state_update", "objects": self.get_game_state_def()},
            )
            # Game ended
            print("Game ended")
            print("Player list " + str(self.players))
            print("score_1: ", self.score_1)
            print("score_2: ", self.score_2)
            self.winner = self.players[0]
            await self.channel_layer.group_send(
                self.game_group_name,
                {"type": "finish_game", "winner": self.winner},
            )
            return

        register = 0
        aux_register = 0
        while len(self.players) == self.REQUIRED_CONNECTIONS:
            async with self.update_lock:
                await asyncio.sleep(0.01)

                # Revote con las palas izquierda
                if (
                        self.ball_x <= -( self.WIDTH / 2) + self.PADDLE_WIDTH
                        and (self.p1_y - (self.PADDLE_LENGHT / 2)) <= self.ball_y
                        and  self.ball_y <= (self.p1_y + (self.PADDLE_LENGHT / 2))
                ):
                    self.ball_dx = -self.ball_dx

                # Revote con las palas derecha
                elif (
                        self.ball_x >= ( self.WIDTH / 2) - self.PADDLE_WIDTH
                        and (self.p2_y - (self.PADDLE_LENGHT / 2)) <= self.ball_y
                        and  self.ball_y <= (self.p2_y + (self.PADDLE_LENGHT / 2))
                ):
                    self.ball_dx = -self.ball_dx

                # Goles
                elif self.ball_x <= -self.WIDTH / 2:
                    self.restart_game()
                    self.ball_dx = -self.ball_dx
                    self.score_2 += 1
                    register += 1

                elif self.ball_x >= self.WIDTH / 2:
                    self.restart_game()
                    self.ball_dx = -self.ball_dx
                    self.score_1 += 1;
                    register += 1

                # Rebote con las paredes horizontales
                elif self.ball_y - self.RADIO <= -self.HEIGHT / 2:
                    self.ball_dy = -self.ball_dy
                elif self.ball_y + self.RADIO >= self.HEIGHT / 2:
                    self.ball_dy = -self.ball_dy

                elif (-(self.WIDTH / 2) < self.ball_x <= (-(self.WIDTH/ 2) + self.PADDLE_WIDTH)
                        and self.ball_y - self.RADIO > self.p1_y
                        and self.ball_y - self.RADIO <= (self.p1_y + (self.PADDLE_LENGHT / 2))
                        and self.ball_dy == -1
                ):
                    self.ball_dy = -self.ball_dy

                elif (-(self.WIDTH / 2) < self.ball_x <= (-(self.WIDTH/ 2) + self.PADDLE_WIDTH)
                        and self.ball_y + self.RADIO < self.p1_y
                        and self.ball_y + self.RADIO >= (self.p1_y - (self.PADDLE_LENGHT / 2))
                        and self.ball_dy == 1
                ):
                    self.ball_dy = -self.ball_dy

                elif (((self.WIDTH/ 2) - self.PADDLE_WIDTH) <= self.ball_x < (self.WIDTH / 2)
                        and self.ball_y - self.RADIO > self.p2_y
                        and self.ball_y - self.RADIO <= (self.p2_y + (self.PADDLE_LENGHT / 2))
                        and self.ball_dy == -1
                ):
                    self.ball_dy = -self.ball_dy

                elif (((self.WIDTH/ 2) - self.PADDLE_WIDTH) <= self.ball_x < (self.WIDTH / 2)
                        and self.ball_y + self.RADIO < self.p2_y
                        and self.ball_y + self.RADIO >= (self.p2_y - (self.PADDLE_LENGHT / 2))
                        and self.ball_dy == 1
                ):
                    self.ball_dy = -self.ball_dy



                # Update the ball position:
                self.ball_x += self.ball_dx * self.BALL_SPEED
                # print(self.ball_x)
                self.ball_y += self.ball_dy * self.BALL_SPEED
                if (self.score_1 == 3 or self.score_2 == 3):
                    break

            # Send updated state:
            await self.channel_layer.group_send(
                self.game_group_name,
                {"type": "state_update", "objects": self.get_game_state()},
            )
            await asyncio.sleep(0.01)
            if (register != aux_register):
                await asyncio.sleep(0.2)
                aux_register = register


        await self.channel_layer.group_send(
            self.game_group_name,
            {"type": "state_update", "objects": self.get_game_state()},
        )
        # Game ended
        print("Game ended")
        print("Player list " + str(self.players))
        print("score_1: ", self.score_1)
        print("score_2: ", self.score_2)
        if (self.score_1 == 3):
            print("Player 1 WINSSSSS: ", self.players[0])
            self.winner = self.players[0]
        elif (self.score_2 == 3):
            print("Player 2 WINSSSSS: ", self.players[1])
            self.winner = self.players[1]
        await self.channel_layer.group_send(
            self.game_group_name,
            {"type": "finish_game", "winner": self.winner},
        )


    def can_move_paddle(self, player_position, movement):
        top_limit = -(self.HEIGHT / 2) + self.PADDLE_LENGHT / 2
        bottom_limit = self.HEIGHT / 2 - self.PADDLE_LENGHT / 2
        return (top_limit <= player_position + movement * self.PADDLE_SPEED <= bottom_limit)

    async def move_paddle(self, paddle, movement):
        print("paddle: ", paddle)
        async with self.update_lock:
            if (paddle == 0 and self.can_move_paddle(self.p1_y, movement)):
                self.p1_y += movement * self.PADDLE_SPEED

            elif (paddle == 1 and self.can_move_paddle(self.p2_y, movement)):
                self.p2_y += movement * self.PADDLE_SPEED
            print("------> ", self.p1_y, " | ", self.p2_y)

    async def disconnect_player(self, player):
        print("player: ", player)
        if (player == 0):
            self.score_2 = 3
        elif (player == 1):
            self.score_1 = 3

    def get_player(self, player_id):
        for index, player in enumerate(self.players):
            if player == player_id:
                return index
        return None


    def end_game(self):
        self.restart_game();
        self.score_1 = 0;
        self.score_2 = 0;

    def get_game_state(self):
        # Return the game state as a dictionary
        for player in players:
            if player.player_id == self.players[0]:
                player1 = player.user_name
            elif player.player_id == self.players[1]:
                player2 = player.user_name
        return {
            "players": self.players,
            "player1": player1,
            "player2": player2,
            "ball_x": self.ball_x,
            "ball_y": self.ball_y,
            "ball_dx": self.ball_dx,
            "ball_dy": self.ball_dy,
            "p1_y": self.p1_y,
            "p2_y": self.p2_y,
            "score_1": self.score_1,
            "score_2": self.score_2,
            "winner": self.winner,
        }

    def get_game_state_def(self):
        # Return the game state as a dictionary
        for player in players:
            if player.player_id == self.players[0]:
                player1 = player.user_name
        return {
            "players": self.players,
            "player1": player1,
            "player2": "ERROR",
            "ball_x": self.ball_x,
            "ball_y": self.ball_y,
            "ball_dx": self.ball_dx,
            "ball_dy": self.ball_dy,
            "p1_y": self.p1_y,
            "p2_y": self.p2_y,
            "score_1": self.score_1,
            "score_2": self.score_2,
            "winner": player1,
        }
