from django.conf.urls import patterns, include, url

# Uncomment the next two lines to enable the admin:
from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    url(r'^$', 'meeting.views.index'),
    url(r'login/','django.contrib.auth.views.login', name="my_login"),
    url(r'logout/','meeting.views.logout_view'),
    # url(r'^$', 'mytestsite.views.home', name='home'),
    # url(r'^mytestsite/', include('mytestsite.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    url(r'^admin/doc/', include('django.contrib.admindocs.urls')),

    # Uncomment the next line to enable the admin:
    url(r'^admin/', include(admin.site.urls)),
)
