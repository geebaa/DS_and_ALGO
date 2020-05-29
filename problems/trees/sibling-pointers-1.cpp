#include <bits/stdc++.h>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left_ptr;
    TreeNode* right_ptr;
    TreeNode *next_right;

    TreeNode(int _val){
        val = _val;
        left_ptr = NULL;
        right_ptr = NULL;
        next_right = NULL;
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
    vector<TreeNode*> nextRightNodes;
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
        nextRightNodes.clear();

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

    void considerEdge(
        string lOrR, TreeNode* parent, TreeNode* child, 
        unordered_map<TreeNode*, int>& nodeToId, int& id, bool& edge_creates_cycle
    ){
        if (child){
            if (nodeToId.find(child) == nodeToId.end()){
                nodeToId[child] = id++;
                nodeValues.push_back(child->val);
                nextRightNodes.push_back(child->next_right);
            }else{
                edge_creates_cycle = true;
                cerr << "Cycle detected in the tree. Cycle contains the edge: " 
                     << nodeToId[parent] << " " << nodeToId[child] 
                     << " " << lOrR << endl;
            }
            edges.push_back(Edge(nodeToId[parent], nodeToId[child], lOrR));
        }
    }

    void getNodeValuesAndEdges(
        TreeNode* root, unordered_map<TreeNode*, int>& nodeToId, int& id
    ){
        if(root == NULL){
            return;
        }

        bool left_edge_creates_cycle = false;
        bool right_edge_creates_cycle = false;

        considerEdge(
            "L", root, root->left_ptr, 
            nodeToId, id, left_edge_creates_cycle
        );
        considerEdge(
            "R", root, root->right_ptr,
            nodeToId, id, right_edge_creates_cycle
        );

        if (left_edge_creates_cycle == false){
            getNodeValuesAndEdges(root->left_ptr, nodeToId, id);
        }
        if (right_edge_creates_cycle == false){
            getNodeValuesAndEdges(root->right_ptr, nodeToId, id);
        }
    }

    void populateRawValuesFromTree(){
        noOfNodes = 0;
        nodeValues.clear();
        rootIndex = -1;
        noOfEdges = 0;
        edges.clear();

        if (root != NULL){
            int id = 0;
            unordered_map<TreeNode*, int> nodeToId;

            rootIndex = id;  // That is 0.
            nodeToId[root] = id++;
            nodeValues.push_back(root->val);
            nextRightNodes.push_back(root->next_right);

            getNodeValuesAndEdges(root, nodeToId, id);
            noOfNodes = nodeValues.size();
            noOfEdges = edges.size();
        }
    }

    void writeRawValues(){
        cout << noOfNodes << endl;
        for(int i = 0; i < noOfNodes; i++){
            if(i){
                cout << " ";
            }
            cout << nodeValues[i];
        }
        if (noOfNodes > 0){
            cout << endl;
        }

        for(int i = 0; i < noOfNodes; i++){
            if(i){
                cout << " ";
            }
            if(nextRightNodes[i] == NULL){
                cout<<"null";
            } else {
                cout<<nextRightNodes[i]->val;
            }
        }

        if (noOfNodes > 0){
            cout << endl;
        }

        cout << rootIndex << endl;

        cout << noOfEdges << endl;
        for(int i = 0; i < noOfEdges; i++){
            cout << edges[i].parentNodeIndex 
                 << " " << edges[i].childNodeIndex
                 << " " << edges[i].leftRightFlag
                 << endl;
        }
    }
};

TreeNode* readBinaryTree(){
    BinaryTree input_binary_tree;
    input_binary_tree.readRawValues();
    input_binary_tree.buildFromRawValues();
    return input_binary_tree.root;
}

void printBinaryTree(TreeNode* root){
    BinaryTree output_binary_tree;
    output_binary_tree.root = root;
    output_binary_tree.populateRawValuesFromTree();
    output_binary_tree.writeRawValues();
}

/*
    class TreeNode{
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;
        TreeNode* next_right;
    };
*/

void helper(TreeNode* node){

    queue<TreeNode*> q;
    q.push(node);

    while(!q.empty()){
        int n = q.size();
        TreeNode *prev=NULL;
        TreeNode *curr=NULL;
        // process of a level in the tree
        for(int i=0;i<n;i++){
            curr = q.front();
            q.pop();
            if(prev){
                prev->next_right = curr;
            }
            prev=curr;

            // push the next level of the current node
            if(curr->left_ptr){
                q.push(curr->left_ptr);
            }
            if(curr->right_ptr){
                q.push(curr->right_ptr);
            }
        }
    }
}
/*
    Complete the function below
*/
TreeNode* populateSiblingPointers(TreeNode* root){
    if(root == NULL){
        return root;
    }
    helper(root); 
    return root;
}



int main(){
    TreeNode* root = readBinaryTree();
    TreeNode* result = populateSiblingPointers(root);
    printBinaryTree(result);
    return 0;
}

