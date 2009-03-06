import urllib2


#functions
def reportDownloadProgress(blocknum, bs, size):
    percent = int(blocknum*bs*100/size)
    print str(blocknum*bs ) + '/' + str(size) + 'downloaded| ' + str(percent) + '%'

def httpDownload(url, filename, headers=None, reporthook=None, postData=None):
    reqObj = urllib2.Request(url, postData, headers)
    fp = urllib2.urlopen(reqObj)
    headers = fp.info()
    ##    This function returns a file-like object with two additional methods:
    ##
    ##    * geturl() -- return the URL of the resource retrieved
    ##    * info() -- return the meta-information of the page, as a dictionary-like object
    ##
    ## Raises URLError on errors.
    ##
    ## Note that None may be returned if no handler handles the request (though the default installed 
    ## global OpenerDirector uses UnknownHandler to ensure this never happens).  
    ## read & write fileObj to filename

    tfp = open(filename, 'wb')
    result = filename, headers
    bs = 1024*8
    size = -1
    read = 0
    blocknum = 0

    if reporthook:
        if "content-length" in headers:
            size = int(headers["Content-Length"])
        reporthook(blocknum, bs, size)

    while 1:
        block = fp.read(bs)
        if block == "":
            break
        read += len(block)
        tfp.write(block)
        blocknum += 1
        if reporthook:
            reporthook(blocknum, bs, size)

    fp.close()
    tfp.close()
    del fp
    del tfp

    # raise exception if actual size does not match content-length header
    if size >= 0 and read < size:
        raise ContentTooShortError("retrieval incomplete: got only %i out "
                                    "of %i bytes" % (read, size), result)

    return result



url = 'http://www.youtube.com/watch?v=ZA3POLOEtFQ'

headers = {
'User-Agent' : 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)',
'Accept' :
'text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5',
'Accept-Language' : 'fr-fr,en-us;q=0.7,en;q=0.3',
'Accept-Charset' : 'ISO-8859-1,utf-8;q=0.7,*;q=0.7'
}


#test it
httpDownload(url, 'testDownload.flv', headers, reportDownloadProgress)
