//https://www.cnblogs.com/grandyang/p/4028713.html
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int max_product_subarray(vector<int> v)
{
    vector<int> dp1(v.size(),0);
    vector<int> dp2(v.size(),0);
    dp1[0]=v[0];
    dp2[0]=v[0];
    int res = v[0];
    for(int i=1;i<v.size();i++)
    {
        dp1[i]=max(max(dp1[i-1]*v[i],dp2[i-1]*v[i]),v[i]);
        dp2[i]=min(min(dp1[i-1]*v[i],dp2[i-1]*v[i]),v[i]);
        res=max(res,dp1[i]);
    }
    return res;
}
int main()
{
    vector<int> v1={2,3,-2,4};
    cout<<max_product_subarray(v1)<<endl;
    vector<int> v2={-2,0,-1};
    cout<<max_product_subarray(v2)<<endl;
    return 0;
}
