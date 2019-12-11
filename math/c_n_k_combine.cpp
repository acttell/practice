//https://www.cnblogs.com/grandyang/p/4332522.html
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
void assit(int n,int k,int level,vector<int>& tmp,vector<vector<int>>& res)
{
    if(tmp.size()==k) 
    {
        res.push_back(tmp);
        return;
    }
    for(int i=level;i<=n;i++)
    {
        tmp.push_back(i);
        assit(n,k,i+1,tmp,res);
        tmp.pop_back();
    }
}
vector<vector<int>> combine(int n,int k)
{
    vector<vector<int>> res;
    vector<int> tmp;
    assit(n,k,1,tmp,res);
    return res;
}
int main()
{
    vector<vector<int>> res;
    res=combine(3,2);
    for(auto iter1:res)
    {
        for(auto iter2:iter1)
        {
            cout<<iter2<<",";
        }
        cout<<endl;
    }
    return 0;
}
