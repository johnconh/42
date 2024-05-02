import bisect
from time import sleep
import uuid
import json
from channels.generic.websocket import AsyncWebsocketConsumer
import threading

tournamentRooms = []
playerList = []

def tournament_printer():
    while True:
        sleep(3)
        for room in tournamentRooms:
            print(f"DIMEBRODER: {room.room_name}, {room.phase}, ")
            for player in room.players:
                print(f"Player: {player.user_name}, {player.inTournamentID}, {player.tournamentCode}, {player.client_id}")
            for temp_player in room.temp_players:
                print(f"TPlayer: {temp_player.user_name}, {temp_player.inTournamentID}, {temp_player.tournamentCode}, {temp_player.client_id}")

        # for player in playerList:
        #     print(f"Player: {player.user_name}, {player.inTournamentID}, {player.tournamentCode}, {player.client_id}")

def playerList_printer():
    while True:
        sleep(3)
        for player in playerList:
            print(f"Player: {player.user_name}, {player.inTournamentID}, {player.tournamentCode}, {player.client_id}")
    
thread = threading.Thread(target=tournament_printer)
thread.start()

def playerList_printer():
    for player in playerList:
        print(f"Player: {player.user_name}, {player.inTournamentID}, {player.tournamentCode}, {player.client_id}")

class Player:
    def __init__(self, consumer, user_name, tournamentCode):
        self.consumer = consumer
        self.user_name = user_name
        self.tournamentCode = tournamentCode
        self.inTournamentID = None
        self.client_id = tuple(consumer.scope['client'])

class TournamentRoom:
    def __init__(self, room_name):
        self.players = []
        self.temp_players = []
        self.final_game = []
        self.temp_final_game = []
        self.finalWinner = None
        self.finalWinnerName = None
        self.phase = 0
        self.conter = 0
        self.oneTwoWinner = None
        self.threeFourWinner = None
        self.room_name = room_name
        self.max_players = 4
        self.fgamestarted = False
        self.finalUUID = None
    
    async def add_player(self, player):
        id = 0;
        if self.phase != 0:
            return
        print(f"Añadiendo al jugador {player.user_name} al torneo {self.room_name}.")
        if len(self.players) == self.max_players:
            return
        if player.user_name in [player.user_name for player in self.players]:
            return
        for p in self.players:
            print(f"Buscando ID para el jugador {p.user_name}, {p.inTournamentID}.")
            if p.inTournamentID == id:
                print(f"El ID {id} ya está ocupado.")
                id += 1
        self.players.append(player)
        print(f"El jugador {player.user_name} ha sido asignado al ID {id}.")
        player.inTournamentID = id
        all_players = [player.user_name for player in self.players]
        await self.message_all({"type": "tournamentPlayers", "players": all_players})
        # await self.message_all({"type": "playerJoined", "user_name": player.user_name})
        if len(self.players) == self.max_players:
            self.temp_players.append(Player(self.players[0].consumer, self.players[0].user_name, self.players[0].tournamentCode))
            self.temp_players.append(Player(self.players[1].consumer, self.players[1].user_name, self.players[1].tournamentCode))
            self.temp_players.append(Player(self.players[2].consumer, self.players[2].user_name, self.players[2].tournamentCode))
            self.temp_players.append(Player(self.players[3].consumer, self.players[3].user_name, self.players[3].tournamentCode))
            uuid1 = uuid.uuid4()
            uuid2 = uuid.uuid4()
            print(f"El torneo {self.room_name} está lleno.")
            await self.start_game(uuid1, uuid2)

    async def start_game(self, uuid1, uuid2):
        self.phase = 1
        print(f"El torneo {self.room_name} ha comenzado.")
        for player in self.players:
            print(f"UUID1: {uuid1}, UUID2: {uuid2}.")
            if player.inTournamentID == 0 or player.inTournamentID == 1:
                await player.consumer.send(text_data=json.dumps({"type": "gameStart", "gameid": str(uuid1)}))
            elif player.inTournamentID == 2 or player.inTournamentID == 3:
                await player.consumer.send(text_data=json.dumps({"type": "gameStart", "gameid": str(uuid2)}))

    async def start_final_game(self, uuid1):
        if self.fgamestarted:
            return
        fgamestarted = True
        print(f"LA FINAL {self.room_name} ha comenzado.")
        for player in self.final_game:
            print(f"UUID1: {uuid1}.")
            print(f"Enviando mensaje a {player.user_name}.")
            await player.consumer.send(text_data=json.dumps({"type": "finalStart", "gameid": str(uuid1)}))
    
    async def remove_player(self, player):
        print(f"Eliminando al jugador {player.user_name} del torneo {self.room_name}.")
        # if player not in self.players:
        #     print(f"El jugador {player.user_name} no está en el torneo {self.room_name}.")
        #     return
        for i, p in enumerate(self.players):
            if (player.user_name == p.user_name):
                self.players.pop(i)
                break
        # self.players.remove(player)
        if self.phase == 0:
            for i, p in enumerate(self.players):
                p.inTournamentID = i
            all_players = [player.user_name for player in self.players]
            print(f"Jugadores restantes: {all_players}")
            await self.message_all({"type": "tournamentPlayers", "players": all_players})
    
    async def message_all(self, message):
        print(f"Enviando mensaje a todos los jugadores del torneo {self.room_name}.")
        for player in self.players:
            print(f"Enviando mensaje a {player.user_name}.")
            await player.consumer.send(text_data=json.dumps(message))

    async def message_winners(self, message):
        print(f"Enviando mensaje a los ganadores del torneo {self.room_name}.")
        print("MESSAGE: ", message)
        for player in self.final_game:
            print(f"Enviando mensaje a {player.user_name}.")
            await player.consumer.send(text_data=json.dumps(message))
    
    async def message_winner(self, message):
        print(f"Enviando mensaje al ganador del torneo {self.room_name}.")
        print("MESSAGE: ", message)
        await self.finalWinner.consumer.send(text_data=json.dumps(message))

    def remove_room_players(self):
        for player in self.players:
            print(f"Eliminando al jugador {player.user_name} del torneo {self.room_name}.")
            for p in playerList:
                if (player.user_name == p.user_name):
                    playerList.remove(p)
                    break

