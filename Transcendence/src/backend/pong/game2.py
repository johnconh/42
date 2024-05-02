import asyncio
from asgiref.sync import sync_to_async
from .serializers import SaveGameDataSerializer
from .models import Game as GameModel
from .gameComponents import Paddle, Ball

        

class Game:
    # Game parameters:
    BALL_SPEED = 0.5
    PADDLE_SPEED = 4
    PADDLE_WIDTH = 8
    PADDLE_HEIGHT = 24
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
        self.player1 = Paddle(
            self.PADDLE_WIDTH, 
            self.PADDLE_HEIGHT,
            -(self.WIDTH / 2) + (self.PADDLE_WIDTH / 2),
            self.HEIGHT, self.PADDLE_SPEED
        )
        self.player2 = Paddle(
            self.PADDLE_WIDTH, 
            self.PADDLE_HEIGHT,
            (self.WIDTH / 2) - (self.PADDLE_WIDTH / 2),
            self.HEIGHT, self.PADDLE_SPEED
        )
        self.ball = Ball(self.RADIO, self.BALL_SPEED)
        self.score_1 = 0
        self.score_2 = 0
        self.winner = False

    async def add_player(self, player_id):
        if len(self.players) >= self.REQUIRED_CONNECTIONS:
            return False
        self.players.append(player_id)
        return True

    async def remove_player(self, player_id):
        if player_id in self.players:
            self.players.remove(player_id)

    def gol(self):
        self.player1.reset()
        self.player2.reset()
        self.ball.gol()

    async def game_loop(self):
        register = 0
        aux_register = 0
        while len(self.players) == self.REQUIRED_CONNECTIONS:
            async with self.update_lock:

                # Rebotes
                if (self.player1.right_colision(*self.ball.get_ball_position())):
                    self.ball.vertical_colision()

                elif (
                        self.player1.top_colision(*self.ball.get_ball_position())
                        or self.player1.bottom_colision(*self.ball.get_ball_position())
                ):
                    self.ball.horizontal_colision()

                elif (self.player2.left_colision(*self.ball.get_ball_position())):
                    self.ball.vertical_colision(*self.ball.get_ball_position())

                elif (
                    self.player2.top_colision(*self.ball.get_ball_position())
                    or self.player1.bottom_colision(*self.ball.get_ball_position())
                ):
                    self.ball.horizontal_colision()

                # Goles
                elif self.ball.x <= -self.WIDTH / 2:
                    self.gol()
                    self.score_2 += 1
                    register += 1

                elif self.ball.x >= self.WIDTH / 2:
                    self.gol()
                    self.score_1 += 1;
                    register += 1

                self.ball.move()

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

        await self.channel_layer.group_send(
            self.game_group_name,
            {"type": "state_update", "objects": self.get_game_state()},
        )
        # Game ended
        print("Game ended")
        print("Player list " + str(self.players))
        await self.channel_layer.group_send(
            self.game_group_name,
            {"type": "finish_game", "winner": self.players[0]},
        )

    async def move_paddle(self, paddle, movement):
        print("paddle: ", paddle)
        async with self.update_lock:
            if (paddle == 0):
                self.player1.move_paddle(movement)

            elif (paddle == 1):
                self.player2.move_paddle(movement)

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
        return {
            "players": self.players,
            "ball_x": self.ball.x,
            "ball_y": self.ball.y,
            "ball_dx": self.ball.dx,
            "ball_dy": self.ball.dy,
            "p1_y": self.player1.y,
            "p2_y": self.player2.y,
            "score_1": self.score_1,
            "score_2": self.score_2,
            "winner": self.winner
        }

    async def save_game(self):

        game = GameModel(
                player1="jose",
                player2="pedro",
                player1_result= self.score_1,
                player2_result= self.score_2,
                mode="tournament"
        )
        await sync_to_async(game.save)()
        self.end_game()
