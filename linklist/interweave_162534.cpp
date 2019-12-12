//https://www.cnblogs.com/grandyang/p/4254860.html
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<limits.h>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
node* revert(node* h)
{
    node* p=h;
    node* q=h->next;
    node* r=q->next;
    h->next=NULL;
    while(q!=NULL)
    {
        q->next=p;
        p=q;
        q=r;
        if(r!=NULL) r=r->next;
    }
    return p;
}
node* interweave_162534(node* head)
{
    if (!head || !head->next || !head->next->next) NULL;
    node* fast=head;
    node* slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    node* mid=slow->next;
    slow->next=NULL;
    node* p1=head;
    node* p2=revert(mid);
    while(p1!=NULL && p2!=NULL)
    {
        node* tmp=p1->next;
        p1->next=p2;
        p2=p2->next;
        p1->next->next=tmp;
        p1=tmp;
    }
    return head;
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
    node* h=interweave_162534(n1);
    while(h!=NULL)
    {
        cout<<h->val<<",";
        h=h->next;
    }
    return 0;
}
