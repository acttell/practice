//https://blog.csdn.net/lyl194458/article/details/100192501
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
string index = "0123456789abcdefghijklmnopqrstuvwxyz";
string func(string s1,string s2)
{
    int i=s1.size()-1,j=s2.size()-1,carry=0;
    string res;
    while(i>=0 && j>=0)
    {
        int indexi=index.find(s1[i]);
        int indexj=index.find(s2[j]);
        int sum=indexi+indexj+carry;
        if(sum>=36)
        {
            carry=1;res+=index[sum%36];
        } else
        {
            carry=0;res+=index[sum];
        }
        i--;j--;
    }
    //if s1 residual
    while(i>=0)
    {
        int sum=index.find(s1[i])+carry;
        if(sum>=36)
        {
            carry=1;res+=index[sum%36];
        } else
        {
            carry=0;res+=index[sum];
        }
        i--;
    }
    //if s2 residual
    while(j>=0)
    {
        int sum=index.find(s2[i])+carry;
        if(sum>=36)
        {
            carry=1;res+=index[sum%36];
        } else
        {
            carry=0;res+=index[sum];
        }
        j--;
    }
    if(carry!=0) res+='1';
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    string s1="1b";
    string s2="2x";
    cout<<func(s1,s2);
    return 0;
}
