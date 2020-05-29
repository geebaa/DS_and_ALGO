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

BinaryTree readBinaryTree(){
    BinaryTree input_binary_tree;
    input_binary_tree.readRawValues();
    input_binary_tree.buildFromRawValues();
    return input_binary_tree;
}

/*
    class TreeNode{
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;
    };
*/

/*
    Complete the below functions
*/
class BTIterator{
public:
    stack<TreeNode *> s;
    BTIterator(TreeNode *root){
        // initialize here
        // push to all the left pointers and wait there as 
        // a recursion stack of inorder traversal would unwind

        while(root){
            //cout << " push : " << root->val << endl;
            s.push(root);
            root=root->left_ptr;
        }
    }

    bool hasNext(){
       //cout << " hasNext is : " << (!s.empty()) << endl;
       return !s.empty(); 
    }

    int next(){
        TreeNode *elem = s.top();
        s.pop();
        int val = elem->val; 
        elem = elem->right_ptr;     

        // everytime a recursion stack for inorder unwinds
        // it would push all the left elements of the node's 
        // right child
        while(elem){
            //cout << " push : " << elem->val << endl;
            s.push(elem);
            elem=elem->left_ptr;
        }
        //cout << " val : " << val << endl;
        return val;
    }
};

void printIterator(TreeNode *root, int noOfNodes){
    BTIterator iterator = BTIterator(root);
    int isFirst = 1;
    while(iterator.hasNext() && noOfNodes >= 0){
        if(!isFirst){
            cout<<" ";
        }
        cout<<iterator.next();
        isFirst = 0;
        noOfNodes--;
    }
    if(noOfNodes < 0){
        cerr<<"POSSIBLY INFINITE LOOP"<<endl;
    }
    cout<<endl;
}

int main(){
    BinaryTree inputTree = readBinaryTree();
    printIterator(inputTree.root, inputTree.noOfNodes);
    return 0;
}


