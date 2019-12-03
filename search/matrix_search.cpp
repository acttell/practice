/*
https://www.cnblogs.com/grandyang/p/4323301.html
*/
#include<iostream>
#include<vector>
using namespace std;
bool search(vector<vector<int>>& vv,int t)
{
    if(vv.empty()||vv[0].empty()) return false;
    int row=vv.size();
    int col=vv[0].size();
    int start=0;
    int end=row*col-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(vv[mid/col][mid%col]==t) return true;
        if(vv[mid/col][mid%col]<t) start=mid+1;
        else end=mid-1;
    }
    return false;
}

int main()
{
    vector<vector<int>> vv={
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int t=16;
    cout<<search(vv,t)<<endl;
    return 0;
}
