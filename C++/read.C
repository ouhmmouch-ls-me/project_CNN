#include <stdio.h>
#include <stdlib.h>
int main()
{   
    
    
    int k[10];
    printf("chose img between 1 and 10000\n");
    for(int l=0;l<10;l++){
        printf("img %d = ",l+1);
        scanf("%d",&k[l]);
    }
    for(int y=0;y<10;y++){
    FILE *f = fopen("../test_batch.bin", "rb");
    int val;
    int label;
    unsigned char r[1024], g[1024], b[1024];
    int i;
    int l_pixel[1024][3];
    
    fseek(f, 3073*k[y], SEEK_SET);

    label = fgetc(f);
    printf("%d\n", label);
    
    fread(r, sizeof(unsigned char), 1024, f);
    fread(g, sizeof(unsigned char), 1024, f);
    fread(b, sizeof(unsigned char), 1024, f);
    
    for (i=0; i<1024; i++)
    {
        l_pixel[i][0] = r[i];
        l_pixel[i][1] = g[i];
        l_pixel[i][2] = b[i];
    }
    
    fclose(f);
    char file[14];
    sprintf(file,"../img/img_%d.ppm",y+1);
    FILE *f1 = fopen(file, "w");
    fprintf(f1, "P3\n");
    fprintf(f1, "32 32\n");
    fprintf(f1, "255\n");
    int j,n=0;
    for (i=0; i<1024; i++)
    {
        for (j=0; j<3; j++)
        {
            fprintf(f1, "%d ", l_pixel[i][j]);
        }
        n+=1;
        if (n==32)
        {
            fprintf(f1, "\n");
            n=0;
        }
    }
    fclose(f1);
    
    }
    return 0;
}


