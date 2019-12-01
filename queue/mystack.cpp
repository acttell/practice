/*
https://blog.csdn.net/acttell/article/details/80644041
*/
#include<iostream>
#include<queue>
using namespace std;
template<class T>
class mystack
{
public:
    void in(const T& x)
    {
        if(q1.size()==0 && q2.size()==0) 
        {
            q1.push(x);
        }
        if(q1.size()>0)
        {
            q1.push(x);
        } 
        if(q2.size()>0)
        {
            q2.push(x);
        }
    }
    void out()
    {
        if(q2.size()==0)
        {
            while(q1.size()!=1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            cout<<q1.front()<<",";
            q1.pop();
        } else
        {
            while(q2.size()!=1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            cout<<q2.front()<<",";
            q2.pop();
        }
        
    }
private:
    queue<T> q1;
    queue<T> q2;
};
int main()
{
    mystack<int> ms;
    ms.in(1);
    ms.in(2);
    ms.in(3);
    ms.out();
    ms.out();
    ms.in(4);
    ms.out();
    return 0;
}
