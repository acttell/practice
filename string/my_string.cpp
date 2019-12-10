//https://blog.csdn.net/yanxiaolx/article/details/51932595
//https://www.xuebuyuan.com/3179264.html
#include<iostream>
#include<cstring>
using namespace std;
class mystr
{
public:
    mystr(const char* c=NULL);
    mystr(const mystr& s);
    mystr& operator=(const mystr& s);
    ~mystr();
    friend ostream& operator<<(ostream& os,mystr& s);
private:
    char* data;
};
mystr::mystr(const char* c)
{
    if(c==NULL) data=NULL;
    else
    {
        int len=strlen(c);
        data=new char[len+1];
        strcpy(data,c);
    } 
}
mystr::mystr(const mystr& s)
{
    if(s.data==NULL) data=NULL;
    else
    {
        int len=strlen(s.data);
        data=new char[len+1];
        strcpy(data,s.data);
    } 
}
mystr::~mystr()
{
    delete[] data;
    data=NULL;
}
mystr& mystr::operator=(const mystr& s)
{
    if(&s==this) return *this;
    else
    {
        delete[] data;
        int len=strlen(s.data);
        data=new char[len+1];
        strcpy(data,s.data);
    }
    return *this;
}
ostream& operator<<(ostream& os,mystr& s)
{
    os<<s.data;
    return os;
}
int main()
{
    mystr s1("abc");
    mystr s2(s1);
    mystr s3;
    s3=s2;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    return 0;
}
