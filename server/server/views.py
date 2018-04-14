from django.http import HttpResponse,JsonResponse
from rest_framework.authtoken.models import Token
from django.views.decorators.http import require_POST,require_GET
from django.contrib.auth.models import User
from django.contrib import auth


@require_POST
def login(request):
        
    username = request.POST.get('username','') # 如果沒有這個key 則使用default
    password = request.POST.get('password','')
    print(username, password)
    user = auth.authenticate(username=username, password=password)
    token = None
    if user is not None and user.is_active: # find user and back
        # auth.login(request, user)
        token = Token.objects.get_or_create(user=user)
    
    return JsonResponse({"token":token, "username":username})