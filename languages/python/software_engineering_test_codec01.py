if __name__ == '__main__':
    # define our Unicode string
    uni = "Hello\u001A\u0BC3\u1451\U0001D10CUnicode"

    # UTF-8 and UTF-16 can fully encode *any* unicode string

    print("UTF-8", repr(uni.encode('utf-8')))
    print("UTF-16", repr(uni.encode('utf-16')))

    # ASCII can only work with code values from 0-127. Below we tell Python

    print("ASCII ", uni.encode('ascii','replace'))

    # ISO-8859-1 is similar to ASCII

    print("ISO-8859-1 ", uni.encode('iso-8859-1','replace'))

    uni = uni.encode('utf-8')
    bstr = str(uni, 'utf-8')
    print("Back from UTF-8:", repr(bstr))
