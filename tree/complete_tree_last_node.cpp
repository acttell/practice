//https://blog.csdn.net/fangjian1204/article/details/39179343
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
tree* last_node_of_complete_tree(tree* root)
{
    if(root==NULL ||(!root->left && !root->right)) return root;
    int depth=0;
    tree* cur=root;
    while(cur!=NULL)
    {
        depth++;cur=cur->left;
    }
    cout<<"tree depth:"<<depth<<endl;
    int level=0,tmpdepth=0;
    while(root)
    {
        level++;
        if(level==depth) break;
        cur=root;
        if(cur->right!=NULL)
        {
            tree* pre=cur;
            cur=cur->right;
            tmpdepth=level+1;
            while(cur->left!=NULL)
            {
                tmpdepth++;
                pre=cur;
                cur=cur->left;
            }
            if(tmpdepth<depth) root=root->left;
            //else if(pre->right==NULL || pre->right==cur) return cur;
            else if(pre->right==NULL) return cur;
            else root=root->right;
        } else
            root=root->left;
    }
    return root;
}
int main()
{
    int a[11]={1,2,4,'#','#',5,'#','#',3,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    tree* last=last_node_of_complete_tree(root);
    cout<<last->val;
    return 0;
}