class TournamentConsumer(AsyncWebsocketConsumer):

    def end_tournament(self, room_name):
        room = self.search_room(room_name)
        # print("ROOM: ", room.room_name)
        room.remove_room_players()
        room.phase = 5
        room.oneTwoWinner = None
        room.threeFourWinner = None
        room.finalWinner = None
        room.finalWinnerName = None
        room.final_game = []
        room.temp_final_game = []
        room.temp_players = []
        room.players = []
        self.remove_room(room_name)

    def create_room(self, room_name):
        room = TournamentRoom(room_name)
        tournamentRooms.append(room)
        return room
    
    def remove_room(self, room_name):
        for i, room in enumerate(tournamentRooms):
            if (room_name == room.room_name):
                tournamentRooms.pop(i)
                break
    
    def search_room(self, room_name):
        for i, room in enumerate(tournamentRooms):
            if (room_name == room.room_name):
                return tournamentRooms[i]
        return None
    
    def search_player(self, client_id):
        for i, player in enumerate(playerList):
            if (client_id == player.client_id):
                return playerList[i]
        print("NO SE ENCONTRÓ EL JUGADOR")
        return None
    
    def search_player_by_name(self, user_name):
        for i, player in enumerate(playerList):
            if (user_name == player.user_name):
                return playerList[i]
        return None

    async def connect(self):
        playerList_printer()
        await self.accept()

    async def disconnect(self, close_code):
        print("CUIDAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAO")
        client_id = tuple(self.scope['client'])
        print(f"El cliente {client_id} se ha desconectado.")
        player = self.search_player(client_id)
        if player:
            print("PLAYER: ", player.user_name)
            room = self.search_room(player.tournamentCode)
            if room:
                await room.remove_player(player)
                if len(room.players) == 0:
                    self.remove_room(room.room_name)
            for player in self.players:
                print(f"Player: {player.user_name}, {player.inTournamentID}, {player.tournamentCode}, {player.client_id}")
            print("\n\n")

    async def receive(self, text_data):
        playerList_printer()
        client_id = tuple(self.scope['client'])
        data = json.loads(text_data)
        print("DATA: ", data)
        tournamentCode = data['tournamentCode']
        if data['user_name']:
            user_name = data['user_name']

        if data['type'] == "joinTournament":
            player = Player(self, user_name, tournamentCode)
            playerList.append(player)
            room = self.find_room(tournamentCode)
            if room:
                if len(room.players) < room.max_players:
                    # room.players.append(player)
                    await room.add_player(player)
                    # if len(room.players) == room.max_players:
                    #     room.temp_players = room.players
                    #     await self.send(text_data=json.dumps({"type": "tournamentReady", "tournamentCode": tournamentCode}))
                else:
                    print(f"El torneo {tournamentCode} está lleno.")
                    await self.send(text_data=json.dumps({"type": "tournamentFull", "tournamentCode": tournamentCode}))
            else:
                room = TournamentRoom(tournamentCode)
                room.players.append(player)
                tournamentRooms.append(room)
                await self.send(text_data=json.dumps({"type": "tournamentReady", "tournamentCode": tournamentCode}))

        elif data['type'] == "leaveTournament":
            room = self.find_room(tournamentCode)
            if room:
                for i, player in enumerate(room.players):
                    if (player.client_id == client_id):
                        room.players.pop(i)
                        break
                if len(room.players) == 0:
                    tournamentRooms.remove(room)
            print(f"El cliente {client_id} ha abandonado el torneo {tournamentCode}.")
        
        elif data['type'] == "createTournament":
            if not self.find_room(tournamentCode):
                room = self.create_room(tournamentCode)
                player = Player(self, user_name, tournamentCode)
                playerList.append(player)
                await room.add_player(player)
                print(f"Se ha creado el torneo {tournamentCode}.")
                self.finalUUID = uuid.uuid4()
            else:
                print(f"El torneo {tournamentCode} ya existe.")

        elif data['type'] == "gameResult":
            room = self.find_room(tournamentCode)
            player = self.search_player_by_name(user_name)
            if room:
                if player.inTournamentID == 0 or player.inTournamentID == 1:
                    if room.oneTwoWinner == None:
                        room.oneTwoWinner = data['winner']
                        room.temp_final_game.append(player)
                        print(f"El 1 ganador del torneo {tournamentCode} es {room.oneTwoWinner}.")
                elif player.inTournamentID == 2 or player.inTournamentID == 3:
                    if room.threeFourWinner == None:
                        room.threeFourWinner = data['winner']
                        print(f"EN TU CLOSE {room.threeFourWinner}.")
                        print(f"CUANDO TE ARREBATAS {data['winner']}")
                        room.temp_final_game.append(player)
                        print(f"El 2 ganador del torneo {tournamentCode} es {room.threeFourWinner}.")
                print("PLAYER: ", player.user_name)
                print("WINNER1: ", room.oneTwoWinner)
                print("WINNER2: ", room.threeFourWinner)
                if room.oneTwoWinner == player.user_name or room.threeFourWinner == player.user_name:
                    new_player = Player(self, player.user_name, player.tournamentCode)
                    new_player.inTournamentID = player.inTournamentID
                    room.final_game.append(new_player)
                    playerList.remove(player)
                    playerList.append(new_player)
                all_players = [player.user_name for player in room.temp_players]
                send = {"type": "phaseTwo",
                        "players": all_players,
                        "winner1": room.oneTwoWinner,
                        "winner2": room.threeFourWinner,
                        "code": player.tournamentCode}
                await room.message_all(send)
                print("FINAL GAME: ", room.final_game.__len__())
                if len(room.final_game) == 2 and room.fgamestarted == False:
                    if room.oneTwoWinner == player.user_name or room.threeFourWinner == player.user_name:
                        active_players = [player.user_name for player in room.players]
                        print("ACTIVE PLAYERS: ", active_players)
                        if room.oneTwoWinner not in active_players:
                            send = {"type": "phaseThree",
                            "players": all_players,
                            "winner1": room.oneTwoWinner,
                            "winner2": room.threeFourWinner,
                            "winner": room.threeFourWinner,
                            "code": player.tournamentCode}
                            await room.message_all(send)
                            self.end_tournament(room.room_name)
                        elif room.threeFourWinner not in active_players:
                            send = {"type": "phaseThree",
                            "players": all_players,
                            "winner1": room.oneTwoWinner,
                            "winner2": room.threeFourWinner,
                            "winner": room.oneTwoWinner,
                            "code": player.tournamentCode}
                            await room.message_all(send)
                            self.end_tournament(room.room_name)
                        else:
                            await room.start_final_game(uuid.uuid4())

        elif data["type"] == "finalResult":
            room = self.find_room(tournamentCode)
            player = self.search_player_by_name(user_name)
            if room:
                if room.finalWinnerName == None:
                    room.finalWinnerName = data['winner']
                    print(f"El ganador del torneo {tournamentCode} es {room.finalWinnerName}.")
                if room.finalWinnerName == player.user_name:
                    new_player = Player(self, player.user_name, player.tournamentCode)
                    new_player.inTournamentID = player.inTournamentID
                    room.finalWinner = new_player
                    playerList.remove(player)
                    playerList.append(new_player)
                all_players = [player.user_name for player in room.temp_players]
                send = {"type": "phaseThree",
                        "players": all_players,
                        "winner1": room.oneTwoWinner,
                        "winner2": room.threeFourWinner,
                        "winner": room.finalWinnerName,
                        "code": player.tournamentCode}
                await room.message_all(send)
                self.end_tournament(room.room_name)
                # if room.finalWinner:
                    # if player.user_name == room.finalWinnerName:
                    #     if room.finalWinner == None:
                    #         room.finalWinner = player
                    # all_players = [player.user_name for player in room.players]
                    # send = {"type": "phaseThree",
                    #         "players": all_players,
                    #         "winner1": room.oneTwoWinner,
                    #         "winner2": room.threeFourWinner,
                    #         "winner": room.finalWinnerName,
                    #         "code": player.tournamentCode}
                    # await room.message_all(send)
                    # if room.finalWinner:
                    #     self.end_tournament(room.room_name)

    def find_room(self, tournamentCode):
        for i, room in enumerate(tournamentRooms):
            if (tournamentCode == room.room_name):
                return tournamentRooms[i]
        return None
