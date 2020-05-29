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

void printCircularList(TreeNode *circularListHead){
    if(circularListHead == NULL){
        printf("\n");
        return;
    }
    TreeNode *tmpHead = circularListHead;
    while(tmpHead->right_ptr != circularListHead){
        printf("%d ", tmpHead->val);
        tmpHead = tmpHead->right_ptr;
    }

    printf("%d\n", tmpHead->val);
}

/*
    class TreeNode{
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;
    };
*/

void helper(TreeNode *node , TreeNode * &pred){
        
    // base case
    if(node == NULL){
        return;
    }

    //recursive case

    // explore the left subtree
    helper(node->left_ptr,pred);

    // do inorder processing after exploring left subtree
    // chain the pred and curr node to form doubly linked list
    // update pred with node
    pred->right_ptr = node;
    node->left_ptr = pred;
    pred = node;
    // explore right subtree
    helper(node->right_ptr,pred);
}

/*
    Complete the function below
*/
TreeNode* BTtoLL(TreeNode* root){


    if(root == NULL){
        return NULL;
    }
    // Algo is to do a boundary walk
    // keep updating pred value everytime 
    // a node gets processed inorder.
    
    // This is a special node that is set to pred before launching 
    // bounday walk
    TreeNode *first=new TreeNode(INT_MIN);
    TreeNode *pred = first;

    helper(root , pred);
    // at this point pred will the last node in the 
    // inorder traversal. What remains is to
    // update the pointers 

    TreeNode *head = first->right_ptr; // head will be returned
    head->left_ptr = pred;
    pred->right_ptr = head;
 
    return head;    
}



int main(){
    TreeNode* root = readBinaryTree();
    TreeNode *result = BTtoLL(root);
    printCircularList(result);
    return 0;
}


