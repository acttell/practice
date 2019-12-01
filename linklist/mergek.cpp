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
struct cmp
{
    bool operator()(node* a,node* b)
    {
        return a->val>b->val;
    }
};
node* mergek(vector<node*>& v)
{
    priority_queue<node*,vector<node*>,cmp> pq;
    for(int i=0;i<v.size();i++) pq.push(v[i]);
    node* h=NULL;
    node* p=NULL;
    node* q=NULL;
    while(!pq.empty())
    {
        q=pq.top();
        pq.pop();
        if(q->next!=NULL) pq.push(q->next);
        if(h==NULL)
        {
            h=p;
            p=q;
        }else
        {
            p->next=q;
            p=p->next;
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
    n2->val=2;
    n3->val=3;
    n4->val=4;
    n5->val=5;
    n1->next=n2;
    n2->next=NULL;
    n3->next=NULL;
    n4->next=n5;
    n5->next=NULL;
    vector<node*> v;
    v.push_back(n1);
    v.push_back(n3);
    v.push_back(n4);
    node* h=mergek(v);
    node* lp=h;
    while(lp!=NULL)
    {
        cout<<lp->val<<" ";
        lp=lp->next;
    }
    return 0;
}
