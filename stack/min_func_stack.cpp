//https://www.cnblogs.com/wanglei5205/p/8622442.html
//https://www.cnblogs.com/jlxuexijidi-2015/p/4946223.html
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
template <class T>
class minstack
{
public:
    void push(int val)
    {
        s1.push(val);
        if(s2.empty()) s2.push(val);
        else if(val<=s2.top())
            s2.push(val);
    }
    void pop()
    {
        if(s1.empty()) return;
        if(s1.top()==s2.top()) s2.pop();
        s1.pop();
    }
    int top()
    {
        return s1.top();
    }
    int min()
    {
        return s2.top();
    }
private:
    stack<T> s1;
    stack<T> s2;
};
int main()
{
    minstack<int> ms;
    ms.push(6);
    ms.push(5);
    ms.push(3);
    cout<<ms.min();
    return 0;
}
