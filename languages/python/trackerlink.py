import operator
import urlparse
import xmlrpclib
import docutils
import sphinx

# TODO: add a cache timeout for re-querying the tracker.
# TODO: check all links for updates in create_Tracker and touch the pages where
#  links have changed.  Should probably rename the method accordingly.


class Tracker:

    def __init__(self, uri, username, password):
        self.tracker = xmlrpclib.ServerProxy(
            'http://%s:%s@%s' % (
                username,
                password,
                uri.partition('://')[2]),
            allow_none=True)

    def find_closed(self, buglist):
        return self.tracker.filter('issue', buglist, {'status': 2})

    def get_fields(self, bug, *fields):
        return self.tracker.display('issue'+bug, *fields)

    def close(self):
        self.tracker.close()


def create_Tracker(app):
    if not app.config.tracker_url: return
    env = app.builder.env
    if not hasattr(env, 'trackerlink_all_links'):
        env.trackerlink_all_links = []
    if not hasattr(env, 'trackerlinks_next_ref_num'):
        env.trackerlinks_next_ref_num = 0
    # This doesn't strike me as good OO programming, but I like the
    # idea of using a global variable in this file even less.
    app.trackerlink_Tracker = Tracker(
        app.config.tracker_url,
        app.config.tracker_username,
        app.config.tracker_password)


class TrackerLink:
    
    def __init__(self, issue, docname, lineno, title, status, ref, target):
        self.issue = issue
        self.docname = docname
        self.lineno = lineno
        self.title = title
        self.status = status
        self.ref = ref
        self.target = target


class TrackerLinks(docutils.nodes.General, docutils.nodes.Element):
    pass


def purge_tracker_links(app, env, docname):
    if not hasattr(env, 'trackerlink_all_links'):
        return
    env.trackerlink_all_links = [ link for link in env.trackerlink_all_links
                                    if link.docname != docname ]

def handle_tracker_link(name, rawtext, text, lineno, inliner,
    options={}, content=[]):
        try:
            issue = int(text)
            if issue<=0:
                raise ValueError
        except ValueError:
            msg = inliner.reporter.error(
                ('Issue number must be a number greater than or equal to '   
                    '1; "%s" is invalid.') % text, line=lineno)
            prb = inliner.problematic(rawtext, rawtext, msg)
            return [prb], [msg]
        issue = str(issue)
        env = inliner.document.settings.env
        app = env.app
        if not app.config.tracker_url:
            text = 'issue ' + issue
            node = docutils.nodes.Text(text, text)
            return [node], []
        try:
            info = app.trackerlink_Tracker.get_fields(issue, 'title', 'status')
        except xmlrpclib.Fault as err:
            msg = inliner.reporter.error(
                ('Could not access tracker issue %s; received xmlrpc error '
                    '"%s"') % (issue, err))
            prb = inliner.problematic(rawtext, rawtext, msg)
            return [prb], [msg]
        ref = urlparse.urljoin(app.config.tracker_url, '/issue%s' % issue)
        #TODO: make this strikethrough styling
        if name=='titledissue':
            linktext = ('issue' + issue + ': %s' % info['title'])
        else:
            linktext = 'issue ' + issue
        if info['status']=='2':
            linktext += ' (closed)'
        docutils.parsers.rst.roles.set_classes(options)
        node = docutils.nodes.reference(
            rawtext,
            linktext,
            refuri=ref,
            **options)
        targetid = "issueref-%s" % env.trackerlinks_next_ref_num
        env.trackerlinks_next_ref_num += 1
        targetnode = docutils.nodes.target('', '', ids=[targetid])
        docname = inliner.document.settings.env.docname
        link = TrackerLink(issue, docname, lineno, info['title'],
                           info['status'], ref, targetnode)
        env.trackerlink_all_links.append(link)
        #TODO: add automatic indexing
        return [targetnode, node], []

        

class TrackerLinksDirective(sphinx.util.compat.Directive):

    def run(self):
        return [TrackerLinks('')]
    

def process_tracker_links(app, doctree, fromdocname):
    if not app.config.tracker_url:
        for node in doctree.traverse(TrackerLinks):
            node.replace_self([])
        return
    env = app.builder.env
    for node in doctree.traverse(TrackerLinks):
        content = []
        para = this = None
        #XXX: the crossref stuff is a bit bogus, needs fixed
        links = sorted(env.trackerlink_all_links,
                       key=operator.attrgetter('issue'))
        for link in links:
            if link.issue!=this:
                if para: content.append(para)
                this = link.issue
                count = 1
                para = docutils.nodes.paragraph()
                #TODO: make this strikethrough or not styling.
                para += docutils.nodes.reference(link.issue, link.issue,
                    refuri=link.ref)
                titletext = ' %s: ' % link.title
                if link.status=='2':
                    titletext += '(closed) '
                para += docutils.nodes.Text(titletext, titletext)
            if count>1:
                para += docutils.nodes.Text(', ', ', ')
            reftext = "%s %s" % (link.docname, link.lineno)
            newnode = docutils.nodes.reference(reftext, reftext)
            newnode['refdocname'] = link.docname
            newnode['refuri'] = app.builder.get_relative_uri(
                fromdocname, link.docname)
            #XXX: refid is an unknown name, so far, so the links are bogus too
            #newnode['refuri'] += '#' + link.target['refid']
            para += newnode
            count += 1
        if para: content.append(para)
        node.replace_self(content)


def setup(app):
    app.add_config_value('tracker_url', '', '')
    app.add_config_value('tracker_username', '', '')
    app.add_config_value('tracker_password', '', '')
    app.connect('env-purge-doc', purge_tracker_links)
    app.add_node(TrackerLink)
    app.add_node(TrackerLinks)
    app.add_role('issue', handle_tracker_link)
    app.add_role('titledissue', handle_tracker_link)
    app.add_directive('trackerlinks', TrackerLinksDirective)
    app.connect('builder-inited', create_Tracker)
    app.connect('doctree-resolved', process_tracker_links)
