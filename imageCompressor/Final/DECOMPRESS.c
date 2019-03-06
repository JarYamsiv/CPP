#include <stdio.h>
#include <stdlib.h>

#include "DFT.h"
#include "IDFT.h"

int expand_array(int MAT_DFTQ[][8],int *SMALL_ARR)
{
  int i,j;
  int BIG_ARR[63];
  int pos,flag=0;
  for(i=0; i<63; i++)
  {
    //printf("%d ",SMALL_ARR[i]);
    if(SMALL_ARR[i]==9999)
    {
      pos=i;
      break;
    }
  }
  //printf("\n");
  for(i=0; i<64; i++)
  {
    if(SMALL_ARR[i]==9999)
    {
      BIG_ARR[i]=0;
      flag=1;
    }
    if(flag==0)
    {
      BIG_ARR[i]=SMALL_ARR[i];
    }
    else
    {
      BIG_ARR[i]=0;
    }
  }
  //BIG ARRAY formed...........
  for(i=0; i<64; i++)
  {
    //printf("%d ",BIG_ARR[i]);
  }
  //printf("\n");

  for(i=0; i<8; i++)
  {
    for(j=0; j<8; j++)
    {
      MAT_DFTQ[i][j]=99;
    }
  }

  int sum=0,sum_v=1;

  i=0;
  for(sum=0; sum<=7; sum++)
  {
    for(j=0; j<=sum; j++)
    {
      //printf("%d ",BIG_ARR[i]);
      MAT_DFTQ[sum-j][j]=BIG_ARR[i];
      i++;
    }
    //printf("\n");

  }
  for(sum=6; sum>=0; sum--)
  {
    for(j=0; j<=sum; j++)
    {
      //printf("%d ",BIG_ARR[i]);
      MAT_DFTQ[14-sum-(7-j)][7-j]=BIG_ARR[i];
      i++;
    }
    //printf("\n");

  }
  //printf("\n");

}

int DECOMP(FILE *p,FILE *write)
{
  int **BIG_MAT;
  int i,j;
  int o_width,o_height;
  int width8,height8;
  int c_max;
  char temp[7];
  int Q[8][8]={{16,11,10,16,24,40,51,61},
				 {12,12,14,19,26,58,60,55},
				 {14,13,16,24,40,57,69,56},
				 {14,17,22,29,51,87,80,62},
				 {18,22,37,56,98,109,103,77},
				 {24,35,55,64,81,104,113,92},
				 {49,64,78,87,103,121,120,101},
				 {72,92,95,98,112,100,103,99},

				};

  fscanf(p, "%s", temp);
  fprintf(write, "P2\n");


  fscanf(p, "%d %d", &o_width,&o_height);
  fscanf(p, "%d %d", &width8,&height8);
  fprintf(write, "%d %d\n", o_width,o_height);

  fscanf(p, "%d", &c_max);
  fprintf(write, "%d\n", c_max);


  //printf("new width:%d new height:%d\n",width8,height8);

  BIG_MAT = (int**)malloc(width8 * sizeof(int*));

  for (i=0;i<width8;i++)
  {
      BIG_MAT[i] = (int*)malloc(height8 * sizeof(int));
  }

  for(i=0; i<width8; i++)
  {
    for(j=0; j<8; j++)
    {
      BIG_MAT[i][j]=0;
    }
  }


  int m,n;
  int M[8][8];
  int FNL_M[i][j];
  int SM_arr[64];
  int temp_value;

  for(i=0; i<(width8/8); i++)
  {
    for(j=0; j<height8/8; j++)
    {
      m=0;
      do
      {
          fscanf(p,"%d",&temp_value);
          //printf("temp_value: %d\n",temp_value);
          SM_arr[m]=temp_value;
          m++;
      } while(temp_value!=9999);
      printf("decompressing pixel block (%d,%d)\n",i,j);
      expand_array(M,SM_arr);

      IDFT(M,Q,FNL_M);

      for(m=0; m<8; m++)
      {
        for(n=0; n<8; n++)
        {
          if(FNL_M[m][n]<0)
          {
            FNL_M[m][n]=0;
          }
          if(FNL_M[m][n]>255)
          {
            FNL_M[m][n]=255;
          }
          BIG_MAT[i*8+m][j*8+n]=FNL_M[m][n];
        }
      }
    }
  }

  for(i=0; i<o_width; i++)
  {
    for(j=0; j<o_height; j++)
    {
      fprintf(write,"%d ",BIG_MAT[i][j]);
    }
    fprintf(write,"\n");
  }


  for (i=0;i<o_width;i++)
  {
      free(BIG_MAT[i]);
  }

}
