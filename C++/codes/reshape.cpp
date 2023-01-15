#include <iostream>

#include "../include/reshape.hpp" 

using namespace std;


void reshape(double in_resh [20][3][3], double out_resh[180])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; i < 3; j++)
        {
            for(int k = 0; k < 20; k++)
            {
                out_resh[k + i*3*20 + j*20]= in_resh[k][i][j];
            }
        }
    }
}