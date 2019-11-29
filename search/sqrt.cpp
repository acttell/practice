/*
https://www.cnblogs.com/grandyang/p/6854825.html
https://www.cnblogs.com/grandyang/p/4346413.html
*/
#include<iostream>
#include<vector>
using namespace std;
int mysqrt(int x)
{
    int begin=0;
    int end=x;
    int mid;
    while(begin<end)
    {   
        mid=begin+(end-begin)/2;
        if(mid*mid==x) return mid;
        if(mid*mid<x) begin=mid+1;
        else end=mid-1;
    }   
    return end-1;
}
int mysearch(int* a,int o,int n)
{
    int begin=0;
    int end=n-1;
    int mid;
    while(begin<=end)
    {
        mid=begin+(end-begin)/2;
        if(a[mid]==o) return mid;
        if(a[mid]<o) begin=mid+1;
        if(a[mid]>o) end=mid-1;
    }
    return -1;
}
int main()
{
    int x=8;
    cout<<mysqrt(x)<<endl;
    int a[]={1,4,6};
    int n=sizeof(a)/sizeof(int);
    cout<<mysearch(a,4,n)<<endl;
    return 0;
}
