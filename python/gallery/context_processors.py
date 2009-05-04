from gallery.settings import ROOT_URL

def root_url_processor(request):
    return {'ROOT_URL': ROOT_URL}
