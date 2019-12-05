//https://blog.csdn.net/hackbuteer1/article/details/6666959
#include<iostream>
using namespace std;
int mystr2int(char* s)
{
    int i=0;
    for(i=0;s[i]==' ';i++);
    int sign=1;
    if(s[i]=='-')
    {
        sign=-1;
        i++;
    }
    int res=0;
    for(int j=i;s[j]!='\0';j++)
    {
        res=res*10+(s[j]-'0');
    }
    return res*sign;
}
void myint2str(int n,char* s)
{
    int sign=0;
    if(n<0) 
    {   
        sign=-1;
        n=-n;
    }   
    int i=0;
    while(n!=0)
    {   
        s[i++]=n%10+'0';
        n/=10;
    }   
    if(sign==-1) s[i++]='-';
    s[i]='\0';
    for(int j=i-1;j>=0;j--) cout<<s[j];
    cout<<endl;
}
int main()
{
    char s[]="-123";
    char a[100];
    cout<<mystr2int(s)<<endl;
    myint2str(-123,a);
    return 0;
}
