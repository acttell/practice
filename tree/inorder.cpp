/*
https://www.cnblogs.com/SHERO-Vae/p/5800363.html
*/
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
void inorder(tree* root)
{
    if(root==NULL) return;
    if(root!=NULL)
    {
        if(root->left!=NULL) inorder(root->left);
        cout<<root->val<<",";
        if(root->right!=NULL) inorder(root->right);
    }
}
void inorder_stack(tree* root)
{
    stack<tree*> s;
    tree* t=root;
    while(!s.empty() || t!=NULL)
    {
        while(t!=NULL)
        {
            s.push(t);
            t=t->left;
        }
        if(!s.empty())
        {
            t=s.top();
            cout<<t->val<<",";
            s.pop();
            t=t->right;
        }
    }
}
int main()
{
    int a[11]={1,2,4,'#','#',5,'#','#',3,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    inorder(root);
    cout<<endl;
    inorder_stack(root);
    return 0;
}
