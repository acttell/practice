//https://www.cnblogs.com/grandyang/p/4042168.html
#include<iostream>
#include<vector>
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
int min_depth(tree* root)
{
    if(root==NULL) return 0;
    if(root->left==NULL) return 1+min_depth(root->right);
    if(root->right==NULL) return 1+min_depth(root->left);
    return 1+min(min_depth(root->right),min_depth(root->left));
}
int main()
{
    int a[11]={1,2,4,'#','#',5,'#','#',3,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    cout<<min_depth(root);
    return 0;
}
