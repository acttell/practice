//https://blog.csdn.net/licongqi/article/details/16845205
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Tree
{
    struct Tree* left;
    struct Tree* right;
    int val;
}tree;
void help(tree* root,tree*& last)
{
    if(root==NULL) return;
    tree* cur=root;
    if(cur->left!=NULL) help(cur->left,last);
    cur->left=last;
    if(last!=NULL) last->right=cur;
    last=cur;
    if(cur->right!=NULL) help(cur->right,last);
}
tree* tree_to_list(tree* root)
{
    tree* last=NULL;
    help(root,last);
    tree* head=last;
    while(head && head->left)
    {
        head=head->left;
    }
    return head;
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
    int a[11]={4,2,1,'#','#',3,'#','#',6,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    level_traverse(root);
    tree* h=tree_to_list(root);
    while(h)
    {
        cout<<h->val<<",";
        h=h->right;
    }
    return 0;
}
