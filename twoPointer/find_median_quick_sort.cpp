//https://blog.csdn.net/oneday_789/article/details/76681764
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
int find_median(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int mid=left+(right-left)/2;
    int obj=partition(nums,left,right);
    while (obj!=mid) {
        if(obj<mid) obj=partition(nums,obj+1,right);
        else
        {
            obj=partition(nums,left,obj-1);
        }   
    }
    return nums[mid];
}
int main()
{
    vector<int> v={3,1,5,2,6};
    cout<<find_median(v);
    cout<<endl;
    return 0;
}
