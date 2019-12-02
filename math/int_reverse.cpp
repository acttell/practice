/*
https://www.cnblogs.com/grandyang/p/4125588.html
*/
#include<iostream>
#include<limits.h>
using namespace std;
int reverse_int(int x)
{
    int res=0;
    while(x!=0)
    {
        if(res*10>INT_MAX) return 0;
        res=res*10+x%10;
        x/=10;
    }
    return res;
}
int main()
{
    int x=-120;
    cout<<reverse_int(x);
    return 0;
}
