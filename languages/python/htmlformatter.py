# written by Eric
# http://studiozero.proboards.com/index.cgi?board=opensrc&action=display&thread=10666

import sys

if sys.version.startswith('3'):
    from html.parser import HTMLParser
else:
    from HTMLParser import HTMLParser

class HTMLFormatter(HTMLParser):
    """Formats HTML"""
    
    def __init__(self):
        HTMLParser.__init__(self)
        self.tabbed = 0
        self.formatted = []

    def append(self, data):
        self.formatted.append(str(data))

    def _write_tabs(self):
        self.append('\t'*self.tabbed)

    def _format_attrs(self, attrs):
        fattrs = ""
        for a,v in attrs:
            fattrs = fattrs + " " + a + '="' + v.replace('"', '\\"') + '"'
        return fattrs
            
    def _format_tag(self, tag, ttype='start', ats=None):
        ftag = '<'
        if ttype == 'end':
            ftag = ftag + '/'
        ftag = ftag + tag
        if ats != None and len(ats):
            ftag = ftag + self._format_attrs(ats)
        if ttype == 'self':
            ftag = ftag + ' /'
        ftag = ftag + '>'
        return ftag
    
    def handle_starttag(self, tag, attrs):
        self._write_tabs()
        self.tabbed = self.tabbed + 1
        self.append(self._format_tag(tag, ats=attrs) + '\n')

    def handle_endtag(self, tag):
        self.tabbed = self.tabbed - 1
        self._write_tabs()
        self.append(self._format_tag(tag, ttype='end') + '\n')

    def handle_startendtag(self, tag, attrs):
        self._write_tabs()
        self.append(self._format_tag(tag, ttype='self', ats=attrs) + '\n')
        
    def handle_data(self, data):
        data = data.strip()
        if(len(data)):
            self._write_tabs()
            self.append(data + '\n')

    def handle_charref(self, name):
        self.append('&#'+name+';')

    def handle_entityref(self, name):
        self.append('&'+name+';')

    def handle_comment(self, data):
        data = '<!--' + data + '-->'
        self._write_tabs();
        self.append(data + '\n')

    def handle_decl(self, decl):
        self._write_tabs()
        self.append('<!'+decl+'>')

    def handle_pi(self, data):
        self._write_tabs()
        self.append('<?'+data+'>')

    def render(self):
        return "".join(self.formatted)

if __name__ == "__main__":
    import sys
    if len(sys.argv) == 3:
        try:
            n = HTMLFormatter()
            f = open(sys.argv[1], 'r')
            n.feed(f.read())
            f.close()
            f = open(sys.argv[2], 'w')
            f.write(n.render())
            f.close()
        except IOError:
            print("Failed opening or writing to files '{0}', '{1}'".format(sys.argv[1], sys.argv[2]))
    else:
        print("Wrong number of arguments")
