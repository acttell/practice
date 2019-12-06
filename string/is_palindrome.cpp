//https://www.cnblogs.com/grandyang/p/4030114.html
#include<iostream>
#include<string>
using namespace std;
bool valid(char c)
{
    if(c<='z' && c>='a') return  true;
    if(c<='Z' && c>='A') return  true;
    if(c<='9' && c>='0') return  true;
    return false;
}
char convert(char c)
{
    if(c<='Z' && c>='A')  c=c-'A'+'a';
    return c;
    
}
bool is_palindrome(string& s)
{
    int left=0;
    int right=s.size();
    while(left<right)
    {
        while(!valid(s[left])) left++;
        while(!valid(s[right])) right--;
        if(convert(s[left])!=convert(s[right])) return false;
        left++;
        right--;
    }
    return true;
}
int main()
{
    string s="A man, a plan, a canal: Panama";
    cout<<s.size()<<endl;
    cout<<"palindrome:"<<is_palindrome(s)<<endl;
    return 0;
}
