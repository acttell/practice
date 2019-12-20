//https://www.cnblogs.com/grandyang/p/7404777.html
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<algorithm>
#include<functional>
#include <stdio.h>
#include <stdint.h>
using namespace std;
void help(string s,int i,int j,int& res)
{
    while(i>=0 && j<s.size() && s[i]==s[j])
    {
        i--;j++;res++;
    }
}
int palindrome_num_substring(string s)
{
    if(s.empty()) return 0;
    int res=0,n=s.size();
    for(int i=0;i<n;i++)
    {
        help(s,i,i,res);
        help(s,i,i+1,res);
    }
    return res;
}
int main()
{
    string s="aaa";
    cout<<palindrome_num_substring(s);
    return 0;
}
