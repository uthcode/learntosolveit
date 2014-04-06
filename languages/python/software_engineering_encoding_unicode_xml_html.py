# From Python Cookbook. Recipe 1.23 - Encoding Unicode Data for XML and HTML.

# Problem: Want to encode Unicode text for output in HTML, or some other XML
# application, using a limited but popular encoding such as ASCII or latin-1

def encode_for_xml(unicode_data, encoding='ascii'):
    return unicode_data.encode(encoding, 'xmlcharrefreplace')

# If you prefer to use HTML's symbolic entity references instead. For this you
# need to define and register a customized encoding error handler.

import codecs
from htmlentitydefs import codepoint2name

def html_replace(exc):
    if isinstance(exc, (UnicodeEncodeError, UnicodeTranslateError)):
        s = [ u'&%s;' % codepoint2name[ord(c)] for c in
        exc.object[exc.start:exc.end]]
        return ''.join(s),exc.end
    else:
        raise TypeError("can't handle %s" % exc.__name__)

codecs.register_error('html_replace',html_replace)


def encode_for_html(unicode_data, encoding='ascii'):
    return unicode_data.encode(encoding, 'html_replace')


if __name__ == '__main__':
    # demo
    data = u'''\
            <html>
            <head>
            <title>Encoding Test</title>
            </head>
            <body>
            <p>accented characters:
            <ul>
            <li>\xe0 (a + grave)
            <li>\xe7 (c + cedilla)
            <li>\xe9 (e + acute)
            </ul>
            <p>symbols:
            <li>\xa3 (British pound)
            <li>\u20ac (Euro)
            <li>\u221e (Infinity)
            </ul>
            </body>
            </html>
            '''
    #print encode_for_xml(data)
    print encode_for_html(data)
