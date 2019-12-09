//https://www.cnblogs.com/grandyang/p/4032449.html
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<vector<int>> pascal_triangle(int n)
{
    vector<vector<int>> vv(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        vv[i].resize(i+1,1);
        for(int j=1;j<i;j++)
            vv[i][j]=vv[i-1][j-1]+vv[i-1][j];
    }
    return vv;
}
int main()
{
    vector<vector<int>> vv;
    vv=pascal_triangle(5);
    for(auto iter1:vv)
    {
        for(auto iter2:iter1)
        {
            cout<<iter2<<",";
        }
        cout<<endl;
    }
    return 0;
}
