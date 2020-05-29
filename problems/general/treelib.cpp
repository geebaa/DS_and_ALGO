#include <bits/stdc++.h>

using namespace std;

class BinaryTreeNode {
    public :
    int key;
    BinaryTreeNode *left,*right;
    BinaryTreeNode(int n) {
        key = n;
        left=NULL;
        right=NULL;
    }
};
 
class NaryTreeNode {
    public :
    int key;
    NaryTreeNode *children;
    NaryTreeNode(int n) {
        key = n;
        children=NULL;
    }
};



/*
    assumes root not NULL
*/
void dfs( BinaryTreeNode *root )
{

    //base case : Leaf node check
    if((root->left == NULL) && (root->right == NULL))
    {
        //do leaf processing
        return;
    }
    //recursive case : Non leaf node

    if(root->left)
    {
        dfs(root->left);
    }

    if(root->right)
    {
        dfs(root->right);
    }

    return;
}
/*
    depth first traversal - uses dfs to traverse the tree
*/
void dft(BinaryTreeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    dfs(root);
    return;
}


void bfs( BinaryTreeNode *root )
{
    queue < BinaryTreeNode *> q;
    q.push(root);

    while(!q.empty())
    {
        BinaryTreeNode *curr = q.front();
        q.pop();

        if(curr->left) 
        {
            q.push(curr->left);
        }
        if(curr->right) 
        {
            q.push(curr->right);
        }

    }

    return;
}

/*
    breadth first traversal - uses dfs to traverse the tree
*/
void bft(BinaryTreeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    bfs(root);
    return;
}
/*
   Constructs a BST of n nodes and returns.
*/

BinaryTreeNode *gettree(int n)
{
    queue <BinaryTreeNode > key_queue,level_queue;
    for(int i=0;i<n;i++)
    {
        key_queue.push(BinaryTreeNode(i));
    }
    return NULL;
}

int main()
{
    BinaryTreeNode *root = NULL;
    dft(root);
    bft(root);
    return 0;
}


