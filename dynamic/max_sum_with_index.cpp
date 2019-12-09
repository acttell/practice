#include<iostream>
#include<vector>
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
int max_sum_with_index(vector<int>& v,int& begin,int& end)
{
    int sum=v[0];
    int max=v[0];
    int pre=0;
    for(int i=0;i<v.size();i++)
    {
        if(sum<0)
        {
            sum=v[i];
            pre=i;
        } else
        {
            sum+=v[i];
        }
        if(sum>max)
        {
            max=sum;
            begin=pre;
            end=i;
        }
    }
    return max;
}
int main()
{
    int a[]={-2,1,-3,4,-1,2,1,-5,4};
    int n=sizeof(a)/sizeof(int);
    cout<<maxsum(a,n)<<endl;
    vector<int> v={-2,1,-3,4,-1,2,1,-5,4};
    int begin=0;
    int end=0;
    cout<<max_sum_with_index(v,begin,end)<<endl;
    cout<<"begin:"<<begin<<" end"<<end<<endl;
    return 0;
}
