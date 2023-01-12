import numpy as np
import matplotlib.pyplot as plt 
import matplotlib.image as mpimg 
import os

directory = os.fsencode("../img")
for file in os.listdir(directory):
    print(file)
    pic= os.fsdecode(file)
    pic="../img/"+pic
    img = mpimg.imread(pic) #Read the image file 
    plt.imshow(img)    #Show the image
    plt.show()



