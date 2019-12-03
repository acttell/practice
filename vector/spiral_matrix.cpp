/*
https://blog.csdn.net/acttell/article/details/80789299
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> spiral_matrix(vector<vector<int>>& vv)
{
    int l=0;
    int r=vv[0].size()-1;
    int u=0;
    int d=vv.size()-1;
    vector<int> v;
    while(l<=r && u<=d)
    {
        for(int i=l;i<=r;i++) v.push_back(vv[u][i]);
        u++;
        for(int j=u;j<=d;j++) v.push_back(vv[j][r]);
        r--;
        if(u<d)
        {
            for(int m=r;m>=l;m--) v.push_back(vv[d][m]);
        }
        d--;
        if(l<r)
        {
            for(int n=d;n>=u;n--) v.push_back(vv[n][l]);
        }
        l++;
    }
    return v;

}
int main()
{
    vector<vector<int>> vv={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> v=spiral_matrix(vv);
    for(auto iter:v)
    {
        cout<<iter<<",";
    }
    cout<<endl;
    return 0;
}
