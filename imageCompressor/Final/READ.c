#include <stdio.h>
#include <stdlib.h>

#include "DFT.h"
#include "READ.h"
#include "P5toP2.c"

int contract_array(int *BIG_ARR,int *SMALL_ARR)
{
  int i,pos=0;
  for(i=63; i>=0; i--)
  {
    if(BIG_ARR[i]!=0)
    {
      pos=i;
      break;	
    }
  }
  for(i=0; i<=pos; i++)
  {
    SMALL_ARR[i]=BIG_ARR[i];
  }
  SMALL_ARR[pos+1]=9999;
  return pos+2;
}

int READ_MAT(FILE *p,FILE *write)
{
  int **BIG_MAT;
  int i,j;
  int o_width,o_height;
  int width8,height8;
  int c_max;
  char temp;
  int Q[8][8]={{16,11,10,16,24,40,51,61},
				 {12,12,14,19,26,58,60,55},
				 {14,13,16,24,40,57,69,56},
				 {14,17,22,29,51,87,80,62},
				 {18,22,37,56,98,109,103,77},
				 {24,35,55,64,81,104,113,92},
				 {49,64,78,87,103,121,120,101},
				 {72,92,95,98,112,100,103,99},

				};

  fscanf(p, "%c", &temp);
  fprintf(write, "JPG%c", temp);

  fscanf(p, "%c", &temp);
  fprintf(write, "%c\n", temp);
  if(temp=='5')
  {
    P5toP2(p);
    fclose(p);
    p=fopen("temp.pgm","r");
    fscanf(p, "P2 ");
  } 
    
  fscanf(p, "%d %d", &o_width,&o_height);
  fprintf(write, "%d %d\n", o_width,o_height);

  width8=o_width+((o_width%8 == 0)? 0: 8-o_width%8);
  height8=o_height+((o_height%8 == 0)? 0: 8-o_height%8);
  fprintf(write, "%d %d\n", width8,height8);

  fscanf(p, "%d", &c_max);
  fprintf(write, "%d\n", c_max);

  printf("new width:%d new height:%d\n",width8,height8);

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

  for(i=0; i<o_width; i++)
  {
    for(j=0; j<o_width; j++)
    {
      fscanf(p, "%d", &(BIG_MAT[i][j]));
    }
  }

  int m,n;
  int M[8][8];
  int arr[64];
  int SM_arr[64];
  int SM_arr_length;
  int arr_len_avg=0;
  int nob=(width8*height8)/64;//number of blocks

  for(i=0; i<(width8/8); i++)
  {
    for(j=0; j<height8/8; j++)
    {
      for(m=0; m<8; m++)
      {
        for(n=0; n<8; n++)
        {
          M[m][n]=BIG_MAT[i*8+m][j*8+n];
        }
      }
      DiscreteFourierTransform(M,Q,arr);
      SM_arr_length=contract_array(arr,SM_arr);
      printf("compressing pixel block (%d,%d) arrray length:%d\n",i,j,SM_arr_length);
      arr_len_avg+=SM_arr_length;
      for(m=0; m<SM_arr_length; m++)
      {
        fprintf(write,"%d ",SM_arr[m]);
      }
      fprintf(write,"\n");
    }
  }

  printf("\nAverage Array length:%d\n",arr_len_avg/nob);

  for (i=0;i<width8;i++)
  {
      free(BIG_MAT[i]);
  }

}

int COMPRESS_GRAY(FILE *p,FILE *write,int Q[][8],int o_width,int o_height,int width8,int height8)
{
  int i,j;
  int **BIG_MAT = (int**)malloc(width8 * sizeof(int*));

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

  for(i=0; i<o_width; i++)
  {
    for(j=0; j<o_width; j++)
    {
      fscanf(p, "%d", &(BIG_MAT[i][j]));
    }
  }

  int m,n;
  int M[8][8];
  int arr[64];
  int SM_arr[64];
  int SM_arr_length;
  int arr_len_avg=0;
  int nob=(width8*height8)/64;//number of blocks

  for(i=0; i<(width8/8); i++)
  {
    for(j=0; j<height8/8; j++)
    {
      for(m=0; m<8; m++)
      {
        for(n=0; n<8; n++)
        {
          M[m][n]=BIG_MAT[i*8+m][j*8+n];
        }
      }
      DiscreteFourierTransform(M,Q,arr);
      SM_arr_length=contract_array(arr,SM_arr);
      printf("compressing pixel block (%d,%d) arrray length:%d\n",i,j,SM_arr_length);
      arr_len_avg+=SM_arr_length;
      for(m=0; m<SM_arr_length; m++)
      {
        fprintf(write,"%d ",SM_arr[m]);
      }
      fprintf(write,"\n");
    }
  }

  printf("\nAverage Array length:%d\n",arr_len_avg/nob);

  for (i=0;i<width8;i++)
  {
      free(BIG_MAT[i]);
  }
}
