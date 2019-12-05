//https://www.cnblogs.com/grandyang/p/5282959.html
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> sparse_multiply(vector<vector<int>>& v1,vector<vector<int>>& v2)
{
    vector<vector<int>> res(v1.size(),vector<int>(v2[0].size()));
    for(int i=0;i<v1.size();i++)
    {
        for(int j=0;j<v1[0].size();j++)
        {
            if(v1[i][j]!=0)
            {
                for(int k=0;k<v2[0].size();k++)
                {
                    if(v2[j][k]!=0)
                        res[i][k]+=v1[i][j]*v2[j][k];
                }
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> v1;
    vector<vector<int>> v2;
    vector<vector<int>> v3;
    v1={
        {1, 0, 0},
        {-1, 0, 3}
    };
    v2={
        {7, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    v3=sparse_multiply(v1,v2);
    for(auto iter1:v3)
    {
        for(auto iter2:iter1)
        {
            cout<<iter2<<",";
        }
        cout<<endl;
    }
    return 0;
}
