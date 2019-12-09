//https://www.cnblogs.com/grandyang/p/4383632.html
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int rob(vector<int>& v)
{
    vector<int> dp(v.size());
    dp[0]=v[0];
    dp[1]=max(v[0],v[1]);
    for(int i=2;i<v.size();i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+v[i]);
    }
    return dp.back();
}
int main()
{
    vector<int> v1={1,2,3,1};
    cout<<rob(v1)<<endl;
    vector<int> v2={2,7,9,3,1};
    cout<<rob(v2)<<endl;
    return 0;
}
