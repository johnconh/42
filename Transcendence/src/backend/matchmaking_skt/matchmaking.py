from asgiref.sync import sync_to_async
from channels.layers import get_channel_layer
import asyncio
import time

def matchQueStart():
    # print("Matchmaking started MELAEMPOTRO")
    # asyncio.create_task(matchmaking_logic())

# def matchmaking_logic():
    while True:
        # Obtener la lista de clientes en la cola de emparejamiento
        print("LUCES TENUES")
        # clients = await obtener_clientes_en_cola()
        # print("MI BEBESITA")
        # print(clients)
        
        # # if clients is None:
        # #     print("No hay clientes en la cola")
        # #     await asyncio.sleep(1)
        # #     continue
        # if clients is not None:
        #     print("clients: ", clients)
        #     # Emparejar a los dos primeros jugadores
        #     jugador1 = clients[0]
        #     jugador2 = clients[1]
            
        #     # Notificar a los jugadores emparejados
        #     await notificar_emparejamiento(jugador1, jugador2)
            
        #     # Eliminar a los jugadores emparejados de la cola
        #     await eliminar_jugadores_emparejados(jugador1, jugador2)
        # print("ESOEUNAMENTIRA")
        # await asyncio.sleep(0.5)  # Esperar un segundo antes de revisar de nuevo
        # print("AUNEEEEL")
        time.sleep(1)

async def obtener_clientes_en_cola():
    channel_layer = get_channel_layer()
    group_name = "matchmaking"
    clients = channel_layer.groups.get(group_name)
    print("clients: >>>>>>")
    print(clients)
    print("<<<<<<<<<<<<<<<<")
    return clients

async def notificar_emparejamiento(jugador1, jugador2):
    channel_layer = get_channel_layer()
    group_name = "matchmaking"
    message = {"type": "match_found", "matchData": {"jugador1": jugador1, "jugador2": jugador2}}
    await channel_layer.group_send(group_name, message)

async def eliminar_jugadores_emparejados(jugador1, jugador2):
    channel_layer = get_channel_layer()
    group_name = "matchmaking"
    await channel_layer.group_discard(group_name, jugador1)
    await channel_layer.group_discard(group_name, jugador2)