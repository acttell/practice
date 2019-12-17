//https://www.cnblogs.com/grandyang/p/5507129.html
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
vector<int> intersection(vector<int> v1,vector<int> v2)
{
    int i=0;
    int j=0;
    vector<int> v3;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]<v2[j]) i++;
        else if(v1[i]>v2[j]) j++;
        else
        {
            if(v3.empty() || v3.back()!=v1[i]) v3.push_back(v1[i]);
            i++;
            j++;
        }
    }
    return v3;
}
int main()
{
    vector<int> v1={3,2,1,5,6,4};
    vector<int> v2={3,2,3,1,2,4,5,5,6};
    vector<int> v3=intersection(v1,v2);
    for(auto iter:v3)
    {
        cout<<iter<<",";
    }
    cout<<endl;
    return 0;
}
