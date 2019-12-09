//https://www.cnblogs.com/littlepanpc/p/7704776.html
#include<iostream>
#include<vector>
using namespace std;
int asc_desc_find_max(vector<int>& v)
{
    int begin=0;
    int end=v.size()-1;
    while(begin<=end)
    {
        int mid=begin+(end-begin)/2;
        if(mid>=1)
        {
            if(v[mid]>v[mid-1] && v[mid]>v[mid+1]) return mid;
            else if(v[mid]>v[mid+1]) end=mid-1;
            else if(v[mid]>v[mid-1]) begin=mid+1;
        }
    }
    return -1;
}
int main()
{
    vector<int> v={1,2,3,4,5,6,7,8,6,5,4,2,1};
    cout<<asc_desc_find_max(v);
    return 0;
}
