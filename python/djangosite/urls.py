from django.conf.urls.defaults import *

from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
                       (r'^polls/',include('djangosite.polls.urls')),
                       (r'',include('djangosite.polls.urls')),
                       (r'^admin/(.*)', admin.site.root),
)
