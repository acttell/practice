//https://www.cnblogs.com/grandyang/p/4298711.htmls
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void rotate(vector<int>& v,int k)
{
    if(v.size()==0 || k%v.size()==0) return;
    int n=v.size();
    reverse(v.begin(),v.begin()+n-k);
    reverse(v.begin()+n-k,v.end());
    reverse(v.begin(),v.end());
}
int main()
{
    vector<int> v={1,2,3,4,5};
    rotate(v,2);
    for(auto iter:v)
    {
        cout<<iter<<",";
    }
    cout<<endl;
    return 0;
}
