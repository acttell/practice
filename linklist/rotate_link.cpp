//https://www.cnblogs.com/grandyang/p/4355505.html
#include<iostream>
using namespace std;
typedef struct Node
{
    struct Node* next;
    int val;
}node;
node* rotate(node* h,int k)
{
    if(h==NULL) return NULL;
    node* tmp=h;
    int n=0;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        n++;
    }
    cout<<"len:"<<n<<endl;
    k%=n;
    node* fast=h;
    node* slow=h;
    for(int i=0;i<k;i++)
    {
        fast=fast->next;
        if(fast==NULL) return h;
    }
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    fast->next=h;
    fast=slow->next;
    slow->next=NULL;
    return fast;
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
    node* h=rotate(n1,2);
    while(h!=NULL)
    {
        cout<<h->val<<" ";
        h=h->next;
    }
    return 0;
}
