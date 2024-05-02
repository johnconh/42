import bisect
import uuid
import json
from channels.generic.websocket import AsyncWebsocketConsumer

# Esta es una lista de jugadores esperando para ser emparejados, ordenada por ratio de victorias.
waiting_players = []

class Player:
    def __init__(self, consumer, user_name, ratio):
        self.consumer = consumer
        self.user_name = user_name
        self.ratio = ratio
        self.client_id = tuple(consumer.scope['client'])

class MatchmakingConsumer(AsyncWebsocketConsumer):
    # ...

    async def connect(self):
        await self.accept()

    def playerFinder(self, client_id):
        for i, other in enumerate(waiting_players):
            if (client_id == other.client_id):
                return waiting_players.pop(i)
        return None

    async def disconnect(self, close_code):
        client_id = tuple(self.scope['client'])
        self.playerFinder(client_id)
        print(f"El cliente {client_id} se ha desconectado.")

    async def receive(self, text_data):
        client_id = tuple(self.scope['client'])
        print(f"El cliente {client_id} ha enviado un mensaje.")

        data = json.loads(text_data)
        if data['type'] == "findMatch":
            user_name = data['user_name']
            ratio = float(data['ratio'])

            # Crea un nuevo jugador y trata de encontrar un emparejamiento.
            player = Player(self, user_name, ratio)
            match = self.find_match(player)

            if match:
                # Si se encontró un emparejamiento, envía un mensaje a ambos jugadores.
                game_id = uuid.uuid4()
                await self.send(text_data=json.dumps({"type": "matchFound", "gameId": str(game_id), "opponent": match.user_name}))
                await match.consumer.send(text_data=json.dumps({"type": "matchFound", "gameId": str(game_id), "opponent": user_name}))
            else:
                # Si no se encontró un emparejamiento, agrega al jugador a la lista de espera.
                waiting_players.append(player)
        else:
            self.playerFinder(client_id)
            print(f"El cliente {client_id} se ha desconectado.")


    def find_match(self, player):
        # Busca un jugador en la lista de espera con un ratio de victorias similar.
        # Si no se encuentra ninguno, devuelve None.
        for i, other in enumerate(waiting_players):
            if abs(player.ratio - other.ratio) <= 0.3:
                if (other.client_id != player.client_id):
                    return waiting_players.pop(i)
        return None
    
    # def queue_leave(self, user_name):
    #     for i, player in enumerate(waiting_players):
    #         if player.user_name == user_name:
    #             waiting_players.pop(i)
    #             return
    # def queue_search(self, user_name):