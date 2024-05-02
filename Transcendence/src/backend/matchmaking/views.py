from django.http import HttpResponse, JsonResponse
from accounts.models import User
from rest_framework.generics import GenericAPIView
from rest_framework.permissions import IsAuthenticated
import uuid
from django.views.decorators.csrf import csrf_exempt

waiting_players = []
game = []
class join_queue(GenericAPIView):
	permission_classes = [IsAuthenticated]

	@csrf_exempt
	def post(self, request):
		user_name = request.data.get('user_name')
		user = User.objects.get(user_name=user_name)
		if user.games_won == 0 or user.games_lost == 0:
			ratio = 0
		else:
			total = user.games_won + user.games_lost
			ratio = user.games_won/total
			ratio = round(ratio, 2)
		return JsonResponse({"ratio" : ratio}, status=200);

class leave_queue(GenericAPIView):
	permission_classes = [IsAuthenticated]

	@csrf_exempt
	def post(self, request):
		user_name = request.data.get('user_name')
		for player in waiting_players:
			if player['user_name'] == user_name:
				waiting_players.remove(player)
		return JsonResponse({"code" : "420"}, status=200);

class matchmake(GenericAPIView):
	permission_classes = [IsAuthenticated]

	@csrf_exempt
	def post(self, request):
		user_name = request.data.get('user_name')
		ratio = request.data.get('ratio')

		for player in game:
			if player['user_name'] == user_name:
				game.remove(player)
				print(player)
				return JsonResponse(player, status=200);

		for player in waiting_players:
			if player['user_name'] == user_name:
				return JsonResponse({"code" : "69"}, status=400);
		
		waiting_players.append({
			'user_name': user_name,
			'ratio': ratio
		})

		if len(waiting_players) >= 2:
			min_diff = float('inf')
			player1, player2 = None, None
			for i in range(len(waiting_players)):
				for j in range(i+1, len(waiting_players)):
					diff = abs(waiting_players[i]['ratio'] - waiting_players[j]['ratio'])
					if diff < min_diff:
						min_diff = diff
						player1, player2 = waiting_players[i], waiting_players[j]

			if player1 and player2:
				waiting_players.remove(player1)
				waiting_players.remove(player2)
				UUID = uuid.uuid4()
				game.append(
					{
						'user_name': player1['user_name'],
						'rival': player2['user_name'],
						'UUID': UUID
					})
				game.append(
					{
						'user_name': player2['user_name'],
						'rival': player1['user_name'],
						'UUID': UUID
					})
		return JsonResponse({"code" : "69"}, status=400);



