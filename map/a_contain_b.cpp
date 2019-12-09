//https://zhuanlan.zhihu.com/p/61331821
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;
bool contain(string& s1,string& s2) 
{
    unordered_map<char,int> m;
    for(int i=0;i<s1.size();i++)
    {   
        m[s1[i]]++;
    }   
    int flag=0;
    for(int i=0;i<s2.size();i++)
    {   
        if(m.count(s2[i]) && m[s2[i]]>0) flag++;
    }   
    cout<<flag<<endl;
    if(flag==s2.size()) return true;
    return false;
}
int main()
{
    string s1="hiok";
    string s2="hk";
    cout<<contain(s1,s2)<<endl;
    return 0;
}
