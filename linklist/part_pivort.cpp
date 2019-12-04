/*
https://blog.csdn.net/HelloZEX/article/details/81126071?utm_source=blogxgwz6
*/
#include<iostream>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
node* part(node* h,int x)
{
    node* small=new node;
    node* large=new node;
    node* p=small;
    node* q=large;
    node* t=h;
    while(t!=NULL)
    {
        if(t->val<=x)
        {
            small->next=t;
            small=small->next;
        } else
        {
            large->next=t;
            large=large->next;
        }
        t=t->next;
    }
    large->next=NULL;
    small->next=q->next;
    return p->next;
}
int main()
{
    node* n1=new node;
    node* n2=new node;
    node* n3=new node;
    node* n4=new node;
    node* n5=new node;
    n1->val=1;
    n2->val=5;
    n3->val=3;
    n4->val=2;
    n5->val=4;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;
    node* h=part(n1,3);
    while(h!=NULL)
    {
        cout<<h->val<<" ";
        h=h->next;
    }
    return 0;
}
