#include <bits/stdc++.h>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left_ptr;
    TreeNode* right_ptr;

    TreeNode(int _val){
        val = _val;
        left_ptr = NULL;
        right_ptr = NULL;
    }
};

class BinaryTree{
public:
    class Edge{
    public:
        int parentNodeIndex;
        int childNodeIndex;
        string leftRightFlag;

        Edge(){}

        Edge(int _parentNodeIndex, int _childNodeIndex, string _leftRightFlag){
            parentNodeIndex = _parentNodeIndex;
            childNodeIndex = _childNodeIndex;
            leftRightFlag = _leftRightFlag;
        }
    };

    int noOfNodes;
    vector<int> nodeValues;
    int rootIndex;
    int noOfEdges;
    vector<Edge> edges;
    TreeNode* root;

    BinaryTree(){
        noOfNodes = 0;
        nodeValues.clear();
        rootIndex = -1;
        noOfEdges = 0;
        edges.clear();

        root = NULL;
    }

    void readRawValues(){
        cin >> noOfNodes;
        nodeValues.assign(noOfNodes, 0);
        for(int i = 0; i < noOfNodes; i++){
            cin >> nodeValues[i];
        }

        cin >> rootIndex;

        Edge tempEdge;
        cin >> noOfEdges;
        edges.assign(noOfEdges, tempEdge);
        for(int i = 0; i < noOfEdges; i++){
            cin >> edges[i].parentNodeIndex
                >> edges[i].childNodeIndex 
                >> edges[i].leftRightFlag;
        }
    }

    void buildFromRawValues(){
        if(noOfNodes == 0){
            root = NULL;
            return;
        }

        vector<TreeNode*> nodes(noOfNodes);
        for(int i = 0; i < noOfNodes; i++){
            nodes[i] = new TreeNode(nodeValues[i]);
        }

        for(int i = 0; i < noOfEdges; i++){
            if(edges[i].leftRightFlag == "L"){
                nodes[edges[i].parentNodeIndex]->left_ptr = nodes[edges[i].childNodeIndex];
            }else{
                nodes[edges[i].parentNodeIndex]->right_ptr = nodes[edges[i].childNodeIndex];
            }
        }

        root = nodes[rootIndex];
        return;
    }
};


TreeNode* readBinaryTree(){
    BinaryTree input_binary_tree;
    input_binary_tree.readRawValues();
    input_binary_tree.buildFromRawValues();
    return input_binary_tree.root;
}

/*
    class TreeNode{
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;
    };
*/

bool helper(TreeNode* node,int &global_unival_count)
{
    // base case - leaf node
    // very leaf node is a unival tree
    if(node->left_ptr == NULL && node->right_ptr == NULL){
        global_unival_count++;
        return true;
    }

    // recursive case
    
    bool is_left_unival=false,is_right_unival=false;
    int left_val,right_val;

    if(node->left_ptr) {
        is_left_unival = helper(node->left_ptr,global_unival_count);
        left_val = node->left_ptr->val;
    }else{
        // to take care of nodes with left NULL.
        // Pretend as if they are unival and also 
        // update the left_value
        is_left_unival = true;
        left_val = node->val;
    }
    if(node->right_ptr) {
        is_right_unival = helper(node->right_ptr,global_unival_count);
        right_val = node->right_ptr->val;
    }else{
        // to take care of nodes with right NULL.
        // Pretend as if they are unival and also 
        // update the right_value
        is_right_unival = true;
        right_val = node->val;
    }

    if(is_right_unival && is_left_unival){
        if(node->val == left_val && node->val == right_val){
            global_unival_count++;
            return true;
        }
    }
    return false;
}

/*
    Complete the function below
*/
int findSingleValueTrees(TreeNode* root){
    int global_unival_count=0;
    if(root == NULL){
        return 0;
    }
    helper(root,global_unival_count);
    return global_unival_count;
}

int main(){
    TreeNode* root = readBinaryTree();
    int result = findSingleValueTrees(root);
    cout<<result<<endl;
    return 0;
}


