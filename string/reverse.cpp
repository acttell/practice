/*
*/
#include<iostream>
using namespace std;
void reverse(char* s,int n)
{
    for(int i=0;i<(n-1)/2;i++)
    {   
        swap(s[i],s[n-2-i]);
    }   
    
}
int main()
{
    char s[]="abde";
    int n=sizeof(s)/sizeof(char);
    cout<<"len:"<<n<<endl;
    reverse(s,n);
    cout<<s<<endl;
    return 0;
}
