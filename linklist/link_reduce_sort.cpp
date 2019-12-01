/*
https://www.cnblogs.com/grandyang/p/4249905.html
*/
#include<iostream>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
node* merge(node* l1,node* l2)
{
    node* h;
    node* cur=new node;
    cur->val=-1;
    h=cur;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val<l2->val)
        {
            cur->next=l1;
            l1=l1->next;
        }else
        {
            cur->next=l2;
            l2=l2->next;
        }
        cur=cur->next;
    }
    if(l1!=NULL) cur->next=l1;
    if(l2!=NULL) cur->next=l2;
    return h->next;

}
node* reduce(node* l)
{
    if(l==NULL || l->next==NULL) return l;
    node* pre;
    node* slow;
    node* fast;
    pre=l;
    slow=l;
    fast=l;
    while(fast!=NULL && fast->next!=NULL)
    {
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    pre->next=NULL;
    node* first=reduce(l);
    node* second=reduce(slow);
    return merge(first,second);
}
int main()
{
    node* n1=new node;
    node* n2=new node;
    node* n3=new node;
    node* n4=new node;
    node* n5=new node;
    node* n6=new node;
    n1->val=2;
    n2->val=4;
    n3->val=3;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->val=5;
    n5->val=7;
    n6->val=6;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;
    node* h=reduce(n1);
    while(h!=NULL)
    {
        cout<<h->val<<" ";
        h=h->next;
    }
    return 0;
}
