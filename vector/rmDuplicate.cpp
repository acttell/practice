/*
https://www.cnblogs.com/grandyang/p/4329128.html
*/
#include<iostream>
#include<vector>
using namespace std;
int rmDuplicate(vector<int>& v)
{
    int fast=0;
    int slow=0;
    int n=v.size();
    while(fast<n)
    {
        if(v[slow]==v[fast])
        {
            fast++;
        } else
        {
            slow++;
            v[slow]=v[fast];
            fast++;
        }
    }
    for(int i=0;i<=slow;i++)
    {
        cout<<v[i]<<",";
    }
    cout<<endl;
    return v.empty()?0:(slow+1);

}
int main()
{
    vector<int> v={1,2,2,2,3};
    cout<<"num:"<<rmDuplicate(v);
    return 0;
}
