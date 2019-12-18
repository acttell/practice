//https://www.cnblogs.com/grandyang/p/4539757.html
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<functional>
using namespace std;
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left], l = left + 1, r = right;
    while (l < r) {
        if (nums[l] < pivot && nums[r] > pivot) {
            swap(nums[l++], nums[r--]);
        }
        if (nums[l] >= pivot) l++;
        if (nums[r] <= pivot) r--;
    }
    swap(nums[left], nums[r]);
    return r;
}
int find_top_k(vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1;
    while (true) {
        int pos = partition(nums, left, right);
        if (pos == k - 1) return nums[pos];
        if (pos > k - 1) right = pos - 1;
        else left = pos + 1;
    }
}
int main()
{
    vector<int> v={3,2,3,1,2,4,5,5,6};
    cout<<find_top_k(v,4);
    cout<<endl;
    return 0;
}
