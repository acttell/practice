//https://www.cnblogs.com/liuliu5151/p/10477669.html
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int unique_path(int row,int col)
{
    vector<vector<int>> dp(row,vector<int>(col));
    for(int i=0;i<col;i++) dp[0][i]=1;
    for(int i=0;i<row;i++) dp[i][0]=1;
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[row-1][col-1];
}
int main()
{
    
    cout<<unique_path(2,3)<<endl;
    cout<<unique_path(3,7)<<endl;
    return 0;
}
