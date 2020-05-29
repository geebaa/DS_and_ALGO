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

bool helper(TreeNode *node,int &unival_count)
{
    bool l_is_unival,r_is_unival;
    l_is_unival=true;
    r_is_unival=true;
    int l_val=0;
    int r_val=0;
    //base case Leaf Node 
    if( (node->left_ptr == NULL )&& (node->right_ptr == NULL ) )
    {
        unival_count = unival_count + 1;
        // leaf node
        return true;
    }

    // non leaf node
    if(node->left_ptr) {
        l_val=node->left_ptr->val;
        l_is_unival = helper(node->left_ptr,unival_count);
    }
    if(node->right_ptr) {
        r_val=node->right_ptr->val;
        r_is_unival = helper(node->right_ptr,unival_count);
    }
    if(node->left_ptr && node->right_ptr) {
        if(l_is_unival && r_is_unival) {
            if((l_val == node->val) && (r_val == node->val )){
                unival_count = unival_count + 1;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else if(node->left_ptr) {
        if(l_is_unival) {
            if(l_val == node->val){
                unival_count = unival_count + 1;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else if(node->right_ptr){
        if(r_is_unival) {
            if(r_val == node->val){
                unival_count = unival_count + 1;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    return false;
}

/*
    Complete the function below
*/
int findSingleValueTrees(TreeNode* root){
    int unival_count=0;
    if(root == NULL){
        return 0;
    }
    helper(root,unival_count);
    return unival_count;
}

int main(){
    TreeNode* root = readBinaryTree();
    int result = findSingleValueTrees(root);
    cout<<result<<endl;
    return 0;
}

