from GL import *
from gl import *

# identity matrix
idmat=[1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0]

# the different materials.
m1=[SPECULAR,0.8,0.0,0.0,DIFFUSE,0.4,0.0,0.0,SHININESS,40.0,LMNULL]
m2=[SPECULAR,1.0,0.4,0.0,DIFFUSE,1.0,0.4,0.0,SHININESS,80.0,LMNULL]
m3=[SPECULAR,0.0,0.0,0.6,DIFFUSE,0.0,0.0,0.8,SHININESS,60.0,LMNULL]
m4=[SPECULAR,0.0,1.0,0.0,DIFFUSE,0.0,0.6,0.0,SHININESS,120.0,LMNULL]
m5=[SPECULAR,1.0,1.0,0.0,DIFFUSE,0.6,0.6,0.0,SHININESS,100.0,LMNULL]
m6=[SPECULAR,1.0,0.0,1.0,DIFFUSE,0.6,0.0,0.6,SHININESS,120.0,LMNULL]
m7=[SPECULAR,0.9,0.9,0.9,DIFFUSE,0.6,0.6,0.6,SHININESS,120.0,LMNULL]
m8=[SPECULAR,0.4,0.7,0.4,DIFFUSE,0.5,1.0,0.5,SHININESS,50.0,LMNULL]
m9=[SPECULAR,0.2,0.0,0.1,DIFFUSE,0.8,0.0,0.3,SHININESS,10.0,LMNULL]

#the lightsources.
light1 = [LCOLOR,1.0,1.0,1.0,POSITION,10.0,10.0,5.0,0.0,LMNULL]
light2 = [LCOLOR,1.0,1.0,1.0,POSITION,-10.0,10.0,5.0,0.0,LMNULL]

# the lightmodel.
model = [AMBIENT,0.4,0.4,0.4,LMNULL]

def bindlight (bool) :
       # Initializes all settings for a window.
       if bool <> 0 :
               mmode(MVIEWING)
               perspective (900, 1.0, 1.0, 35.0)
               loadmatrix(idmat)
       # define materials and lights
       lmdef(DEFMATERIAL, 1, m1)
       lmdef(DEFMATERIAL, 2, m2)
       lmdef(DEFMATERIAL, 3, m3)
       lmdef(DEFMATERIAL, 4, m4)
       lmdef(DEFMATERIAL, 5, m5)
       lmdef(DEFMATERIAL, 6, m6)
       lmdef(DEFMATERIAL, 7, m7)
       lmdef(DEFMATERIAL, 8, m8)
       lmdef(DEFMATERIAL, 9, m9)
       lmdef(DEFLIGHT, 1, light1)
       lmdef(DEFLIGHT, 2, light2)
       lmdef(DEFLMODEL, 1, model)
       lmbind(LIGHT0,1)
       lmbind(LIGHT1,2)
       lmbind(LMODEL,1)
