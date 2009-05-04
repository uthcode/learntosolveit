from django.conf.urls.defaults import *
from gallery.settings import ROOT_URL
from django.conf import settings

urlpatterns = patterns('',
    url(r'^%s' % ROOT_URL[1:], include('gallery.real_urls')),
)

if settings.DEBUG:
    urlpatterns += patterns('',
                            (r'^media/(?P<path>.*)$',
                             'django.views.static.serve',{'document_root':settings.STATIC_PATH}),
                           )
