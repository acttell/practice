/*
https://www.cnblogs.com/4everlove/p/3666016.html
*/
#include<iostream>
#include<stack>
using namespace std;
void reverse(stack<int>& s)
{
    if(s.empty()) return;
    else
    {
        int t=s.top();
        s.pop();
        if(s.empty()) 
        {
            s.push(t);
            return;
        }else
        {
            s.push(t);
        }
    }
    int a=s.top();
    s.pop();
    reverse(s);
    int b=s.top();
    s.pop();
    reverse(s);
    s.push(a);
    reverse(s);
    s.push(b);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverse(s);
    while(!s.empty())
    {
        cout<<s.top()<<",";
        s.pop();
    }
    return 0;
}
