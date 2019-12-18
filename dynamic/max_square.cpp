//https://www.cnblogs.com/grandyang/p/4550604.html
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
int max_square(vector<vector<int>>& vv) 
{
    int row=vv.size();
    int col=vv.size();
    int res=0;
    vector<vector<int>> dp(row,vector<int>(col,0));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0 || j==0) dp[i][j]=vv[i][j];
            else if(vv[i][j]==1)
            {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
            res=max(res,dp[i][j]);
        }
    }
    return res*res;
}

int main()
{
    vector<vector<int>> v1={
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };
    cout<<max_square(v1);
    cout<<endl;
    return 0;
}
