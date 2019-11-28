/*
https://blog.csdn.net/acttell/article/details/80754748
*/
#include<iostream>
using namespace std;
int rotate_min(int* a,int n)
{
    int left=0;
    int right=n-1;
    int mid;
    while(left<right)
    {   
        mid=left+(right-left)/2;
        if(a[mid]<a[right])
            right=mid;
        else
        {   
            left=mid+1;
        }   
    }   
    return a[left];
}

int main()
{
    int a[]={5,6,1,2,3,4};
    int n=sizeof(a)/sizeof(int);
    int x=rotate_min(a,n);
    cout<<"min:"<<x<<endl;
}
