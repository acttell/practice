/*
https://blog.csdn.net/dycljj/article/details/75808155
https://blog.csdn.net/acttell/article/details/80723496
https://www.cnblogs.com/grandyang/p/4297009.html
*/
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
vector<vector<int>> zlevel(tree* root)
{
    if(root==NULL) return {};
    vector<vector<int>> res;
    queue<tree*> q;
    q.push(root);
    int cnt=0;
    while(!q.empty())
    {
        vector<int> level;
        for(int i=q.size();i>0;i--)
        {
            tree* qf=q.front();
            q.pop();
            level.push_back(qf->val);
            if(qf->left!=NULL) q.push(qf->left);
            if(qf->right!=NULL) q.push(qf->right);
        }
        if(cnt%2==1) reverse(level.begin(),level.end());
        res.push_back(level);
        ++cnt;
    }
    return res;
}
int main()
{
    int a[11]={1,2,4,'#','#',5,'#','#',3,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    level_traverse(root);
    cout<<endl;
    vector<vector<int>> res;
    res=zlevel(root);
    for(auto i1:res)
    {
        for(auto i2:i1)
        {
            cout<<i2<<",";
        }
        cout<<endl;
    }
    return 0;
}
