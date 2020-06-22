#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int key;
        Node* left;
        Node* right;
        Node(int k) {
            key = k;
            left = NULL;
            right = NULL;
        }
};
void dfs_inorder(Node* node,vector<int> &inorder)
{
    if(node->left){
        dfs_inorder(node->left,inorder);
    }
    inorder.push_back(node->key);
    if(node->right){
        dfs_inorder(node->right,inorder);
    }
}
void merge(vector<int> &arr1,vector<int> &arr2,vector<int> &arr)
{
    int n1=arr1.size(),n2=arr2.size();
    int i1=0,i2=0;
    while(i1<n1 && i2<n2){
        if(arr1[i1] < arr2[i2]){
            arr.push_back(arr1[i1]);
            i1++;
        }else{
            arr.push_back(arr2[i2]);
            i2++;
        }
    }
    while(i1<n1){
        arr.push_back(arr1[i1]);
        i1++;
    }
    while(i2<n2){
        arr.push_back(arr2[i2]);
        i2++;
    }
}

Node *construct_bst(vector<int> &inorder,int s,int e)
{
    // base case - if pointers cross nothing to construct
    if(s > e){
        return NULL;
    }
    int m=s + (e-s)/2;
    Node *node = new Node(inorder[m]);
    node->left  = construct_bst(inorder,s,m-1);
    node->right = construct_bst(inorder,m+1,e);

    return node;
}
Node* mergeTwoBSTs(Node* root1, Node* root2) {
        
    // Write your code here.
    vector<int> tree1_inorder;
    vector<int> tree2_inorder;
    vector<int> final_tree_inorder;
    if(root1){
        dfs_inorder(root1,tree1_inorder);
    }
    if(root2){
        dfs_inorder(root2,tree2_inorder);
    }
    merge(tree1_inorder,tree2_inorder,final_tree_inorder);
    return NULL;
    return construct_bst(final_tree_inorder,0,final_tree_inorder.size()-1);   
}


Node* buildTree(int idx, int key[], int tree[][2]) {
    Node* root = new Node(key[idx]);
    if(tree[idx][0] != -1) {
        root->left = buildTree(tree[idx][0], key, tree);
    }
    if(tree[idx][1] != -1) {
        root->right = buildTree(tree[idx][1], key, tree);
    }
    return root;
}

int max(int a, int b) {
    return a >= b ? a : b;
}

int abs(int a) {
    return a > 0 ? a : -a;
}

class Height {
    public:
        int height;
        Height() { height = 0;}
};

bool isBalanced(Node* temp, Height* height) {
    if(temp == NULL) {
        height -> height = 0;
        return true;
    }

    Height* lh = new Height();
    Height* rh = new Height();

    bool l = isBalanced(temp->left, lh);
    bool r = isBalanced(temp->right, rh);

    height->height =   max(lh->height, rh->height) + 1;

    if(abs(lh->height - rh->height) <= 1 && l && r)
        return true;
    return false;
}

void inOrderTraversal(Node* temp, vector<int> &list) {
    if(temp == NULL)
        return;
    inOrderTraversal(temp->left, list);
    list.push_back(temp->key);
    inOrderTraversal(temp->right, list);
}

int parent1[100001];
int key1[100001];
int child1[100001];
int parent2[100001];
int key2[100001];
int child2[100001];

int main() {
    ostream &fout = cout;
    
    int N1;
    cin >> N1;
    
    for(int i = 0; i < N1; i++) {
        cin >> parent1[i];
    }
    
    for(int i = 0; i < N1; i++) {
        cin >> child1[i];
    }

    for(int i = 0; i < N1; i++) {
        cin >> key1[i];
    }
    
    int N2;
    cin >> N2;
    
    for(int i = 0; i < N2; i++) {
        cin >> parent2[i];
    }

    for(int i = 0; i < N2; i++) {
        cin >> child2[i];
    }

    for(int i = 0; i < N2; i++) {
        cin >> key2[i];
    }
    
    int tree1[N1][2];
    int tree2[N2][2];
    for(int i = 0; i < N1; i++)
        tree1[i][0] = tree1[i][1] = -1;

    for(int i = 0; i < N2; i++)
        tree2[i][0] = tree2[i][1] = -1;

    int r1 = -1;
    for(int i = 0; i < N1; i++) {
        if(parent1[i] == -1)
            r1 = i;
        else{
            if(child1[i] == 0) {
                tree1[parent1[i]][0] = i;
            }
            else if(child1[i] == 1) {
                tree1[parent1[i]][1] = i;
            }
        }
    }

    int r2 = -1;
    for(int i = 0; i < N2; i++) {
        if(parent2[i] == -1)
            r2 = i;
        else{
            if(child2[i] == 0) {
                tree2[parent2[i]][0] = i;
            }
            else if(child2[i] == 1) {
                tree2[parent2[i]][1] = i;
            }
        }
    }
    
    Node* root1 = buildTree(r1, key1, tree1);
    Node* root2 = buildTree(r2, key2, tree2);
    vector<int> list;
    
    Node* root = mergeTwoBSTs(root1, root2);
    
    Height* height = new Height();
    
    if(isBalanced(root, height)) {
        vector<int> list;
        inOrderTraversal(root, list);
        for (auto it = list.begin(); it != list.end(); it++) 
            fout << *it << "\n"; 
    }
    else {
        fout << "Returned tree is not height balanced\n";
    }
    
    return 0;
}


