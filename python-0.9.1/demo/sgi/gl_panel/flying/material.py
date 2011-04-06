import light

def mkmatdict () :
       m = {}
       m['material 1'] = light.m1
       m['material 2'] = light.m2
       m['material 3'] = light.m3
       m['material 4'] = light.m4
       m['material 5'] = light.m5
       m['material 6'] = light.m6
       m['material 7'] = light.m7
       m['material 8'] = light.m8
       m['material 9'] = light.m9
       #
       return m

materdict = mkmatdict ()

def mklichtdict () :
       m = {}
       m['light 1'] = light.light1
       m['light 2'] = light.light2
       #
       return m

lichtdict = mklichtdict ()
