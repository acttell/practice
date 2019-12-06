//https://www.cnblogs.com/grandyang/p/5931874.html
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int longest_palindrome(string& s)
{
    unordered_map<char,int> m;
    for(autu iter:s) m[iter]++;
    int res=0;
    int flag=0;
    for(auto iter=m.begin();iter!=m.end();iter++)
    {
        if(iter->second%2==0)
        {
            res+=iter->second;
        }
        if(iter->second==1) flag=1;
        if(iter->second>1 && iter->second%2!=0)  res+=iter->second;
    }
    return flag==1?res+1:res;
}
int main()
{
    string s="abccccdd";
    cout<<s.size()<<endl;
    cout<<"longest palindrome:"<<longest_palindrome(s)<<endl;
    return 0;
}
