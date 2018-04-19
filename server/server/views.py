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
    if user is None:
        if User.objects.filter(username=username).exists():
            return JsonResponse({'res':'密碼錯誤'}, status=403)
        return JsonResponse({'res':'使用者不存在'}, status=403)
    if user is not None and user.is_active:
        # auth.login(request, user)
        token = Token.objects.get_or_create(user=user)
    print(type(str(token[0])))
    return JsonResponse({"token":str(token[0]), "username":username})