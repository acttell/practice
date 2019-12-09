//https://www.jianshu.com/p/df2ba460e7d1
#include<iostream>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
node* pairs_swap(node* h)
{
    node* n=new node;
    n->next=h;
    node* p=n;
    while(p->next!=NULL && p->next->next!=NULL)
    {
        node* n1=p->next;
        node* n2=n1->next;
        node* n3=n2->next;
        n2->next=n1;
        n1->next=n3;
        p->next=n2;
        p=n1;
    }
    return n->next;
}
int main()
{
    node* n1=new node;
    node* n2=new node;
    node* n3=new node;
    node* n4=new node;
    n1->val=1;
    n2->val=2;
    n3->val=3;
    n4->val=4;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=NULL;

    node* h=pairs_swap(n1);
#if 1
    while(h!=NULL)
    {
        cout<<h->val<<" ";
        h=h->next;
    }
#endif
    return 0;
}
