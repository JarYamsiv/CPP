/*
 * This is an example of a very simple class
 * This contains both public and private fucntions
 * Also shows the creation and deletion of varialbles inside class constructors
 * remove the content from Class destructor and use valgrind to see memory leak in action
 * */

#include <iostream>

class Parent{
    public:
        Parent(int,int,int);
        int *id;
        void Create();
        int  Obtain();
        ~Parent();
    private:
        int a,b,c;
        int sum;
        int helper();
};

Parent::Parent(int x,int y,int z){
    a=x;b=y;c=z;
    id = new int;
}

Parent::~Parent(){
    delete id;
}

int Parent::helper()
{
    return a+b+c;
}

void Parent::Create(){
    *id = helper();
}

int Parent::Obtain(){
    return *id;
}

int main(){
    Parent p(1,2,3);
    p.Create();
    std::cout<<p.Obtain()<<std::endl;
    return 0;
}


