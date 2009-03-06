'''
Upload script specifically engineered for the PyWeek challenge.

Handles authentication and gives upload progress feedback.
'''
import sys, os, httplib, cStringIO, socket, time, getopt

class Upload:
    def __init__(self, filename):
        self.filename = filename

boundary = '--------------GHSKFJDLGDS7543FJKLFHRE75642756743254'
sep_boundary = '\n--' + boundary
end_boundary = sep_boundary + '--'

def mimeEncode(data, sep_boundary=sep_boundary, end_boundary=end_boundary):
    '''Take the mapping of data and construct the body of a
    multipart/form-data message with it using the indicated boundaries.
    '''
    ret = cStringIO.StringIO()
    for key, value in data.items():
        # handle multiple entries for the same name
        if type(value) != type([]): value = [value]
        for value in value:
            ret.write(sep_boundary)
            if isinstance(value, Upload):
                ret.write('\nContent-Disposition: form-data; name="%s"'%key)
                filename = os.path.basename(value.filename)
                ret.write('; filename="%s"\n\n'%filename)
                value = open(os.path.join(value.filename), "rb").read()
            else:
                ret.write('\nContent-Disposition: form-data; name="%s"'%key)
                ret.write("\n\n")
            ret.write(str(value))
            if value and value[-1] == '\r':
                ret.write('\n')  # write an extra newline
    ret.write(end_boundary)
    return ret.getvalue()

class Progress:
    def __init__(self, info, data):
        self.info = info
        self.tosend = len(data)
        self.total = self.tosend/1024
        self.data = cStringIO.StringIO(data)
        self.start = self.now = time.time()
        self.sent = 0
        self.num = 0
        self.stepsize = self.total / 100 or 1
        self.steptimes = []
        self.display()

    def __iter__(self): return self

    def next(self):
        self.num += 1
        if self.sent >= self.tosend:
            print self.info, 'done', ' '*(75-len(self.info)-6)
            sys.stdout.flush()
            raise StopIteration

        chunk = self.data.read(1024)
        self.sent += len(chunk)
        #print (self.num, self.stepsize, self.total, self.sent, self.tosend)

        if self.num % self.stepsize:
            return chunk
        self.display()
        return chunk

    def display(self):
        # figure how long we've spent - guess how long to go
        now = time.time()
        steptime = now - self.now
        self.steptimes.insert(0, steptime)
        if len(self.steptimes) > 5:
            self.steptimes.pop()
        steptime = sum(self.steptimes) / len(self.steptimes)
        self.now = now
        eta = steptime * ((self.total - self.num)/self.stepsize)

        # tell it like it is (or might be)
        if now - self.start > 3:
            M = eta / 60
            H = M / 60
            M = M % 60
            S = eta % 60
            if self.total:
                s = '%s %2d%% (ETA %02d:%02d:%02d)'%(self.info,
                    self.num * 100. / self.total, H, M, S)
            else:
                s = '%s 0%% (ETA %02d:%02d:%02d)'%(self.info, H, M, S)
        elif self.total:
            s = '%s %2d%%'%(self.info, self.num * 100. / self.total)
        else:
            s = '%s %d done'%(self.info, self.num)
        sys.stdout.write(s + ' '*(75-len(s)) + '\r')
        sys.stdout.flush()

class progressHTTPConnection(httplib.HTTPConnection):
    def progress_send(self, str):
        """Send `str' to the server."""
        if self.sock is None:
            self.connect()

        p = Progress('Uploading', str)
        for chunk in p:
            sent = 0
            while sent != len(chunk):
                try:
                    sent += self.sock.send(chunk)
                except socket.error, v:
                    if v[0] == 32:      # Broken pipe
                        self.close()
                    raise
                p.display()

class progressHTTP(httplib.HTTP):
    _connection_class = progressHTTPConnection
    def _setup(self, conn):
        httplib.HTTP._setup(self, conn)
        self.progress_send = self._conn.progress_send

def http_request(data, server, port, url):
    h = progressHTTP(server, port)

    data = mimeEncode(data)
    h.putrequest('POST', url)
    h.putheader('Content-type', 'multipart/form-data; boundary=%s'%boundary)
    h.putheader('Content-length', str(len(data)))
    h.putheader('Host', server)
    h.endheaders()

    h.progress_send(data)

    errcode, errmsg, headers = h.getreply()

    f = h.getfile()
    response = f.read().strip()
    f.close()

    print '%s %s'%(errcode, errmsg)
    if response: print response

def usage():
    print '''This program is to be used to upload files to the PyWeek system.
You may use it to upload screenshots or code submissions.

REQUIRED ARGUMENTS:
 -u   username
 -p   password
 -d   description of file
 -c   file to upload
 -e   entry short name

OPTIONAL ARGUMENTS:
 -s   file is a screenshot
 -f   file is FINAL submission
 -h   override default host name (www.pyweek.org)
 -P   override default host port (80)

In order to qualify for judging at the end of the challenge, you MUST
upload your source and check the "Final Submission" checkbox.
'''


if __name__ == '__main__':
    try:
        optlist, args = getopt.getopt(sys.argv[1:], 'e:u:p:sfd:h:P:c:')
    except getopt.GetoptError, message:
        print message
        usage()
        sys.exit(1)
    host = 'www.pyweek.org'
    port = 80
    data = dict(version=2)
    optional = {}
    url = None
    for opt, arg in optlist:
        if opt == '-u': data['user'] = arg
        elif opt == '-p': data['password'] = arg
        elif opt == '-s': optional['is_screenshot'] = 'yes'
        elif opt == '-f': optional['is_final'] = 'yes'
        elif opt == '-d': data['description'] = arg
        elif opt == '-c': data['content_file'] = Upload(arg)
        elif opt == '-e': url = '/e/%s/oup/'%arg
        elif opt == '-h': host = arg
        elif opt == '-P': port = int(arg)

    if len(data) < 4 or url is None:
        print 'Required argument missing'
        usage()
        sys.exit(1)

    data.update(optional)
    http_request(data, host, port, url)

