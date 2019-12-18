//https://www.cnblogs.com/grandyang/p/6607318.html
#include<iostream>
#include<vector>
#include<unordered_map>
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
int helper(tree* root,int& res,unordered_map<tree*, int>& m)
{
    if(root==NULL) return 0;
    if(m.count(root)) return m[root];
    int left=helper(root->left,res,m);
    int right=helper(root->right,res,m);
    res=max(res,left+right);
    m[root]=max(left, right) + 1;
    return m[root];
}
int max_depth(tree* root)
{
    int res=0;
    unordered_map<tree*, int> m;
    helper(root,res,m);
    return res;
}
int main()
{
    int a[11]={1,2,4,'#','#',5,'#','#',3,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    cout<<max_depth(root);
    return 0;
}
