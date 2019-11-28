/*
https://blog.csdn.net/acttell/article/details/80754748
*/
#include<iostream>
using namespace std;
int rotate_find(int* a,int n,int f)
{
    int left=0;
    int right=n-1;
    int mid;
    while(left<=right)
    {   
        mid=left+(right-left)/2;
        if(a[mid]==f) return mid;
        if(a[mid]>a[left])
        {
            if(f<a[mid] && f>=a[left])
            {
                right=mid-1;
            }else
            {
                left=mid+1;
            }
        }
        else
        {   
            if(f>a[mid] && f<=a[right])
            {
                left=mid+1;
            }else
            {
                right=mid-1;
            }
        }   
    }   
    return -1;
}

int main()
{
    int a[]={5,6,1,2,3,4};
    int n=sizeof(a)/sizeof(int);
    int x=rotate_find(a,n,1);
    cout<<"index:"<<x<<endl;
}

