/*
https://www.cnblogs.com/grandyang/p/4325432.html
*/
#include<iostream>
using namespace std;
int hamming(int n)
{
    int res=0;
    for(int i=0;i<32;i++)
    {
        res+=(n&1);
        n>>=1;
    }
    return res;
}
int main()
{
    int n=11;
    cout<<hamming(n);
    return 0;
}
