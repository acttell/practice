//https://blog.csdn.net/fkyyly/article/details/83930343
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
int max_former_sub_latter(vector<int> v)
{
    int i=0;
    int j=1;
    int max=0;
    while(j<v.size())
    {
        while(v[i]>v[j] && j<v.size())
        {
            if(v[i]-v[j]>max) max=v[i]-v[j];
            j++;
        }
        i=j;
        j++;
    }
    return max;
}
int main()
{
    vector<int> v1={9,1,7,18,13,-2,20,4,0,5};
    cout<<max_former_sub_latter(v1);
    cout<<endl;
    return 0;
}
