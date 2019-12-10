//https://www.cnblogs.com/grandyang/p/4296500.html
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
tree* assit(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) {
    if (pLeft > pRight || iLeft > iRight) return NULL;
    int i=0;
    for(i=iLeft;i<=iRight;i++)
    {
        if(preorder[pLeft]==inorder[i]) break;
    }
    tree* cur=new tree;
    cur->val=preorder[pLeft];
    cur->left=assit(preorder,pLeft+1,pLeft+i-iLeft,inorder,iLeft,i-1);
    cur->right=assit(preorder,pLeft+i-iLeft+1,pRight,inorder,i+1,iRight);
    return cur;
}
tree* build_from_preorder_inorder(vector<int> &preorder, vector<int> &inorder) {
    return assit(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

int main()
{
    vector<int> v1={3,9,20,15,7};
    vector<int> v2={9,3,15,20,7};
    tree* root=build_from_preorder_inorder(v1,v2);
    level_traverse(root);
    return 0;
}
