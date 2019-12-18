//https://www.cnblogs.com/grandyang/p/6529857.html
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;
int max_0_1_contiguous(vector<int>& v) 
{
    int n=v.size();
    int sum=0;
    int num=0;
    unordered_map<int,int> m;
    m[0]=-1;
    for(int i=0;i<n;i++)
    {
        sum+=(v[i]==1)?1:-1; 
        if(m.count(sum)) num=max(num,i-m[sum]);
        else m[sum]=i;
    }
    return num;
}

//0  1  0  0  0  1  1 0
//-1 0 -1 -2 -3 -2 -1 0
int main()
{
    vector<int> v1={0,1,0};
    //vector<int> v1={0,1,0,0,0,1,1,0};
    cout<<max_0_1_contiguous(v1);
    cout<<endl;
    return 0;
}
