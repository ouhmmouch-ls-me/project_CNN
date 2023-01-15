import numpy as np
from math import sqrt
def line_to_int(liste):
    for i in range(0,len(liste)):
            liste[i]=int(liste[i])
pic="../img/img_1.ppm"
fichier=open(pic,"r")
lines = [line.rstrip('\n') for line in fichier]
matrix=[]
for line in range(3,len(lines)):
    raw=[]
    ligne=[]
    pixel=[]
    raw=lines[line].split()
    line_to_int(raw)
    for i in range(0,len(raw)):
        if(i%3==0):
            pixel+=[raw[i]]
        if(i%3==1):
            pixel+=[raw[i]]  
        if(i%3==2):
            pixel+=[raw[i]]  
            ligne+=[pixel]
            pixel=[]
    matrix+=[ligne]
import numpy as np

def create_fmap(image):
    # On convertit l'image en un tableau numpy
    image = np.array(image)
    # On transpose les dimensions de l'image pour passer de (10,10,3) à (3,10,10)
    image = np.transpose(image, (2, 0, 1))
    # On crée une fmap vide de la même taille que l'image transposée
    fmap = np.zeros_like(image)
    # On parcourt chaque canal de l'image
    for c in range(image.shape[0]):
        # On extrait chaque canal de l'image
        channel = image[c,:,:]
        # On effectue un traitement sur chaque canal, par exemple une convolution avec un filtre
        # ...
        # On stocke le résultat dans la fmap correspondante
        fmap[c,:,:] = channel
    return fmap
