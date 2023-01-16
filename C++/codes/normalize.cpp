#include <cstring>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

void print_matrix(double matrix[3][26][26]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                cout << matrix[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

// ...

void normalize(string image_in,double img_out[3][26][26]){
    // Open pic.ppm file in read mode
    ifstream file(image_in);

    // Read in all lines from the file
    string lines[35];
    string line;
    int lines_i = 0;
    while (getline(file, line)) {
        lines[lines_i] = line;
        lines_i++;
    }
    file.close();

    // Convert lines to a matrix of doubles
    double matrix[3][32][32];
    for (int i = 3; i < lines_i; i++) {
        string token;
        string tmp[96];
        int pt = 0;
        stringstream ss(lines[i]);
        while (ss >> token) {
            tmp[pt] = token;
            pt++;
        }
        for (int j=0; j < 96; j+=3){
            matrix[0][i-3][j/3]= stof(tmp[j]);
            matrix[1][i-3][j/3]= stof(tmp[j+1]);
            matrix[2][i-3][j/3]= stof(tmp[j+2]);
            
        }
        
        
    }
    //cout << matrix[0][0][0]<< endl;
    // Write matrix to matrix.txt file
    ofstream f("matrix.txt");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 32; k++) {
                f << matrix[i][j][k] << " ";
            }
            f << endl;
        }
        f << endl;
    }
    f.close();

    // Create a new matrix with the rows 4 to 27
    
    int img_i = 1;
    int img_j = 1;
    for (int i = 4; i < 28; i++) {
        img_j = 1;
        for (int j = 4; j < 28; j++) {
            img_out[0][img_i][img_j] = matrix[0][i][j];
            img_out[1][img_i][img_j] = matrix[1][i][j];
            img_out[2][img_i][img_j] = matrix[2][i][j];
            img_j++;
        }
        img_i++;
    }
    //padding the img
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            img_out[i][0][j]=0;
            img_out[i][j][0]=0;
            img_out[i][25][j]=0;
            img_out[i][j][25]=0;
        }
        
    }
    //print_matrix(img_out);
    // Normalize the values in the img matrix
    int N = 24 * 24 * 3;
    double mu = 0;
    double sigma = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 24; j++) {
            for (int k = 0; k < 24; k++) {
                mu += img_out[i][j+1][k+1] / N;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 24; j++) {
            for (int k = 0; k < 24; k++) {
                sigma += (img_out[i][j+1][k+1] - mu) * (img_out[i][j+1][k+1] - mu);
            }
        }
    }
    sigma = sqrt(sigma / N);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 24; j++) {
            for (int k = 0; k < 24; k++) {
                img_out[i][j+1][k+1] = (img_out[i][j+1][k+1] - mu) / max(sigma, 1 / sqrt(N));
            }
        }
    }
 
    

// Write img_out to img_out.txt file
ofstream f1("img_out.txt");
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 26; j++) {
        for (int k = 0; k < 26; k++) {
            f1 << img_out[i][j][k] << " ";
            }
        f1 << endl;
    }
    f1 << endl;
}
f1.close();
}
int main(){
    double img[3][26][26];
    normalize("../../img/img_1.ppm",img);
    print_matrix(img);
}