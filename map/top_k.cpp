//https://www.cnblogs.com/grandyang/p/4539757.html
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct cmp
{
    bool operator()(int a,int b)
    {
        return a<=b;
    }
};
int topk(vector<int>& v,int k)
{
    priority_queue<int,vector<int>,cmp> q;
    for(int i=0;i<v.size();i++)
        q.push(v[i]);
    for(int i=0;i<k-1;i++)
        q.pop();
    return q.top();
}
int main()
{
    vector<int> v1={3,2,1,5,6,4};
    cout<<topk(v1,2)<<endl;
    vector<int> v2={3,2,3,1,2,4,5,5,6};
    cout<<topk(v2,4)<<endl;
    return 0;
}
