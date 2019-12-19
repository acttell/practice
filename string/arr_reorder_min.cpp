//https://blog.csdn.net/peiyao456/article/details/54605752
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<algorithm>
#include<functional>
#include <stdio.h>
#include <stdint.h>
using namespace std;
bool compare(const string& str1,const string& str2)
{
    string s1 = str1+str2;
    string s2 = str2+str1;
    return s1<s2;
}
void arr_reorder_min(int arr[],int n)
{
    string* sp = new string[n]; 
    for(int i = 0; i < n; ++i)
    {
       char buffer[10];
       //_itoa(arr[i],buffer,10);
       snprintf(buffer,10, "%d", arr[i]);
       sp[i] = buffer;
    }
    sort(sp,sp+n,compare);
    for(int i = 0; i < n; ++i)
    {
       cout<<sp[i]<<",";
    }
    cout<<endl;
}
int main()
{
    //int arr[] = {32,321,1};
    int arr[] = {3,32,321};
    arr_reorder_min(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}
