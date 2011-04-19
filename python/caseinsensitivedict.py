#!/usr/bin/python
# $Id$

"""
Case Insenstive Dictionary Lookup.  Dictionary keys are case sensitive. However
you might want some facilities to do a case-insenstive dictiionary lookup at
times.  This provides the facility for the same.
"""

class CaseInsensitiveDict(dict):
    def __init__(self, *args, **kwargs):
        self._keystore = {}
        d = dict(*args, **kwargs)
        for k in d.keys():
            self._keystore[self._get_lower(k)] = k
        return super(CaseInsensitiveDict,self).__init__(*args,**kwargs)

    def __setitem__(self, k, v):
        self._keystore[self._get_lower(k)] = k
        return super(CaseInsensitiveDict, self).__setitem__(k, v)

    def __getitem__(self, k):
        return super(CaseInsensitiveDict,
                self).__getitem__(self._keystore[self._get_lower(k)])
    @staticmethod
    def _get_lower(k):
        if isinstance(k,str):
            return k.lower()
        else:
            return k

def test():
    obj = CaseInsensitiveDict([('name','senthil')])
    print obj
    obj['Sname']='kumaran'
    obj['spam'] ='eggs'
    obj['SPAM']='ham'
    print obj.items()
    obj1 = dict(fname='FIRST')
    obj.update(obj1)
    print obj
    print obj.keys()
    print obj.items()
    print obj['NAME']
    print obj['SNAME']

if __name__ == '__main__':
    test()
