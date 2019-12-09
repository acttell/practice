//https://www.cnblogs.com/xiaobingqianrui/p/8863408.html
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
void even_odd_swap(vector<int>& v)
{
    int right=v.size()-1;
    int left=0;
    while(left<right)
    {
        while(v[right]%2==0 && left<right)
        {
            right--;
        }
        while(v[left]%2!=0 && left<right)
        {
            left++;
        }
        swap(v[left++],v[right--]);
    }
}
int main()
{
    vector<int> a= {1,2,3,4,5,6,7,8,9};
    even_odd_swap(a);
    for(int i=0;i<a.size();i++) cout<<a[i]<<",";
    return 0;
}
