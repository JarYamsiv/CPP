#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
#include <mutex>

using namespace std;
namespace
{
	unsigned ln = 1;
	auto Line(int l) { int m=l-ln; ln=l; return "\r"+(m<0?"\33["+std::to_string(-m)+'A':std::string(m,'\n')); }
	void fn(int x)
	{
		std::mutex print_lock;
		for (int i = 0; i <=100; ++i)
		{
			std::lock_guard<std::mutex> l(print_lock);
			usleep(rand()%75000);
			cout<<Line(x)<<"thread "<<x<<" finished "<<i<<" % "<<std::flush;
		}
	}
}
int main()
{
	std::vector<std::thread>threads;
	for(int i=0; i<10; i++)
	{
		threads.emplace_back([i]{fn(i+1);});
	}
	for(auto &p: threads)p.join();
	return 0;
}
