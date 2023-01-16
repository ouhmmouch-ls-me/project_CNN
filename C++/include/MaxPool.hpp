#ifndef __MAXPOOL_H__
#define __MAXPOOL_H__

/// @brief 
/// @param tab_in 
/// @param tab_out 
void maxpool_1( double tab_in[64][24][24], double tab_out[64][14][14]);

/// @brief 
/// @param tab_in 
/// @param tab_out 
void maxpool_2( double tab_in[32][12][12],double tab_out[32][8][8]);

/// @brief 
/// @param tab_in 
/// @param tab_out 
void maxpool_3( double tab_in[20][6][6], double tab_out[20][3][3]);

#endif