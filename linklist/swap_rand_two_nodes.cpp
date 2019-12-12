//https://www.cnblogs.com/grandyang/p/5493999.html
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
node* swap_rand_two_nodes(node* head,int v1,int v2)
{
    node* dummy=new node;
    dummy->next=head;
    node* pre=dummy;
    node* cur=dummy;
    node* p1=NULL;
    node* p2=NULL;
    while(cur->next!=NULL)
    {
        if(cur->next->val==v1 || cur->next->val==v2)
        {
            if(p1==NULL)
            {
                p1=cur->next;
                pre=cur;
            } else
            {
                node* t=cur->next->next;
                p2=cur->next;
                pre->next=p2;
                if(cur==p1)
                {
                    p2->next = p1;
                    p1->next = t;
                } else
                {
                    p2->next=p1->next;
                    cur->next=p1;
                    p1->next = t;
                }
                return dummy->next;
            }
        }
        cur=cur->next;
    }
    return dummy->next;
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
    node* h=swap_rand_two_nodes(n1,1,3);
    while(h!=NULL)
    {
        cout<<h->val<<",";
        h=h->next;
    }
    return 0;
}
