/*
https://blog.csdn.net/acttell/article/details/80793181
*/
#include<iostream>
using namespace std;
int maxsum(int* p,int n)
{
    int res=p[0];
    int dp[n];
    dp[0]=p[0];
    for(int i=1;i<n;i++) 
    {
        dp[i]=max(p[i],dp[i-1]+p[i]);
        res=max(dp[i],res);
    }
    return res;
}
int main()
{
    int a[]={-2,1,-3,4,-1,2,1,-5,4};
    int n=sizeof(a)/sizeof(int);
    cout<<maxsum(a,n)<<endl;
    return 0;
}
