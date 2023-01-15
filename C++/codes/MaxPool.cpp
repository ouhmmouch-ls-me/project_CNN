#include <iostream>
#include <algorithm>
#include <fstream>
#include <string.h>

#include "../include/MaxPool.hpp"

using namespace std;

void maxpool_1( double tab_in[64][24][24], double tab_out[64][14][14] ){
    double tmp; 
    for (int i = 0; i<64; i++){
        int line = 1;
        for(int F=0; F < 14 ; F++){
            tab_out[i][0][F]=0.0;
        } 
        for(int j=0; j<24; j+=2){
            int colomn=1;
            tab_out[i][line][0]=0.0;
             tab_out[i][line][13]=0.0;
            for(int k=0; k<24; k+=2){
                tmp=0;
                if(k<22 && j<22){
                    tmp= max(max(max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j][k+2],tab_in[i][j+1][k])),max(max(tab_in[i][j+1][k+1],tab_in[i][j+1][k+2]),max(tab_in[i][j+2][k],tab_in[i][j+2][k+1]))),tab_in[i][j+2][k+2]);
                    tab_out[i][line][colomn]=tmp;
                }
                else if (k==22){
                    tmp=max(max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j+1][k],tab_in[i][j+1][k+1])),max(tab_in[i][j+2][k],tab_in[i][j+2][k+1]));
                    tab_out[i][line][colomn]=tmp;
                }
                else if (j==22){
                    tmp=max(max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j][k+2],tab_in[i][j+1][k])),max(tab_in[i][j+1][k+1],tab_in[i][j+1][k+2]));
                    tab_out[i][line][colomn]=tmp;
                }
                else if (k==22 && j==22){
                    tmp=max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j+1][k],tab_in[i][j+1][k+1]));
                    tab_out[i][line][colomn]=tmp;
                }
                colomn+=1;
            }
            line+=1;
        } 
        for(int L=0; L<14; L++){
            tab_out[i][13][L]=0.0;
        }  
    }
}

void maxpool_2( double tab_in[32][12][12],double tab_out[32][8][8] ){
    double tmp; 
    for (int i = 0; i<32; i++){
        int line = 1;
        for(int F=0; F < 8 ; F++){
            tab_out[i][0][F]=0.0;
        } 
        for(int j=0; j<12; j+=2){
            int colomn=1;
            tab_out[i][line][0]=0.0;
            tab_out[i][line][7]=0.0;
            for(int k=0; k<12; k+=2){
                tmp=0;
                if(k<12 && j<12){
                    tmp= max(max(max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j][k+2],tab_in[i][j+1][k])),max(max(tab_in[i][j+1][k+1],tab_in[i][j+1][k+2]),max(tab_in[i][j+2][k],tab_in[i][j+2][k+1]))),tab_in[i][j+2][k+2]);
                    tab_out[i][line][colomn]=tmp;
                }
                else if (k==10){
                    tmp=max(max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j+1][k],tab_in[i][j+1][k+1])),max(tab_in[i][j+2][k],tab_in[i][j+2][k+1]));
                    tab_out[i][line][colomn]=tmp;
                }
                else if (j==10){
                    tmp=max(max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j][k+2],tab_in[i][j+1][k])),max(tab_in[i][j+1][k+1],tab_in[i][j+1][k+2]));
                    tab_out[i][line][colomn]=tmp;
                }
                else if (k==10 && j==10){
                    tmp=max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j+1][k],tab_in[i][j+1][k+1]));
                    tab_out[i][line][colomn]=tmp;
                }
                colomn+=1;
            }
            line+=1;
        } 
        for(int L=0; L<8; L++){
            tab_out[i][7][L]=0.0;
        }  
    }
}

void maxpool_3( double tab_in[20][6][6], double tab_out[20][3][3] ){
    double tmp; 
    for (int i = 0; i<20; i++){
        int line = 1;
        for(int j=0; j<6; j+=2){
            int colomn=1;
            for(int k=0; k<6; k+=2){
                tmp=0;
                if(k<6 && j<6){
                    tmp= max(max(max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j][k+2],tab_in[i][j+1][k])),max(max(tab_in[i][j+1][k+1],tab_in[i][j+1][k+2]),max(tab_in[i][j+2][k],tab_in[i][j+2][k+1]))),tab_in[i][j+2][k+2]);
                    tab_out[i][line][colomn]=tmp;
                }
                else if (k==4){
                    tmp=max(max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j+1][k],tab_in[i][j+1][k+1])),max(tab_in[i][j+2][k],tab_in[i][j+2][k+1]));
                    tab_out[i][line][colomn]=tmp;
                }
                else if (j==4){
                    tmp=max(max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j][k+2],tab_in[i][j+1][k])),max(tab_in[i][j+1][k+1],tab_in[i][j+1][k+2]));
                    tab_out[i][line][colomn]=tmp;
                }
                else if (k==4 && j==4){
                    tmp=max(max(tab_in[i][j][k],tab_in[i][j][k+1]),max(tab_in[i][j+1][k],tab_in[i][j+1][k+1]));
                    tab_out[i][line][colomn]=tmp;
                }
                colomn+=1;
            }
            line+=1;
        } 
    }
}

/*
int main(){
    int bias_ = 32;
    int img_e = 12;
    int img_s = 8;
    int c = 0;
    string s;
    double TAB_e[32][12][12];
    double TAB_s[32][8][8];
    for (int i = 0; i<bias_; i++){
        for (int j = 0; j<img_e; j++){
            for (int k = 0; k<img_e; k++){
                TAB_e[i][j][k]=c;
                c++;
            }
        }
    }
    maxpool_2(TAB_e,TAB_s);
    
    ofstream f ("test.txt");
    f << "------------------------------------------------------tableau_entré-------------------------------------" << endl;
    for (int i = 0; i<bias_; i++){
        f<<" "<<endl;
        f<<" "<<endl;
        f<<" "<<endl;
        for (int j = 0; j<img_e; j++){
            for (int k = 0; k<img_e; k++){
                s=to_string(TAB_e[i][j][k]);
                f <<s<< "      ";
            }
            f<<" "<<endl;
        }
    }

    f<<" "<<endl;
    f<<" "<<endl;
    f<<" "<<endl;
    f << "------------------------------------------------------tableau_sortie-------------------------------------" << endl;
    for (int i = 0; i<bias_; i++){
        f<<" "<<endl;
        f<<" "<<endl;
        f<<" "<<endl;
        for (int j = 0; j<img_s; j++){
            for (int k = 0; k<img_s; k++){
                s=to_string(TAB_s[i][j][k]);
                f <<s<< "      ";
            }
            f<<" "<<endl;
        }
    }
    f.close();
    return 1;
    
}*/