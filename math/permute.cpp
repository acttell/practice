/*for example [1,2,3] 
第一位1和第一位1互换后:[1,2,3]
此时第一位1固定，剩下[2,3]递归有[1,2,3] [1,3,2]两种排列；互换的再换回保持原样
第二位2和第一位1互换后:[2,1,3]
此时第一位2固定，剩下[1,3]递归有[2,1,3] [2,3,1]两种排列；互换的再换回保持原样
第三位3和第一位1互换后:[3,2,1]
此时第一位3固定，剩下[2,1]递归有[3,1,2] [3,2,1]两种排列；
*/
#include<iostream>
#include<string>
using namespace std;
void permute(string s,int begin,int end)
{
    if(begin==end) cout<<s<<endl;
    else
    {
        int i=begin;
        for(int j=begin;j<end;j++)
        {
            swap(s[i],s[j]);
            permute(s,begin+1,end);
            swap(s[i],s[j]);
        }
    } 
}
int main()
{
    string s="123";
    permute(s,0,s.size());
}
