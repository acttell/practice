//https://blog.csdn.net/zuochao_2013/article/details/53746296
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
void doprint(int m,int n)
{
    for(int i=m;i<=n;i++)
    {
        cout<<i<<",";
    }
    cout<<endl;
}
void continuous_sub_equal_n(int n)
{
    int left=1;
    int right=2;
    int cur=left+right;
    if(cur==n) doprint(left,right);
    while(left<right && right<n)
    {
        right++;
        cur+=right;
        if(cur==n && right!=n) doprint(left,right);
        while(cur>n && left<right) 
        {
            cur-=left;
            left++;
            if(cur==n && left!=n) doprint(left,right);
        }
    }
}
int main()
{
    continuous_sub_equal_n(15);
    return 0;
}
