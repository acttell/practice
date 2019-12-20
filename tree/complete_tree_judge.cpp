//https://blog.csdn.net/ONEDAY_789/article/details/54928613
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<algorithm>
#include<functional>
#include <stdio.h>
#include <stdint.h>
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
bool complete_tree_judge(tree* root)
{
    if(root==NULL) return false;
    queue<tree*> q;
    q.push(root);
    tree* cur=q.front();
    while(cur!=NULL)
    {
        q.push(cur->left);
        q.push(cur->right);
        q.pop();
        cur=q.front();
    }
    while(!q.empty())
    {
        if(q.front()) return false;
        q.pop();
    }
    return true;
}
int main()
{
    int a[11]={1,2,4,'#','#',5,'#','#',3,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    cout<<complete_tree_judge(root);
    return 0;
}
