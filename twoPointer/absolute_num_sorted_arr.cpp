//https://blog.csdn.net/orangefly0214/article/details/98848215
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
int absolute_count(vector<int> v)
{
    int i=0;
    int j=v.size()-1;
    int count=0;
    while(i<j)
    {
        if(i<v.size()-1 && v[i]==v[i+1]) i++;
        if(j>1 && v[j]==v[j-1]) j--;
        if(v[i]+v[j]==0)
        {
            i++;j--;
            count++;
        } else if (v[i]+v[j]>0)
        {
            j--;count++;
        } else
        {
            i++;count++;
        } 
    }
    if(i==j) count++;
    return count;
}
int main()
{
    vector<int> v1={-3, -1, 0, 0, 2, 3, 5};
    cout<<absolute_count(v1);
    cout<<endl;
    return 0;
}
