//https://www.cnblogs.com/grandyang/p/10634116.html
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
int score_parentheses(string s)
{
    int res=0;
    stack<int> st;
    for(auto c:s)
    {
        if(c=='(')
        {
            st.push(res);
            res=0;
        } else
        {
            res=st.top()+max(res*2,1);
            st.pop();
        }
    }
    return res;
}
int main() 
{
    //string s="(()(()))";
    string s="(())";
    cout<<score_parentheses(s);
}
