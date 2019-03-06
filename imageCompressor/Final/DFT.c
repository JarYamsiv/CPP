#include <stdio.h>
#include <math.h>


int min(int a, int b)
{
	return (a < b)? a: b;
}

// A utility function to find min of three integers
int min3(int a, int b, int c)
{
	return min(min(a, b), c);
}

// A utility function to find max of two integers
int max(int a, int b)
{
	return (a > b)? a: b;
}

void DiscreteFourierTransform(int M[][8],int Q[][8],int *a)
{
	int M_m128[8][8];//M- 128 matrix
	double T[8][8];//Matrix used for descrete fourier transform
	double T_star_M[8][8];
	double T_trans[8][8];
	float DFT[8][8];//after DFT
	float DFT_rounded[8][8];
	int DFT_Q[8][8];//DFT after quantisztion

	int coded_array[64];

	int i,j,k;

	//setting median to 0
	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			M_m128[i][j]=M[i][j]-128;
			T_star_M[i][j]=0;
			DFT[i][j]=0;
		}
	}
	//printf("M_m128\n");
	//print(M_m128);
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

	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			for(k=0; k<8; k++)
			{
				T_star_M[i][j]+=T[i][k]*M_m128[k][j];
			}
		}
	}

	//printf("T*M_m128\n");
	//printdb(T_star_M);

	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			for(k=0; k<8; k++)
			{
				DFT[i][j]+=T_star_M[i][k]*T_trans[k][j];
			}
		}
	}

	//printfl(DFT);

	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			DFT_rounded[i][j]=ceilf(DFT[i][j]*10)/10;
		}
	}

	//printf("DFT_rounded\n");
	//printfl(DFT_rounded);

	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			DFT_Q[i][j]=(DFT_rounded[i][j]/Q[i][j]);
		}
	}

		for(i=0; i<64; i++)
		{
			coded_array[i]=0;
		}

		int line;
		int counter=0;
		int count;
		int ROW=8;
		int COL=8;
    for (line=1; line<=(ROW + COL -1); line++)
    {
        int start_col =  max(0, line-ROW);
         int count = min3(line, (COL-start_col), ROW);
        for (int j=0; j<count; j++)
				{
						coded_array[counter]=DFT_Q[min(ROW, line)-j-1][start_col+j];
						counter++;
				}
    }

		for(i=0; i<64; i++)
		{
			//printf("%d ",coded_array[i]);
			a[i]=coded_array[i];
		}

}
