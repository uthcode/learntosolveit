class U(str):
    def __format__(self, fmt):
        if fmt[0] == 'u':
            s = self.upper()
            fmt = fmt[1:]
        elif fmt[0] == 'l':
            s = self.lower()
            fmt = fmt[1:]
        else:
            s = str(self)
        return s.__format__(fmt)

name = 'Example String Ábã'
print('{0:u*^20} {0:l*^20} {0:*^20}'.format(U(name)))

#This would print:
#EXAMPLE STRING ÁBÃ example string ábã Example String Ábã
