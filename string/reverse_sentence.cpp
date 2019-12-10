//https://www.cnblogs.com/grandyang/p/4606676.html
#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
void reverse_sentence(string& s)
{
    int n=s.size();
    int index=0;
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++)
    {
        if(s[i]!=' ')
        {
            if(index!=0) s[index++]=' ';
            int j=i;
            while(s[j]!=' ' && j<n) s[index++]=s[j++];
            reverse(s.begin()+index-(j-i),s.begin()+index);
            i=j;
        }
    }
    s.resize(index);
}
int main()
{
    string s="   i am ok,     that's true!  ";
    reverse_sentence(s);
    cout<<s<<endl;
    return 0;
}
