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

void printArray(vector<int>result){
    for(int i=0;i<result.size();i++){
        if(i>0) cout<<" ";
        cout<<result[i];
    }
    cout<<endl;
}

/*
    class TreeNode{
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;
    };
*/
void helper(TreeNode* node,vector<int> &result){

    stack<pair<TreeNode*,int>> s;

    pair<TreeNode*,int> stack_elem = make_pair(node,0);

    s.push(stack_elem);

    while(!s.empty()){

        pair<TreeNode*,int> stack_top = s.top() ;
        s.pop();
        // stack_top.first null
        if(stack_top.first == NULL){
            continue;
        }
        // 
        // Stack s doubles up as a state machine
        // for each element , the first time it is pushed 
        // the value of the "second" is 0. Everytime an element is
        // popped , it is processed if it has a non-zero "second"
        // if "second" is zero , it is pushed back in with a nonzero
        // in this example the non-zero value chosen is "2" indicating
        // left and right children
        // value along with its children. This enables 
        // popping it again and processing it 
        // 
        // 
        if(stack_top.second == 0){
            stack_top.second = 2; // for left and right
            s.push(stack_top);
            // right child
            pair<TreeNode*,int> r_child = make_pair(stack_top.first->right_ptr,0);
            s.push(r_child);
            // left child
            pair<TreeNode*,int> l_child = make_pair(stack_top.first->left_ptr,0);
            s.push(l_child);
        }else{
            // permanently take the element off stack 
            // and collect in the result bag
            //cout << " " << stack_top.first->val << endl;
            result.push_back(stack_top.first->val);
        }
    }
}

/*
    Complete the function below
*/
// uncomment if complicated method above is needed
//vector<int> postorderTraversal(TreeNode* root){
//    vector<int> result;
//    helper(root,result);
//    return result;    
//}

/*Another easy way is to get the reverse of postorder and then reverse that */
void dfs_rev_postorder_iterative(TreeNode *root,vector<int> &result)
{
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *node=s.top();
        s.pop();
        result.push_back(node->val);
        // left has to go in first since ww want to process reverse of post_order (root,root->right,root->left) 
        if(node->left_ptr){
            s.push(node->left_ptr);
        }
        if(node->right_ptr){
            s.push(node->right_ptr);
        }

    }
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if(!root){
        return {};
    }
    dfs_rev_postorder_iterative(root,result);
    reverse(result.begin(),result.end());
    return result;
}


int main(){
    TreeNode* root = readBinaryTree();
    vector<int> result = postorderTraversal(root);
    printArray(result);
    return 0;
}


