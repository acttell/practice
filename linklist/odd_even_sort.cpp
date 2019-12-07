//https://www.cnblogs.com/DarrenChan/p/8764608.html
#include<iostream>
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
node* merge(node* a,node* b)
{
    node* p=new node;
    node* h=p;
    while(a!=NULL && b!=NULL)
    {
        if(a->val<=b->val)
        {
            p->next=a;
            p=p->next;
            a=a->next;
        }else
        {
            p->next=b;
            p=p->next;
            b=b->next;
        }
        
    }
    if(a!=NULL) p->next=a;
    if(b!=NULL) p->next=b;

    return h->next;
}
node* odd_even(node* h)
{
    node* odd=new node;
    node* even=new node;
    node* h1=odd;
    node* h2=even;
    node* cur=h;
    int flag=1;
    while(cur!=NULL)
    {
        if(flag%2!=0)
        {
            if(odd!=NULL)
            {
                odd->next=cur;
                odd=odd->next;
            }

        }else
        {
            if(even!=NULL)
            {
                even->next=cur;
                even=even->next;
            }
        }
        cur=cur->next;
        flag++;
    }
    odd->next=NULL;
    even->next=NULL;
    node* h3=revert(h2->next);
    node* h4=merge(h1->next,h3);
    return h4;
}
int main()
{
    node* n1=new node;
    node* n2=new node;
    node* n3=new node;
    node* n4=new node;
    node* n5=new node;
    node* n6=new node;
    n1->val=1;
    n2->val=6;
    n3->val=3;
    n4->val=4;
    n5->val=5;
    n6->val=2;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;

    node* h=odd_even(n1);
#if 1
    while(h!=NULL)
    {
        cout<<h->val<<" ";
        h=h->next;
    }
#endif
    return 0;
}
