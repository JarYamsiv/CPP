#include <iostream>
#include <vector>

using namespace std;
int main()
{
  vector<int> v;
  vector<int>::iterator it;
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.pop_back();
  v.push_back(6);
  //v.pop_back();
  it = v.begin();
  it = v.insert(it,7);
  v.insert(it,8);
  cout<<" "<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
  cout<<"number of elemnts :"<<v.size();
}
