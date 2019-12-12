//https://www.cnblogs.com/grandyang/p/4295618.html
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
typedef struct Tree
{
    struct Tree* left;
    struct Tree* right;
    int val;
}tree;
void level_traverse(tree* root)
{
    if(root==NULL) return;
    queue<tree*> q;
    q.push(root);
    while(!q.empty())
    {
        tree* qf=q.front();
        q.pop();
        cout<<qf->val<<",";
        if(qf->left!=NULL) q.push(qf->left);
        if(qf->right!=NULL) q.push(qf->right);
    }
}
tree* link2bst(node* head)
{
    if(head==NULL) return NULL;
    if(head->next==NULL) 
    {
        tree* tmp=new tree;
        tmp->val=head->val;
        tmp->left=NULL;
        tmp->right=NULL;
        return tmp;
    }
    node* slow=head;
    node* fast=head;
    node* last = slow;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        last = slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=slow->next;
    last->next=NULL;
    tree* cur=new tree;
    cur->val=slow->val;
    if(head!=slow) cur->left=link2bst(head);
    cur->right=link2bst(fast);
    return cur;
}
int main()
{
    node* n1=new node;
    node* n2=new node;
    node* n3=new node;
    node* n4=new node;
    node* n5=new node;
    n1->val=-10;
    n2->val=-3;
    n3->val=0;
    n4->val=5;
    n5->val=9;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=NULL;
    tree* root=link2bst(n1);
    level_traverse(root);
    return 0;
}
