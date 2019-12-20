//https://www.cnblogs.com/grandyang/p/7801533.html
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
int longest_same_sub_array_of_two(vector<int>& v1,vector<int>& v2)
{
    int res=0;
    int m=v1.size();
    int n=v2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            dp[i][j]=(v1[i-1]==v2[j-1])?dp[i-1][j-1]+1:0;
            res=max(res,dp[i][j]);
        }
    }
    return res;
}
int main() 
{
    vector<int> v1={1,2,3,2,1};
    vector<int> v2={3,2,1,4,7};
    cout<<longest_same_sub_array_of_two(v1,v2);
}
