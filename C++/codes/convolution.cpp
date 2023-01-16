#include <cstring>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include"../include/KERNEL.hpp"
#include"normalize.cpp"
#include"../include/MaxPool.hpp"
#include"../include/reshape.hpp"
using namespace std;

void convo1(
  double    image_in[3][26][26],
  double    kernel_1[3][3][3][64],
  double    bais_1[64],
  double    image_out[64][24][24]
){
  double res;
  for (int c = 0; c < 64; c++){
    for (int i = 0; i < 24; i++){
      for (int j = 0; j < 24; j++){
        res = bais_1[c];
        for (int l = 0; l < 3; l++){
          for (int m = 0; m < 3; m++){
            for (int n = 0; n < 3; n++){
              res += image_in[l][i+m][j+n] * kernel_1[m][n][l][c];
            }
          }
        }
        if (res < 0) res = 0;
        image_out[c][i][j] = res;
        
      }
    }
  }
}
void convo2(
  double    image_in[64][14][14],
  double    kernel_2[3][3][64][32],
  double    bais_2[32],
  double    image_out[32][12][12]
){
  double res;
  for (int c = 0; c < 32; c++){
    for (int i = 0; i < 14; i++){
      for (int j = 0; j < 14; j++){
        res = bais_2[c];
        for (int l = 0; l < 64; l++){
          for (int m = 0; m < 3; m++){
            for (int n = 0; n < 3; n++){
              res += image_in[l][i+m][j+n] * kernel_2[m][n][l][c];
            }
          }
        }
        if (res < 0) res = 0;
        image_out[c][i][j] = res;
      }
    }
  }
}
void convo3(
  double    image_in[32][8][8],
  double    kernel_3[3][3][32][20],
  double    bais_3[20],
  double    image_out[20][6][6]
){
  double res;
  for (int c = 0; c < 20; c++){
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
        res = bais_3[c];
        for (int l = 0; l < 32; l++){
          for (int m = 0; m < 3; m++){
            for (int n = 0; n < 3; n++){
              res += image_in[l][i+m][j+n] * kernel_3[m][n][l][c];
            }
          }
        }
        if (res < 0) res = 0;
        image_out[c][i][j] = res;
      }
    }
  }
}
void print_matrix1(double matrix[64][24][24]) {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 24; j++) {
            for (int k = 0; k < 24; k++) {
                cout << matrix[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
int main(){
    
    double img_0[3][26][26];
    double img_10[64][24][24];
    double img_1[64][14][14];
    double img_20[32][12][12];
    double img_2[32][8][8];
    double img_30[20][6][6];
    double img_3[20][3][3];
    double out[180];
    normalize("../../img/img_3.ppm",img_0);
    convo1(img_0,kernel_1,bais_1,img_10);
    maxpool_1(img_10,img_1);
    convo2(img_1,kernel_2,bais_2,img_20);
    maxpool_2(img_20,img_2);
    convo3(img_2,kernel_3,bais_3,img_30);
    maxpool_3(img_30,img_3);
    reshape(img_3,out);
    for (int i = 0; i < 180; i++)
    {
      cout<<out[i]<<endl;
    }
    
    return 0;
}