//https://www.cnblogs.com/grandyang/p/4296193.html
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
tree* assit(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRight) {
    if (iLeft > iRight || pLeft > pRight) return NULL;

    tree* cur=new tree;
    cur->val=postorder[pRight];
    int i=0;
    for (i = iLeft; i < inorder.size(); ++i) {
        if (inorder[i] == cur->val) break;
    }
    cur->left=assit(inorder, iLeft, i - 1, postorder, pLeft, pLeft + i - iLeft - 1);
    cur->right=assit(inorder, i + 1, iRight, postorder, pLeft + i - iLeft, pRight - 1);
    return cur;
}
tree* build_from_inorder_postorder(vector<int> &inorder, vector<int> &postorder) {
    return assit(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

int main()
{
    vector<int> v1={11,4,5,13,8,9};
    vector<int> v2={11,4,13,9,8,5};
    tree* root=build_from_inorder_postorder(v1,v2);
    level_traverse(root);
    return 0;
}
