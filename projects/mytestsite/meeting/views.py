# Create your views here.
from django.http import HttpResponse
from django.shortcuts import redirect
from django.template import Context, loader

from django.contrib.auth.decorators import login_required
from django.contrib.auth import logout

@login_required
def index(request):
    if request.user.is_authenticated():
        groups = "".join([str(group) for group in request.user.groups.all()])
        if "requester" == groups.lower():
            t = loader.get_template('requestor.html')
            c = Context({'user':request.user, 'group':'Requestor'})
        elif "approver" == groups.lower():
            t = loader.get_template('approver.html')
            c = Context({'user':request.user, 'group':'Approver'})
        return HttpResponse(t.render(c))

def logout_view(request):
    logout(request)
    return redirect('/')
