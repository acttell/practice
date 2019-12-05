//https://www.cnblogs.com/grandyang/p/4392254.html
#include<iostream>
#include<queue>
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
vector<int> right_view(tree* root)
{
    vector<int> res;
    if(root==NULL) return res;
    queue<tree*> q;
    q.push(root);
    while(!q.empty())
    {
        int len=q.size();
        res.push_back(q.back()->val);
        for(int i=0;i<len;i++)
        {
            tree* node=q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
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
    vector<int> v=right_view(root);
    for(auto iter:v)
    {
        cout<<iter<<",";
    }
    return 0;
}
