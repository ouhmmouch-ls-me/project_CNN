def get_kernel_matrix(kernel, conv_type, bias, weights):
    cnt = 0
    kernel.seek(0, 0)
    b = []
    w = []

    for line in kernel:
        mot = line.split(': ')
        if mot[0] == 'tensor_name':
            cnt += 1    
        if cnt == (2 * conv_type) - 1:
            # get biases
            for i in range(bias[conv_type - 1] // 6 + 1):
                line = kernel.readline()
                line = line[1:]
                mot = line.split()
                if line[-2] == ']':
                    line = line[:-2]
                    mot = line.split()
                b += [float(elm) for elm in mot] 
            # get weights
            line = kernel.readline()
            for n in range(3):
                x = []
                for m in range(3):
                    y = []
                    for l in range(weights[conv_type - 1]):
                        z = []
                        for i in range(bias[conv_type - 1] // 4):
                            line = kernel.readline()
                            line = line[5:]
                            mot = line.split()
                            index = line.find(']')
                            if index != -1:
                                line = line[:index]
                                mot = line.split()
                            z += [float(elm) for elm in mot]
                        y.append(z)
                    line = kernel.readline()
                    x.append(y)
                line = kernel.readline()
                w.append(x)
            return b, w
W = [3, 64, 32, 180]
B = [64, 32, 20, 10]
kernel=open("../../../CNN_coeff_3x3.txt",'r')
#print(get_kernel_matrix(kernel,3,B,W)[1])
kernel_1=get_kernel_matrix(kernel,1,B,W)[1]
kernel_2=get_kernel_matrix(kernel,2,B,W)[1]
kernel_3=get_kernel_matrix(kernel,3,B,W)[1]
bais_1=get_kernel_matrix(kernel,1,B,W)[0]
bais_2=get_kernel_matrix(kernel,2,B,W)[0]
bais_3=get_kernel_matrix(kernel,3,B,W)[0]
with open("../C++/KERNEL.hpp","w") as f1:
    f1.write("#ifndef __KERNEL_H__\n#define __KERNEL_H__\n\n\n")
    f1.write('double bais_1[64]={')
    for i in range(64):
        f1.writelines(str(bais_1[i]))
        if i!=63: f1.write(",") 
    f1.write("};\n\n\n")
    f1.write('double kernel_1[3][3][3][64]={')
    for i in range(3):
        f1.write("{")
        for j in range(3):
            f1.write("{")
            for k in range(3):
                f1.write("{")
                for x in range(64):
                    f1.writelines(str(kernel_1[i][j][k][x]) ) 
                    if x!=63:
                        f1.write(",")
                if(k!=2):
                    f1.write("},")
                else : f1.write("}")
            if(j!=2):
                f1.write("},")
            else : f1.write("}")
        if(i!=2):
            f1.write("},")
        else : f1.write("}")
    f1.write("};\n\n\n")
    f1.write('double bais_2[32]={')
    for i in range(32):
        f1.writelines(str(bais_2[i]))
        if i!=31: f1.write(",") 
    f1.write("};\n\n\n")
    f1.write('double kernel_2[3][3][64][32]={')
    for i in range(3):
        f1.write("{")
        for j in range(3):
            f1.write("{")
            for k in range(64):
                f1.write("{")
                for x in range(32):
                    f1.writelines(str(kernel_2[i][j][k][x]) ) 
                    if x!=31:
                        f1.write(",")
                if(k!=63):
                    f1.write("},")
                else : f1.write("}")
            if(j!=2):
                f1.write("},")
            else : f1.write("}")
        if(i!=2):
            f1.write("},")
        else : f1.write("}")
    f1.write("};\n\n\n")
    f1.write('double bais_3[20]={')
    for i in range(20):
        f1.writelines(str(bais_3[i]))
        if i!=19: f1.write(",") 
    f1.write("};\n\n\n")
    f1.write('double kernel_3[3][3][32][20]={')
    for i in range(3):
        f1.write("{")
        for j in range(3):
            f1.write("{")
            for k in range(32):
                f1.write("{")
                for x in range(20):
                    f1.writelines(str(kernel_3[i][j][k][x])) 
                    if x!=19:
                        f1.write(",")
                if(k!=31):
                    f1.write("},")
                else : f1.write("}")
            if(j!=2):
                f1.write("},")
            else : f1.write("}")
        if(i!=2):
            f1.write("},")
        else : f1.write("}")
    f1.write("};\n\n\n")
    f1.write("#endif")
    
