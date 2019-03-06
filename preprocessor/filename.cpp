#include <iostream>
using namespace std;

#define glue(a,b) a ## b


int main(void)
{
	cout<<"the file name is :"<<__FILE__<<endl;

	cout<<"the compilation began at :"<<__DATE__<<" "<<__TIME__<<endl;

	glue(co,ut)<<"this cout is in line "<<__LINE__<<endl;

	return 13;
}