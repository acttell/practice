/*
https://www.cnblogs.com/grandyang/p/4051715.html
*/
#include<iostream>
#include<queue>
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
bool symmetric(tree* left,tree* right)
{
    if(left==NULL && right==NULL) return true;
    if(left==NULL && right!=NULL || left!=NULL &&right==NULL || left->val!=right->val) return false;
    return symmetric(left->left,right->right) && symmetric(left->right,right->left);
}
bool is_symmetric(tree* root)
{   
    if(root==NULL) return true;
    return symmetric(root->left,root->right);
}
bool symmetric_queue(tree* root)
{
    if(root==NULL) return true;
    queue<tree*> q1,q2;
    q1.push(root->left);
    q2.push(root->right);
    while(!q1.empty()&&!q2.empty())
    {
        tree* left=q1.front();q1.pop();
        tree* right=q2.front();q2.pop();
        if(left==NULL && right==NULL) continue;
        if(left==NULL && right!=NULL || left!=NULL &&right==NULL || left->val!=right->val) return false;
        q1.push(left->left);
        q1.push(left->right);
        q2.push(right->right);
        q2.push(right->left);
    }
    return true;
}
int main()
{
    int a[11]={1,2,'#','#',2,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    cout<<is_symmetric(root);
    cout<<endl;
    cout<<symmetric_queue(root);
    return 0;
}
