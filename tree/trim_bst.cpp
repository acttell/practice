//https://www.cnblogs.com/grandyang/p/7583185.html
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
tree* creat_tree(int* a,int& n,int& index)
{
    tree* root=new tree;
    if(index<n && a[index]=='#')
    {
        root=NULL;
    }
    if(index<n && a[index]!='#'){
        root->val=a[index];
        root->left=creat_tree(a,n,++index);
        root->right=creat_tree(a,n,++index);
    }
    return root;
}
tree* trim_bst(tree* root,int l,int r)
{
    if(root==NULL) return NULL;
    if(root->val<l) return trim_bst(root->right,l,r);
    if(root->val>r) return trim_bst(root->left,l,r);
    root->left=trim_bst(root->left,l,r);
    root->right=trim_bst(root->right,l,r);
    return root;
}
int main()
{
    int a[11]={1,2,4,'#','#',5,'#','#',3,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    tree* h=trim_bst(root,3,5);
    level_traverse(h);
    return 0;
}
