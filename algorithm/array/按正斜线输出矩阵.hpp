#include <stdio.h>
#define MAX 5
void outMatrix(int** array, int rows, int cols)
{
    for(int row=0;row<rows;row++)
    {
        int scolumn=0;
        if(row>0)
            scolumn=array[row][cols]-1;
        for(int column=scolumn;column<array[row][cols];column++)
        {
            int r=row;
            int c=column;
            printf("%d\n",array[r][c]);
            while(++r<rows&&--c>=0)
            {
                printf("%d\n",array[r][c]);
            }
        }
    }
}