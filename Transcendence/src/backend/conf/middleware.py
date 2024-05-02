import json
import jwt
from django.http import HttpResponse
from django.utils.deprecation import MiddlewareMixin
from django.conf import settings


# Define the path to be intercepted by the middleware:
PATH = '/media'

class MediaMiddleware(MiddlewareMixin):
    def process_request(self, request):
        if request.path.startswith(PATH):            
            jwt_token = request.headers.get('authorization', None)
            print("jwt is ==> " + jwt_token.__str__() + " <==")
            if jwt_token:
                trimmed_jwt = (str(jwt_token)).replace("Bearer ", "")
                try:
                    jwt.decode(trimmed_jwt, settings.SECRET_KEY, algorithms=['HS256'])
                    return None
                except jwt.ExpiredSignatureError:
                    response = {"message": "Authentication token has expired."}
                    return HttpResponse(json.dumps(response), status=401)
                except (jwt.DecodeError, jwt.InvalidTokenError):
                    response = {"message": "Authorization token not valid."}
                    return HttpResponse(json.dumps(response), status=401)
            else:
                response = {"message": "Authorization token not found."}
                return HttpResponse(json.dumps(response), status=401)
        return None
