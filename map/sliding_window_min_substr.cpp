//https://www.cnblogs.com/grandyang/p/4340948.html
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<limits.h>
#include<unordered_map>
#include<algorithm>
#include<functional>
#include <stdio.h>
#include <stdint.h>
using namespace std;
string sliding_window_min_substr(string s,string t)
{
    string res="";
    unordered_map<char,int> lettercnt;
    int left=0,cnt=0,minlen=INT_MAX;
    for(auto c:t) lettercnt[c]++;
    for(int i=0;i<s.size();i++)
    {
        if(--lettercnt[s[i]]>=0) cnt++;
        while(cnt == t.size())
        {
            if(minlen>i-left+1)
            {
                minlen=i-left+1;
                res=s.substr(left,minlen);
            }
            if(++lettercnt[s[left]]>0) cnt--;
            left++;
        }
    }
    return res;
}
int main() 
{
    string s="ADOBECODEBANC";
    string t="ABC";
    cout<<sliding_window_min_substr(s,t);
}
