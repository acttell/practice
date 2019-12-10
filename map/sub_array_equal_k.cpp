//https://www.cnblogs.com/grandyang/p/6810361.html
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int sub_array_equal_k(vector<int> v,int k)
{
    int res=0;
    int sum=0;
    unordered_map<int,int> m;
    m[0]=1;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];//1,3,6,9,15,21,21
        res+=m[sum-k];//-5,-3,0,3,9,15,15
        m[sum]++;
    }
    return res;
}
int main()
{
    vector<int> v={1,2,3,3,6,6,0};
    cout<<sub_array_equal_k(v,6)<<endl;
    return 0;
}
