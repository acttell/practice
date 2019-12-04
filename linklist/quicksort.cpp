/*
https://www.cnblogs.com/LJ-LJ/p/11385886.html
*/
#include<iostream>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
node* part(node* begin,node* end)
{
    node* slow=begin;
    node* fast=begin->next;
    int val=begin->val;
    while(fast!=end)
    {
        if(fast->val<val)
        {
            slow=slow->next;
            swap(slow->val,fast->val);
        }
        fast=fast->next;
    }
    swap(slow->val,begin->val);
    return slow;
}
void quicksort(node* begin,node* end)
{
    if(begin!=end)
    {
        node* temp=part(begin,end);
        quicksort(begin,temp);
        quicksort(temp->next,end);
    }
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
    n6->val=1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=NULL;
    quicksort(n1,n6->next);
    node* h=n1;
    while(h!=NULL)
    {
        cout<<h->val<<" ";
        h=h->next;
    }
    return 0;
}
