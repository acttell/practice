//https://blog.csdn.net/zlx_code/article/details/88976466
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
float search_sqrt(float n)
{
    float low=0.0;
    float high=n/2.0;
    float mid=0.0;
    while(abs(high-low)>1e-6)
    {
        mid=low+(high-low)/2.0;
        float mid2=mid*mid;
        if(mid2>n) high=mid;
        else if(mid2<n) low=mid;
        else return mid;
    }
    return mid;
}
int main()
{
    cout<<search_sqrt(8.0);
    return 0;
}
