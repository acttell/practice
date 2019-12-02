/*
https://www.cnblogs.com/grandyang/p/4079165.html
*/
#include<iostream>
#include<vector>
using namespace std;
int stairs(int n)
{
    if(n<=1) return 1;
    int dp[n];
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<n;i++)
    {   
        dp[i]=dp[i-1]+dp[i-2];
    }   
    return dp[n-1];
}
int main()
{
    cout<<"steps:"<<stairs(3);
    return 0;
}
