/*
https://www.cnblogs.com/grandyang/p/4606920.html
*/
#include<iostream>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
node* removenode(node* h,int n)
{
    if(h->next==NULL) return NULL;
    node* n1=h;
    node* n2=h;
    for(int i=0;i<n;i++) n1=n1->next;
    if(n1==NULL) return h->next;
    while(n1->next!=NULL)
    {
        n1=n1->next;
        n2=n2->next;
    }
    n2->next=n2->next->next;
    return h;
}
int main()
{
    node* n1=new node;
    node* n2=new node;
    node* n3=new node;
    node* n4=new node;
    node* n5=new node;
    n1->val=1;
    n2->val=2;
    n3->val=3;
    n4->val=4;
    n5->val=5;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;

    node* h=removenode(n1,2);
    while(h!=NULL)
    {
        cout<<h->val<<" ";
        h=h->next;
    }
    return 0;
}
