import numpy as np
import matplotlib.pyplot as plt 
import matplotlib.image as mpimg 

f ="../test_batch.bin"
def read_img(file,k):
    file_=open(file, 'rb')
    val=int.from_bytes (file_.read(3073*k), byteorder='big')
    label=int.from_bytes (file_.read(1), byteorder='big') # Correspond au label de l'ima
    R=np.frombuffer(file_.read(1024), dtype=np. uint8)
    G=np.frombuffer(file_.read(1024), dtype=np. uint8)
    B=np.frombuffer(file_.read(1024), dtype=np. uint8)
    l_pixel=[]
    for i in range(1024) :
        l_pixel.append( [R[i], G[i], B[i]])
    return l_pixel
print(len(read_img(f,100)))

def write_image_ppm(image_data, output_file):
    with open(output_file, 'w') as f:
        f.write('P3\n')
        f.write('32 32\n')
        f.write('255\n')
        n=0
        for pixel in image_data:
            for color in pixel:
                    f.write(str(color) + ' ')
            n+=1
            if n==32 :
                f.write('\n')
                n=0
    f.close()
pic="pic.ppm"
write_image_ppm(read_img(f,1000),pic)

#Read the image file 
img = mpimg.imread(pic)

#Show the image
plt.imshow(img)
plt.show()
from PIL import Image
with Image.open(pic) as im:
     im.save("your_jpg_file.jpg")


