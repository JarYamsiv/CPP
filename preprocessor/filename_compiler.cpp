#include <iostream>

using namespace std;

int main()
{
	system("g++ filename.cpp -o filename");
	int t = system("./filename");
	cout<<"that programme returned : "<<t<<endl;
	return 0;
}
