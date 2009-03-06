from django.conf.urls.defaults import *

from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('djangosite.polls.views',
                       (r'^$','index'),
                       (r'^(?P<poll_id>\d+)/$','detail'),
                       (r'^(?P<poll_id>\d+)/results/$','results'),
                       (r'^(?P<poll_id>\d+)/vote/$','vote'),

    # Example:
    # (r'^djangosite/', include('djangosite.foo.urls')),

    # Uncomment the admin/doc line below and add 'django.contrib.admindocs' 
    # to INSTALLED_APPS to enable admin documentation:
    # (r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
                        (r'^admin/(.*)', admin.site.root),
)
