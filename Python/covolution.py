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
kernel=open("../../CNN_coeff_3x3.txt",'r')
print(len(get_kernel_matrix(kernel,3,B,W)[0]))
