# This is an example of simple decorator using only the concepts of closure.
import time

def retry(ExceptionToCheck, tries=4, delay=3, backoff=2, logger=None):

    def _retry(fn):

        def retrying_function(*args, **kwargs):
            mtries, mdelay = tries, delay
            while (mtries > 1):
                try:
                    return fn(*args, **kwargs)
                except ExceptionToCheck, e:
                    print "retrying %d times." % mtries
                    mtries -=1
                    mdelay *= backoff
                    time.sleep(mdelay)
            return fn(*args, **kwargs)

        return retrying_function

    return _retry


@retry(Exception)
def test_function(a, b):
    print a, b
    raise Exception


test_function(10, 10)



