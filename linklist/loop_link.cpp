//https://www.cnblogs.com/dancingrain/p/3405197.html
#include<iostream>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
bool haveloop(node* h)
{
    node* slow=h;
    node* fast=h;
    while(slow!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) return true;
    }
    return false;
}
node* find_entrance(node* h)
{
    node* slow=h;
    node* fast=h;
    while(slow!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow) break;
    }
    if(fast==NULL || slow==NULL) return NULL;
    node* p1=h;
    while(p1!=slow)
    {
        p1=p1->next;
        slow=slow->next;
    }
    return p1;
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
    n4->val=5;
    n5->val=6;
    n6->val=4;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n2;
    cout<<"exist loop:"<<haveloop(n1)<<endl;
    node* e=find_entrance(n1);
    cout<<"entrance:"<<e->val<<endl;
    return 0;
}
