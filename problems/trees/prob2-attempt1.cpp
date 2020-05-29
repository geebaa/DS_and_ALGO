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

void helper(TreeNode *node,int &curr_node_num,int &pred_node_val,bool &is_bst)
{
    bool l_is_bst,r_is_bst;
    //base case : 
    if(node == NULL){
        return ;
    }

    // intermediate node

    
    helper(node->left_ptr,curr_node_num,pred_node_val,is_bst);
    curr_node_num = curr_node_num + 1;
    if(curr_node_num == 1){
        pred_node_val = node->val;
    } else {
        if(pred_node_val > node->val){
            is_bst = false; 
            return ;
        }else{
            pred_node_val = node->val;
        }
    }
    helper(node->right_ptr,curr_node_num,pred_node_val,is_bst);

}
/*
    class TreeNode{
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;
    };
*/
/*
    Complete the function below
*/
bool isBST(TreeNode* root){
    bool is_bst=true;
    int curr_node_num=0,pred_node_val=0;
    if(root == NULL){
        return true;
    } else {
        helper(root,curr_node_num,pred_node_val,is_bst);
    }
    return is_bst;
}


int main(){
    TreeNode* root = readBinaryTree();
    bool result = isBST(root);
    if(result == true){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}



