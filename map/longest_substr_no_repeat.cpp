//https://www.cnblogs.com/grandyang/p/4480780.html
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int longest_substring_without_repeat(string s) {
    int res=0;
    int n=s.size();
    int left=-1;
    unordered_map<char,int> m;
    for(int i=0;i<n;i++)
    {   
        if(m.count(s[i])&&m[s[i]]>left) left=m[s[i]];
        m[s[i]]=i;
        res=max(res,i-left);
    }
    return res;
}
int main()
{
    string s1="abcabcbb";
    cout<<longest_substring_without_repeat(s1)<<endl;
    string s2="bbbbb";
    cout<<longest_substring_without_repeat(s2)<<endl;
    string s3="pwwkew";
    cout<<longest_substring_without_repeat(s3)<<endl;  
    return 0;
}
