//https://www.cnblogs.com/grandyang/p/4402392.html
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int trap_rain(vector<int>& v)
{
    int res=0,l=0,r=v.size()-1;
    while(l<r)
    {
        int s=min(v[l],v[r]);
        if(h[l]==s)
        {
            l++;
            while(l<r && v[l]<s) res+=s-v[l++];
        } 
        if(v[r]==s)
        {
            r--;
            while(l<r && v[r]<s) res+=s-v[r--];
        }
    }
    return res;
}

int main()
{
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap_rain(v);
    return 0;
}
