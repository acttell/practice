//https://www.cnblogs.com/grandyang/p/4424731.html
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;

int longest_parentheses(string s)
{
    stack<char> ps;
    int res=0;
    int start=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') ps.push(i);
        else if(s[i]==')')
        {
            if(ps.empty()) start=i+1;
            else
            {
                ps.pop();
                res=ps.empty()?max(res, i - start + 1):max(res, i - ps.top());
            }
        }
    }
    return res;
}
int main()
{
    string s=")()()";
    cout<<longest_parentheses(s);
    cout<<endl;
    return 0;
}
