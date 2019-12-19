//https://www.cnblogs.com/grandyang/p/4383775.html
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
float power_float(float x,int n)
{
    if(n==0) return 1;
    double half=power_float(x,n/2);cout<<"fun:"<<half<<endl;
    if(n%2==0) return half*half;
    if(n>0) return half*half*x;
    cout<<half<<","<<x<<endl;
    return half*half/x;
}
int main()
{
    cout<<power_float(2.0,-2);
    return 0;
}
