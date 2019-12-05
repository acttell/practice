//https://www.cnblogs.com/grandyang/p/4640572.html
#include<iostream>
#include<stack>
using namespace std;
typedef struct Tree
{
    struct Tree* left;
    struct Tree* right;
    int val;
}tree;
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
tree* ancestor_bst(tree* root,tree* p,tree* q)
{
    if(root==NULL) return NULL;
    if(root->val>max(p->val,q->val)) return ancestor_bst(root->left,p,q);
    else if(root->val<min(p->val,q->val)) return ancestor_bst(root->right,p,q);
    else return root;
}
int main()
{
    int a[11]={4,2,1,'#','#',3,'#','#',6,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    tree* p=root->left->left;
    //tree* q=root->right;
    tree* q=root->left->right;
    tree* t=ancestor_bst(root,p,q);
    cout<<"lowest common ancestor bst:"<<t->val<<endl;
    return 0;
}
