//https://www.cnblogs.com/grandyang/p/7500082.html
#include<iostream>
#include<stack>
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
string helper(tree* node, unordered_map<string, int>& m, vector<tree*>& res) {
    if (node==NULL) return "#";
    string str1 = helper(node->left, m, res);
    string str2 = helper(node->right, m, res);
    string str = to_string(node->val) + "," +str1 + "," + str2; cout<<str<<endl;
    if (m[str] == 1) res.push_back(node); for(int i=0;i<res.size();i++) cout<<res[i]->val<<","; cout<<endl;
    ++m[str];
    return str;
}
vector<tree*> duplicate_sub_tree(tree* root) {
    vector<tree*> res;
    unordered_map<string, int> m;
    helper(root, m, res);
    return res;
}
int main()
{
    int a[]={1,2,4,'#','#',5,'#','#',2,4,'#','#',5,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    tree* root=creat_tree(a,n,index);
    vector<tree*> v=duplicate_sub_tree(root);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]->val<<",";
    }
    cout<<endl;
    return 0;
}
