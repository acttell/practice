/*
https://blog.csdn.net/stpeace/article/details/46672035
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
#include <time.h>
using namespace std;

int rand5()
{
    return rand()%5+1;
}
int rand7()
{
    while(1)
    {   
        int n=(rand5()-1)*5+rand5();
        if(n>=21) continue;
        else
        {   
            return n%7+1;
        }   
    }   
}
int main()
{
    srand(time(NULL));
    int a[5]={0};
    int b[7]={0};
    for(int i=0;i<5000;i++)
    {   
        a[rand5()-1]++;
    }   
    for(int i=0;i<5;i++) cout<<a[i]<<endl;
    cout<<endl;
    for(int i=0;i<7000;i++)
    {   
        b[rand7()-1]++;
    } 
    for(int i=0;i<7;i++) cout<<b[i]<<endl;
}

