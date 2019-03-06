#include <stdio.h>

#include "DFT.c"
#include "IDFT.c"
#include "READ.c"
#include "DECOMPRESS.c"

int main()
{
	FILE *p,*write;
	int array[64];
	char inp_file_name[30];
	char op_file_name[30];
	int DFT_op[8][8];
	int choice_flag;
	int Q[8][8]={{16,11,10,16,24,40,51,61},
				 {12,12,14,19,26,58,60,55},
				 {14,13,16,24,40,57,69,56},
				 {14,17,22,29,51,87,80,62},
				 {18,22,37,56,98,109,103,77},
				 {24,35,55,64,81,104,113,92},
				 {49,64,78,87,103,121,120,101},
				 {72,92,95,98,112,100,103,99},

				};

	printf("choose option\n 1.compress\n 2.decompress");
	scanf("%d",&choice_flag);
	printf("enter file name: ");
	scanf("%s",inp_file_name);
	printf("enter output file name:");
	scanf("%s",op_file_name);

	p= fopen(inp_file_name, "r");
	write=fopen(op_file_name,"w");

	//p= fopen("test/opt.txt", "r");
	//write=fopen("test/base_out.pgm","w");

	if(choice_flag==1)
	{
		READ_MAT(p,write);
	}
	else
	{
		DECOMP(p,write);
	}

	fclose(p);
	fclose(write);

	printf("\n");
	return 0;
}
