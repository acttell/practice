/*
https://blog.csdn.net/morewindows/article/details/6684558
*/
#include<iostream>
#include<vector>
using namespace std;

int merge_sort(vector<int>& s,int l,int r)
{
    int i=l;
    int j=r;
    int x=s[i];
    while(i<j)
    {
        while(i<j && s[j]>x) j--;
        if(i<j)
        {   
            s[i]=s[j];
            i++;
        }   
        while(i<j && s[i]<x) i++;
        if(i<j)
        {   
            s[j]=s[i];
            j--;
        }   
    }   
    s[i]=x;
    return i;
}

void merge_sort_recursive(vector<int>& v,int l,int r)
{
    if(l<r)
    {   
        int i=merge_sort(v,l,r);
        merge_sort_recursive(v,l,i-1);
        merge_sort_recursive(v,i+1,r);
    }   
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    //v.push_back(2);
    v.push_back(1);
    v.push_back(9);
    merge_sort_recursive(v,0,v.size()-1);
    for(int i=0;i<v.size();i++) cout<<v[i]<<",";
    return 0;
}
