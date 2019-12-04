/*
https://www.cnblogs.com/grandyang/p/4341243.html
*/
#include<iostream>
#include<vector>
using namespace std;
void color_sort(vector<int>& v)
{
    int start=0;
    int end=v.size()-1;
    for(int i=0;i<=end;i++)
    {
        if(v[i]==0)
        {
            swap(v[i],v[start]);
            start++;
        }
        if(v[i]==2)
        {
            swap(v[i],v[end]);
            i--;
            end--;
        }
    }
}
int main()
{
    vector<int> v={2,0,2,1,1,0};
    color_sort(v);
    for(auto iter:v)
    {
        cout<<iter<<",";
    }
    cout<<endl;
    return 0;
}
