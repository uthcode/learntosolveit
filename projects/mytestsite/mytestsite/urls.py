from django.conf.urls import patterns, include, url

# Uncomment the next two lines to enable the admin:
from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
    # Common views
    url(r'^$', 'meeting.views.index'),
    url(r'login/','django.contrib.auth.views.login', name="my_login"),
    url(r'logout/','meeting.views.logout_view'),

    # John Doe's views
    url(r'create/','meeting.views.create_meeting'),
    url(r'view/','meeting.views.view_meetings'),

    # Jane Chan's requests
    url(r'delete/','meeting.views.delete_meeting'),
    url(r'approve/','meeting.views.approve_meeting'),

    # admin views
    url(r'^admin/', include(admin.site.urls)),
    url(r'^admin/doc/', include('django.contrib.admindocs.urls')),
)
