//https://www.cnblogs.com/grandyang/p/4424587.html
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;

bool valid_parentheses(string s)
{
    stack<char> ps;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') ps.push(s[i]);
        else
        {
            if(ps.empty()) return false;
            if(s[i]==')' && ps.top()!='(') return false;
            if(s[i]=='[' && ps.top()!=']') return false;
            if(s[i]=='{' && ps.top()!='}') return false;
            ps.pop();
        }
    }
    return ps.empty();
}
int main()
{
    string s="{[]}";
    cout<<valid_parentheses(s);
    cout<<endl;
    return 0;
}
