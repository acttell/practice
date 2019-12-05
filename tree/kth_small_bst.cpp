//https://www.cnblogs.com/grandyang/p/4620012.html
#include<iostream>
#include<stack>
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
int kthSmallest(tree* root,int k)
{
    tree* t=root;
    int cnt=0;
    stack<tree*> s;
    while(!s.empty() || t!=NULL)
    {
        while(t!=NULL)
        {
            s.push(t);
            t=t->left;
        }
        if(!s.empty())
        {
            t=s.top();
            s.pop();
            cnt++;
            if(cnt==k)  return t->val;
            t=t->right;
        }
    }
    return -1;
}
int main()
{
    int a[11]={4,2,1,'#','#',3,'#','#',6,'#','#'};
    int index=0;
    int n=sizeof(a)/sizeof(int);
    cout<<"size:"<<n<<endl;
    tree* root=creat_tree(a,n,index);
    cout<<"kth:"<<kthSmallest(root,3);
    return 0;
}
