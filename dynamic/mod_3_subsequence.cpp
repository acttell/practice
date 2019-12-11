//https://blog.csdn.net/weixin_43922043/article/details/89164552
//https://blog.csdn.net/qq_43475252/article/details/90702214
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int mod=1e9+7;
int a2i(char c)
{
    return c-'0';
}
int mod_3_sequence(string s)
{
    vector<int> dp(3);
    for(int i=0;i<3;i++) dp[i]=0;
    for(int i=0;i<s.size();i++)
    {
        int x=a2i(s[i]);
        int s0=0;
        int s1=0;
        int s2=0;
        if(x%3==0)
        {
            s0+=dp[0]+1;
            s1+=dp[1];
            s2+=dp[2];
        }
        if(x%3==1)
        {
            s0+=dp[2];
            s1+=dp[0]+1;
            s2+=dp[1];
        }
        if(x%3==2)
        {
            s0+=dp[1];
            s1+=dp[2];
            s2+=dp[0]+1;
        }
        dp[0]+=s0;
        dp[1]+=s1;
        dp[2]+=s2;
        for(int i=0;i<3;i++) dp[i]%=mod;
    }
    return dp[0];
}
int main()
{
    string s="123456";
    cout<<mod_3_sequence(s);
    return 0;
}
