//https://www.cnblogs.com/grandyang/p/4344107.html
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int edit_distance(string& s1,string& s2)
{
    int m=s1.size();
    int n=s2.size();
    vector<vector<int>>  dp(m+1,vector<int>(n+1));
    for(int i=0;i<m+1;i++) dp[i][0]=i;
    for(int i=0;i<n+1;i++) dp[0][i]=i;
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            } else
            {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
            
        }
    }
    return dp[m][n];
}
int main()
{
    //string s1="intention";
    //string s2="execution";
    string s1="horse";
    string s2="ros";
    cout<<edit_distance(s1,s2)<<endl;
    return 0;
}
