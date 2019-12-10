//https://www.cnblogs.com/grandyang/p/4295245.html
#include<iostream>
#include<stack>
#include<vector>
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
tree* assist(vector<int>& v,int left,int right)
{
    if(left>right) return NULL;
    int mid=left+(right-left)/2;
    tree* cur=new tree;
    cur->val=v[mid];
    cur->left=assist(v,left,mid-1);
    cur->right=assist(v,mid+1,right);
    return cur;
}
tree* arr2bst(vector<int>& v)
{
    return assist(v,0,v.size()-1);
}
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
int main()
{
    int a[11]={1,2,4,'#','#',5,'#','#',3,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    inorder(root);
    index=0;
    tree* root1=creat_tree(a,n,index);
    level_traverse(root1);
    cout<<endl;
    vector<int> v={-10,-3,0,5,9};
    tree* root2=arr2bst(v);
    inorder(root2);
    cout<<endl;
    tree* root3=arr2bst(v);
    level_traverse(root3);
    return 0;
}
