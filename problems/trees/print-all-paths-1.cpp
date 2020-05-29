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

void printPaths(vector<vector<int> > allPaths) {
    int pathCount = allPaths.size();
    if(pathCount == 0){
        return;
    }
    for(int i=0;i<pathCount;i++){
        vector<int> currentPathValues = allPaths[i];
        for(int j=0;j<currentPathValues.size();j++){
            if(j>0) cout<<" ";
            cout<<currentPathValues[j];
        }
        cout<<endl;
    }
}

/*
    class TreeNode{
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;
    };
*/
void dfs(TreeNode* node,vector<vector<int> > &result,vector<int> &path)
{
    //base case - Leaf node
    // construct a full path with node's val in "path"
    // push path that into result and cleanup by a pop
    if(node->left_ptr == NULL && node->right_ptr == NULL){
        path.push_back(node->val);
        result.push_back(path);
        path.pop_back();
        return;
    }

    // recursive case
    // keep accumulating node->val in path until 
    // leaf node is reached above
    
    path.push_back(node->val);
    if(node->left_ptr){
        dfs(node->left_ptr,result,path);
    }
    if(node->right_ptr){
        dfs(node->right_ptr,result,path);
    }
    path.pop_back();
    


}
/*
    Complete the function below
    Input: root of the input tree
    Output: A list of integer lists denoting the node values of the paths of the tree
*/
vector<vector<int> > allPathsOfABinaryTree(TreeNode* root){
    vector<vector<int> > result;
    vector<int> path;
    dfs(root,result,path);
    return result;
}


int main(){
    TreeNode* root = readBinaryTree();
    vector<vector<int> > result = allPathsOfABinaryTree(root);
    printPaths(result);
    return 0;
}


