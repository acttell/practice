//https://www.cnblogs.com/grandyang/p/6493182.html
//https://www.cnblogs.com/grandyang/p/4280803.html
//https://www.cnblogs.com/grandyang/p/4281975.html
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<algorithm>
#include<functional>
#include <stdio.h>
#include <stdint.h>
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
//https://blog.csdn.net/xunalove/article/details/79174895
int stock_max_sub_2(vector<int>& v)
{
    int res=0,n=v.size();
    for(int i=0;i<n-1;i++)
    {
        if(v[i]<v[i+1]) res+=v[i+1]-v[i];
    }
    return res;
}
//https://blog.csdn.net/linhuanmars/article/details/23236995
int stock_max_sub_3(vector<int>& v)
{
    if(v.empty()) return 0;
    int n=v.size();
    int g[n][3],l[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            g[i][j]=0;l[i][j]=0;
        }
    }
    for(int i=1;i<n;i++)
    {
        int diff=v[i]-v[i-1];
        for(int j=1;j<3;j++)
        {
            l[i][j]=max(l[i-1][j]+diff,g[i-1][j-1]+max(diff,0));
            g[i][j]=max(g[i-1][j],l[i][j]);
        }
    }
    return g[n-1][2];
}
int main() 
{
    vector<int> v={7,1,5,3,6,4};
    cout<<stock_max_sub(v)<<endl;
    vector<int> v2={1,2,7,4,5,6};
    cout<<stock_max_sub_2(v2)<<endl;
    vector<int> v3={3,3,5,0,0,3,1,4};
    cout<<stock_max_sub_3(v3)<<endl;
}
