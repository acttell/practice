/*
https://www.cnblogs.com/grandyang/p/4129891.html
*/
#include<iostream>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
node* add(node* l1,node* l2)
{
    node* cur=new node;
    cur->val=-1;
    node* h=cur;
    int carry=0;
    while(l1!=NULL || l2!=NULL)
    {
        int val1=(l1!=NULL)?l1->val:0;
        int val2=(l2!=NULL)?l2->val:0;
        int sum=val1+val2+carry;
        carry=sum/10;
        cur->next=new node;
        cur->next->val=sum%10;
        cur=cur->next;
        if(l1!=NULL) l1=l1->next;
        if(l2!=NULL) l2=l2->next;
    }
    if(carry!=0) 
    {
        cur->next=new node;
        cur->next->val=1;
    }
    return h->next;
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
    n3->next=NULL;
    n4->val=5;
    n5->val=6;
    n6->val=4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;
    node* h=add(n1,n4);
    while(h!=NULL)
    {
        cout<<h->val<<" ";
        h=h->next;
    }
    return 0;
}
