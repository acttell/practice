//https://www.cnblogs.com/grandyang/p/4465932.html
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<limits.h>
using namespace std;
int findk(vector<int>& v1, int i, vector<int>& v2, int j, int k)
{
    if(i>=v1.size()) return v2[j+k-1];
    if(j>=v2.size()) return v1[i+k-1];
    if(k==1) return min(v1[i],v2[j]);
    int mid1=(i+k/2-1<v1.size())?v1[i+k/2-1]:INT_MAX;
    int mid2=(j+k/2-1<v2.size())?v2[j+k/2-1]:INT_MAX;
    if(mid1<mid2) return findk(v1,i+k/2,v2,j,k-k/2);
    else  return findk(v1,i,v2,j+k/2,k-k/2);
}
double median_two_sorted_arr(vector<int>& v1, vector<int>& v2) 
{
    int m=v1.size();
    int n=v2.size();
    int left=(m+n+1)/2;
    int right=(m+n+2)/2;
    return (findk(v1,0,v2,0,left)+findk(v1,0,v2,0,right))/2.0;
}
int main()
{
    vector<int> v1={1,2};
    vector<int> v2={3,4};
    cout<<median_two_sorted_arr(v1,v2);
    return 0;
}
