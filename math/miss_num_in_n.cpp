/*
https://www.cnblogs.com/grandyang/p/4756677.html
*/
#include<iostream>
#include<vector>
using namespace std;
int missnum(vector<int>& v)
{
    int res=0;
    for(int i=0;i<v.size();i++)
    {
        res^=(i+1)^v[i];
    }
    return res;
}
int main()
{
    vector<int> v={0,1,3};
    cout<<missnum(v);
    return 0;
}
