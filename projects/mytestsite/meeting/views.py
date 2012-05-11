# Create your views here.
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import redirect, render_to_response
from django.template import Context, loader

from django.contrib.auth.decorators import login_required
from django.contrib.auth import logout

from meeting.forms import MeetingForm
from meeting.models import Meeting

import datetime

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

def create_meeting(request):
    if request.method == 'POST':
        form = MeetingForm(request.POST)
        if form.is_valid():
            title = form.cleaned_data['title_meeting']
            date = form.cleaned_data['date']
            time = form.cleaned_data['time']
            loc = form.cleaned_data['location']
            dt = datetime.datetime.strptime(date + "-" + time, "%d %m %Y-%H %M")
            approve_status = 1

            m = Meeting(title_meeting=title,
                        date_time = dt,
                        location = loc,
                        requestor = request.user.username,
                        approver = 'janechan',
                        approve = approve_status)
            m.save()
            return HttpResponseRedirect('/')
    else:
        form = MeetingForm()

    return render_to_response('create.html', {'form':form, 'user':request.user})

def view_meetings(request):
    all_meetings = Meeting.objects.all().order_by('-approve')
    t = loader.get_template('view.html')
    c = Context({'user':request.user, 'all_meetings':all_meetings})
    return HttpResponse(t.render(c))

def delete_meeting(request):
    t = loader.get_template('delete.html')
    c = Context({'user':request.user})
    return HttpResponse(t.render(c))

def approve_meeting(request):
    t = loader.get_template('approve.html')
    c = Context({'user':request.user})
    return HttpResponse(t.render(c))

