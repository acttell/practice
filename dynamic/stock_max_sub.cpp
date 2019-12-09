//https://blog.csdn.net/acttell/article/details/80727313
#include<iostream>
#include<vector>
using namespace std;
int stock_max_sub(vector<int>& v)
{
    int max=v[1]-v[0];
    int small=min(v[1],v[0]);
    for(int i=2;i<v.size();i++)
    {
        if(v[i]<small) small=v[i];
        if(v[i]-small>max) max=v[i]-small;
    }
    return max;
}
int main() 
{
    vector<int> v={7,1,5,3,6,4};
    cout<<stock_max_sub(v);
}
