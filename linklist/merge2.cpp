/*
https://www.cnblogs.com/grandyang/p/4086297.html
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
node* mergetwo(node* p,node* q)
{
    if(p==NULL) return q;
    if(q==NULL) return p;
    if(p==NULL && q==NULL) return NULL;
    node* t=new node;
    t->val=-1;
    node* h=t;
    while(p!=NULL && q!=NULL)
    {
        if(p->val<q->val)
        {
            t->next=p;
            p=p->next;
        }else
        {
            t->next=q;
            q=q->next;
        }
        t=t->next;
    }
    if(p==NULL && q!=NULL) t->next=q;
    if(q==NULL && p!=NULL) t->next=p;
    return h->next;
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
    n2->next=NULL;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;
    node* h=mergetwo(n1,n3);
    while(h!=NULL)
    {
        cout<<h->val<<",";
        h=h->next;
    }
    return 0;
}
