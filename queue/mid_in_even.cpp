//https://blog.csdn.net/oneday_789/article/details/76681764
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
struct cmp
{
    bool operator()(int a,int b) return a>b;
};
int mid_one_arr(vector<int>& v)
{
    int n=v.size()-1;
    int mid=0+(n-0)/2;
    priority_queue<int,vector<int>,cmp> q;
    for(int i=0;i<=mid;i++)
        q.push(v[i]);
    for(int j=mid+1;j<=n;j++)
    {
        if(v[j]>q.top())
        {
            q.pop();
            q.push(v[i]);
        }
    }
    return q.top();
}
int main()
{
    vector<int> v={1,7,2,3,5};
    cout<<mid_one_arr()<<endl;
    return 0;
}
