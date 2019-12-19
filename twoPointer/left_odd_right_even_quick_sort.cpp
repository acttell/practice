//https://blog.csdn.net/a739260008/article/details/86562347
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;
void odd_even_double_pointer(vector<int>& nums, int left, int right) {
    int l = left;
    int r = right;
    while (l < r) {
        if (nums[l] %2 ==0 && nums[r] %2 !=0) swap(nums[l++], nums[r--]);
        if (nums[l] %2 !=0) l++;
        if (nums[r] %2 ==0) r--;
    }
}
int main()
{
    vector<int> v={3,4,5,2,7};
    odd_even_double_pointer(v,0,v.size()-1);
    for(auto iter:v) cout<<iter<<",";
    cout<<endl;
    return 0;
}
