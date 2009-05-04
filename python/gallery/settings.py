DEBUG = True
TEMPLATE_DEBUG = DEBUG

ADMINS = ()
MANAGERS = ADMINS

DATABASE_ENGINE = 'sqlite3'
DATABASE_NAME = 'book.db'

TIME_ZONE = 'America/New_York'
LANGUAGE_CODE = 'en-us'
SITE_ID = 1
USE_I18N = True


SECRET_KEY = 'iy@w6)#gctex-omuue%k!t2=42)_*o__%5xqd#pc^q2iq5b8c*'

TEMPLATE_LOADERS = (
    'django.template.loaders.filesystem.load_template_source',
    'django.template.loaders.app_directories.load_template_source',
)

MIDDLEWARE_CLASSES = (
    'django.middleware.common.CommonMiddleware',
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
)

INSTALLED_APPS = (
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.sites',
    'django.contrib.admin',
    'gallery.items',
)


# Root URL prefix - e.g. '/gallery/' would be for non-top-level domain
ROOT_URL = '/'
LOGIN_URL = ROOT_URL + 'login/'
MEDIA_URL = ROOT_URL + 'media/'
ADMIN_MEDIA_PREFIX = '/media/admin/'
MEDIA_ROOT = './media/'
STATIC_PATH = './media/'
TEMPLATE_CONTEXT_PROCESSORS = (
    'gallery.context_processors.root_url_processor',
    'django.core.context_processors.auth',
)
ROOT_URLCONF = 'gallery.urls'
