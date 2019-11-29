/*
https://blog.csdn.net/acttell/article/details/80723496
*/
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
void path(tree* root,int num,int& cur,vector<int>& v)
{
    if(root==NULL) return;
    cur+=root->val;
    v.push_back(root->val);
    bool leaf=false;
    if(root->left==NULL && root->right==NULL) leaf=true;
    if(left && cur==num)
    {
        for(auto i:v)
        {
            cout<<i<<",";
        }
        cout<<endl;
    }
    if(root->left!=NULL) path(root->left,num,cur,v);
    if(root->right!=NULL) path(root->right,num,cur,v);
    cur-=root->val;
    v.pop_back();
}
int main()
{
    int a[11]={1,2,4,'#','#',5,'#','#',3,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    int cur=0;
    vector<int> v;
    path(root,7,cur,v);
    return 0;
}
