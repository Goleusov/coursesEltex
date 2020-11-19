#include <stdio.h>       
#include <string.h>       

#define N 5
int main(void)                 
{
    printf("1 задание\n");
    int arr1[N][N];
    int inkrement1=0;
    for(int i=0; i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            arr1[i][j]=inkrement1++;
            printf(" %d",arr1[i][j]);
        }
        printf("\n");
    }

    printf("2 задание\n");

    int arr2[N][N];
    int inkrement2=0;
    for(int i=0; i<N;i++)
        for(int j=0;j<N;j++)
        {
            arr2[i][j]=inkrement2++;
        }

     for(int i=N-1; i>=0;i--)
    {
        for(int j=N-1;j>=0;j--)
        {
            printf(" %d",arr2[i][j]);
        }
    }
    printf("\n");

    printf("3 задание\n");

    int arr3[N][N];
    for(int i=0; i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i+j>=N-1)
            arr3[i][j]=1;
            else
            arr3[i][j]=0;
            printf(" %d",arr3[i][j]);
        }
    printf("\n");
    }

    printf("4 задание\n");
    int arr4[N][N];
    int inkrement4=1;

   
    int numstr1=0,numstr2=1,numstr3=N-1,numstr4=N-1;
    int numcol1=0,numcol2=N-1,numcol3=N-2,numcol4=0;

    for(int i=0; i<N*2;i++)
    {
        if(i%4==0)
        {
            for(int j=numcol1;j<N-numcol1;j++)
            {
                arr4[numstr1][j]=inkrement4++;
            }
            numstr1++;
            numcol1++;
        }
        if(i%4==1)
        {
            for(int j=numstr2;j<N-numstr2+1;j++)
            {
                arr4[j][numcol2]=inkrement4++;
            }
            numcol2--;
            numstr2++;
        }
        if(i%4==2)
        {
            for(int j=numcol3;j>N-(numcol3+2);j--)
            {
                arr4[numstr3][j]=inkrement4++;
            }
            numstr3--;
            numcol3--;
        }
        if(i%4==3)
        {
            for(int j=numstr4;j>=N-(numstr4);j--)
            {
                arr4[j][numcol4]=inkrement4++;
            }
            numstr4--;
            numcol4++;
        }
    }

    for(int i=0; i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf(" %d",arr4[i][j]);
        }
        printf("\n");
    }
}     