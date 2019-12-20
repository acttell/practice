//https://www.cnblogs.com/grandyang/p/5933787.html
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<limits.h>
#include<unordered_map>
#include<algorithm>
#include<functional>
#include <stdio.h>
#include <stdint.h>
using namespace std;
int split_arr_max(vector<int>& v,int m)
{
    int n=v.size();
    vector<int> sums(n+1,0);
    vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
    dp[0][0]=0;
    for(int i=1;i<=n;i++) sums[i]=sums[i-1]+v[i-1];
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            for(int k=i-1;k<j;k++)
            {
                int val=max(dp[i-1][k],sums[j]-sums[k]);
                dp[i][j]=min(dp[i][j],val);
            }
        }
    }
    return dp[m][n];
}
int main() 
{
    vector<int> v={7,2,5,10,8};
    cout<<split_arr_max(v,2);
}
