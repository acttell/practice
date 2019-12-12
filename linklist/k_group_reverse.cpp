//https://www.cnblogs.com/grandyang/p/4441324.html
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
node* k_group_reverse(node* head,int k)
{
    node* dummy=new node;
    node* pre=dummy;
    node* cur=dummy;
    dummy->next=head;
    int num=0;
    while(cur->next!=NULL)
    {
        num++;
        cur=cur->next;
    }
    while(num>=k)
    {
        cur=pre->next;
        for(int i=1;i<k;i++)
        {
            node* t=cur->next;
            cur->next=t->next;
            t->next=pre->next;
            pre->next=t;
        }
        pre=cur;
        num-=k;
    }
    return dummy->next;
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
    node* h=k_group_reverse(n1,3);
    while(h!=NULL)
    {
        cout<<h->val<<",";
        h=h->next;
    }
    return 0;
}
