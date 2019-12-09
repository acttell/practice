//https://blog.csdn.net/qq_28114615/article/details/86561069
#include<iostream>
#include<stack>
#include<limits.h>
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
int helper(tree* root,int& m);
int max_path_sum(tree* root) 
{
    if(!root)return 0;
    int m=INT_MIN;
    helper(root,m);
    return m;
}  
int helper(tree* root,int& m)
{
    if(root==NULL) return 0;  
    int l=helper(root->left,m);
    int r=helper(root->right,m);
    int path1=max(root->val,max(l+root->val,r+root->val));
    int path2=max(path1,l+r+root->val);
    m=max(m,path2);
    return path1;
}
int main()
{
    int a[11]={1,2,4,'#','#',5,'#','#',3,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    tree* root=creat_tree(a,n,index);
    int res=0;
    cout<<max_path_sum(root);
    return 0;
}
