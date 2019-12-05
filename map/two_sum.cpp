//https://blog.csdn.net/acttell/article/details/80954185
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> find_two_sum(vector<int>& v,int target)
{
    unordered_map<int,int> m;
    vector<int> v1;
    for(int i=0;i<v.size();i++) m[v[i]]=i;
    for(int j=0;j<v.size();j++)
    {
        int val=target-v[j];
        if(m.count(val) && m[val]!=j)
        {
            v1.push_back(j);
            v1.push_back(m[val]);
            break;
        }
    }
    return v1;
}
int main()
{
    vector<int> v={2,7,11,15};
    vector<int> v1;
    v1=find_two_sum(v,9);
    for(auto iter:v1) cout<<iter<<",";
    return 0;
}
