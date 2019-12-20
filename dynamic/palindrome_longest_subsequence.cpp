//https://www.cnblogs.com/grandyang/p/6493182.html
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
int palindrome_longest_subsequence(string s)
{
    int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=n-1;i>=0;i--)
    {
        dp[i][i]=1;
        for(int j=i+1;j<n;j++)
        {
            if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
            else dp[i][j]=max(dp[i + 1][j],dp[i][j - 1]);
        }
    }
    return dp[0][n-1];
}
int main()
{
    string s="bbbab";
    cout<<palindrome_longest_subsequence(s);
    return 0;
}
