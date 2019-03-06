#include<stdio.h>
#include<math.h>
int IDFT(int DFT_Q1[][8],int Q[][8],int OPT_M[][8])
{
 double T[8][8];//Matrix used for descrete fourier transform
 double T_trans[8][8];
 double Ttrans_star_DFT1[8][8];
 float DFT1_rounded[8][8];
 float DFT1[8][8];
 int M1_m128[8][8];//M- 128 matrix
 int M1[8][8];//M1 matrix

  int i,j,k;
  //creating T matrix

  for(i=0; i<8; i++)
  {
    for(j=0; j<8; j++)
    {
      if(i==0)
      {
        T[i][j]=1/sqrt(8);
      }
      else
      {
        T[i][j]=0.5*cos((double)(((2*j+1)*i*3.14159265359)/16));
      }

    }
  }

  //printf("T matrix \n");
  //printdb(T);

  for(i=0; i<8; i++)
  {
    for(j=0; j<8; j++)
    {
      T_trans[i][j]=T[j][i];
    }
  }

  //printf("T_trans \n");
  //printdb(T_trans);

  //setting median to 0
  for(i=0; i<8; i++)
  {
    for(j=0; j<8; j++)
    {
      M1_m128[i][j]=0;
      Ttrans_star_DFT1[i][j]=0;
      M1[i][j]=0;
    }
  }


//Creating DFT1_rounded Matrix
  for(i=0; i<8; i++)
  {
    for(j=0; j<8; j++)
    {
      DFT1[i][j]=(DFT_Q1[i][j]*Q[i][j]);
    }
  }








//Ttrans * DFT1 matrix
for(i=0; i<8; i++)
{
  for(j=0; j<8; j++)
  {
    for(k=0; k<8; k++)
    {
      Ttrans_star_DFT1[i][j]+=T_trans[i][k]*DFT1[k][j];
    }
  }
}

//M1_m128 matrix creation
for(i=0; i<8; i++)
{
  for(j=0; j<8; j++)
  {
    for(k=0; k<8; k++)
    {
    M1_m128[i][j]  +=Ttrans_star_DFT1[i][k]*T[k][j];
    }
  }
}
//M1 creation
//setting median to 0
for(i=0; i<8; i++)
{
  for(j=0; j<8; j++)
  {
    M1[i][j]=M1_m128[i][j]+128;
    //T_star_M[i][j]=0;
    //DFT[i][j]=0;
  }
}

for(i=0; i<8; i++)
{
  for(j=0; j<8; j++)
  {
    //printf("%3d ",M1[i][j]);
    OPT_M[i][j]=M1[i][j];
  }
  //printf("\n");
}

}
