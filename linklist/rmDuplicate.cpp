/*
https://www.cnblogs.com/grandyang/p/4066453.html
*/
#include<iostream>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
node* rmDuplicate(node* h)
{
    node* cur=h;
    while(cur!=NULL&&cur->next!=NULL)
    {
        if(cur->val==cur->next->val)
        {
            cur->next=cur->next->next;
        } else
        {
            cur=cur->next;
        }
    }
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
    n2->val=3;
    n3->val=3;
    n4->val=4;
    n5->val=4;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;
    node* h=rmDuplicate(n1);
    while(h!=NULL)
    {
        cout<<h->val<<" ";
        h=h->next;
    }
    return 0;
}
