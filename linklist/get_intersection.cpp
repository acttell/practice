//https://www.cnblogs.com/grandyang/p/4128461.html
#include<iostream>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
int getlen(node* h)
{
    node* t=h;
    int len=0;
    while(t!=NULL)
    {
        len++;
        t=t->next;
    }
    return len;
}
node* intersect(node* p,node* q)
{
    if(p==NULL || q==NULL) return NULL;
    node* a=p;
    node* b=q;
    int lena=getlen(a);
    int lenb=getlen(b);
    if(lena>lenb)
    {
        for(int i=0;i<lena-lenb;i++) a=a->next;
    } else
    {
        for(int i=0;i<lenb-lena;i++) b=b->next;
    }
    while(a!=NULL && b!=NULL && a!=b)
    {
        a=a->next;
        b=b->next;
    }
    if(a==b) return a;
    else return NULL;
    
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
    n2->val=2;
    n3->val=3;
    n4->val=4;
    n5->val=5;
    n6->val=6;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;
    node* n7=new node;
    n7->val=7;
    n7->next=n3;
    node* h=intersect(n1,n7);
    if(h!=NULL) cout<<"intersect:"<<h->val;
    return 0;
}
