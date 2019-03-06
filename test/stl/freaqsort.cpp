#include <bits/stdc++.h>

int main(int argc, char const *argv[])
{
    std::unordered_map<int,int> f;

    srand(time(0));
    int len=(rand()%25)+75;
    std::vector<int> arr;
    for(int i=0; i<len; i++)
    {
        arr.push_back(rand()%25);
        printf("%d ",arr[i]);
        if(f.find(arr[i])==f.end())
        {
            f[arr[i]]=1;
        }
        else
        {
            f[arr[i]]++;
        }
    }
    std::sort(arr.begin(),arr.end(),[&](int a,int b){    return f[a]>f[b] || (f[a]==f[b]&&a>b) ;     });

    printf("\nsorted:\n");
    for(int i=0; i<len; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
    return 0;
}
