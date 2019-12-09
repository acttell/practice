//https://www.cnblogs.com/grandyang/p/4389572.html
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void rotate_90(vector<vector<int>>& vv) {
    int n=vv.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(vv[i][j],vv[j][i]);
        }
        reverse(vv[i].begin(),vv[i].end());
    }
}
int main() 
{
    vector<vector<int>> vv={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotate_90(vv);
    for(auto iter1:vv)
    {
        for(auto iter2:iter1)
        {
            cout<<iter2<<",";
        }
        cout<<endl;
    }
}
