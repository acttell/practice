//https://blog.csdn.net/acttell/article/details/80038274
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
vector<int> big_mul(vector<int>& v1,vector<int>& v2)
{
    int n1=v1.size();
    int n2=v2.size();
    vector<int> v3(n1+n2);
    for(int i=0;i<n1+n2;i++)
        v3[i]=0;
    reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            v3[i+j]+=v1[i]*v2[j];
        }
    }
    for(int k=0;k<n1+n2;k++)
    {
        if(v3[k]>9)
        {
            v3[k+1]+=v3[k]/10;
            v3[k]%=10;
        }
    }
    reverse(v3.begin(),v3.end());
    return v3;
}

int main()
{
    vector<int> v1={2,4,5,6,6};
    vector<int> v2={4,5,2,0,5,3};
    vector<int> v3(v1.size()+v2.size());
    v3=big_mul(v1,v2);
    for(auto iter:v3) cout<<iter<<",";
    return 0;
}
