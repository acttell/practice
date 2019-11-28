/*
https://blog.csdn.net/morewindows/article/details/6678165
*/
#include<iostream>
#include<stdlib.h>
#include <time.h>
using namespace std;

void merge_unit(int* a,int begin,int mid,int end,int* p)
{
    int i=begin;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=end)
    {   
        if(a[i]<=a[j]) 
        {   
            p[k++]=a[i++];
        }   
        else 
        {   
            p[k++]=a[j++];
        }   
    }   
    while(i<=mid) p[k++]=a[i++];
    while(j<=end) p[k++]=a[j++];
    for(int t=0;t<=end;t++)
        a[begin+t]=p[t];
}
void merge(int* a,int begin,int end,int* p)
{
    if(begin<end)
    {   
        int mid=begin+(end-begin)/2;
        merge(a,begin,mid,p);
        merge(a,mid+1,end,p);
        merge_unit(a,begin,mid,end,p);
    }   
}
void reduce_sort(int* a,int n)
{
    int* p=new int[n];
    merge(a,0,n-1,p);
    delete[] p;
}
int main()
{
    int a[]={1,5,2,1,4};
    int n=sizeof(a)/sizeof(int);
    reduce_sort(a,n);
    for(int i=0;i<5;i++)
        cout<<a[i]<<",";
}

