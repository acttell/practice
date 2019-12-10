//https://blog.csdn.net/acttell/article/details/80810401
//https://www.cnblogs.com/grandyang/p/4938187.html
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int longest_sub_sequence(vector<int> v)
{
    vector<int> dp(v.size(),1);
    int res=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[j]<v[i]) dp[i]=max(dp[i],dp[j]+1);
        }
        res=max(res,dp[i]);
    }
    return res;
}
int main()
{
    vector<int> v1={10,9,2,5,3,7,18};
    cout<<longest_sub_sequence(v1)<<endl;
    vector<int> v2={5,2,3,8,6,7};
    cout<<longest_sub_sequence(v2)<<endl;
    return 0;
}
