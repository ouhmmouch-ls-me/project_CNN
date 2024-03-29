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
    print(len(matrix))
#print(matrix)
fichier.close()
f=open("matrix.txt","w")
f.write("".join(map(str, matrix)))
f.close()
img=[]
for i in range(4,28):
    img+=[matrix[i]]
#for i in range(len(img)):
 #   del img[i][0:4]
  #  del img[i][28:31]
#print(len(img[20]))>img.txt

print(np.array(matrix))
for i in range(4):
    del matrix[0]
    del matrix[-1]
for i in matrix:
    for j in range(4):
        del i[0]
        del i[-1]
def normalise(matrix):
    N=24*24*3
    mu=0
    sigma=0
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            for k in range(3):
                mu+=matrix[i][j][k]/N
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            for k in range(3):
                sigma+=(matrix[i][j][k]-mu)**2
    sigma=sqrt(sigma/N)
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            for k in range(3):
                matrix[i][j][k]=(matrix[i][j][k]-mu)/(max(sigma,1/sqrt(N)))
    return matrix
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
matrix=normalise(matrix)
matrix=create_fmap(matrix)
print(matrix)
fi=open("imag.txt","w")
fi.write("".join(map(str, np.array(matrix))))
fi.close()
