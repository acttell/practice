/*
https://blog.csdn.net/acttell/article/details/80635812
*/
#include<iostream>
#include<stack>
using namespace std;
template<class T>
class myqueue
{
public:
    void in(const T& x)
    {
        s1.push(x);
    }
    void out()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            cout<<s2.top()<<",";
            s2.pop();
        }else
        {
            cout<<s2.top()<<",";
            s2.pop();
        }
        
    }
private:
    stack<T> s1;
    stack<T> s2;
};
int main()
{
    myqueue<int> mq;
    mq.in(1);
    mq.in(2);
    mq.out();
    mq.out();
}
