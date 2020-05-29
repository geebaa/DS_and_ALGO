#include <bits/stdc++.h>

using namespace std;

struct TreeNode 
{ 
    int data; 
    struct TreeNode* left, *right; 
};

/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct TreeNode* newNode(int data) 
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node); 
} 

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
struct TreeNode* build_tree(int, int, vector<vector<int>> &);
bool is_mirror_image(struct TreeNode*, struct TreeNode*, ostream &);
void print_level_order(int n, struct TreeNode* root, ostream &);

/*
* Complete the 'mirror_image' function below.
*
* The function accepts root node of binary tree as parameter.
*
* Structure of TreeNode will be:
* struct TreeNode
* {
*    int data;
*    struct TreeNode* left, *right;
* };
*/

void helper(struct TreeNode* &node){

    // base case
    if(node == NULL){
        return ;
    }

    // recursive case

    helper(node->left);
    helper(node->right);

    // swap the left & right
    TreeNode *tmp=node->left;
    node->left = node->right;
    node->right = tmp;

    return;
}

void mirror_image(struct TreeNode* root) 
{
    // Write your code here

    helper(root);
}



int main()
{
    string vertices;
    getline(cin, vertices);

    int n = stoi(ltrim(rtrim(vertices)));
    
    string root_index_str;
    getline(cin, root_index_str);
    
    int root_index = stoi(ltrim(rtrim(root_index_str)));
    
    vector<vector<int>> edges(n);

    for (int i = 0; i < n; i++) {
        edges[i].resize(3);

        string edge;
        getline(cin, edge);

        vector<string> end_points = split(rtrim(edge));

        for (int j = 0; j < 3; j++) {
            int v = stoi(end_points[j]);
            edges[i][j] = v;
        }
    }

    ostream &fout = cout;
    
    struct TreeNode* root;
    root = build_tree(n, root_index, edges);
    struct TreeNode* mirror_root;
    mirror_root = build_tree(n, root_index, edges);
    
    mirror_image(mirror_root);
    
    if(!is_mirror_image(root, mirror_root, fout)) {
        fout<< "Not a mirror image" << "\n";
    }
    
    print_level_order(n, mirror_root, fout);

    return 0;
}

struct TreeNode* build_tree(int n, int root_index, vector<vector<int>> &edges){
    if(n==0) {
        return NULL;
    }
    vector<TreeNode*> nodes;
    for(int i=0;i<n;i++) {
        nodes.push_back(NULL);
    }
    nodes[root_index] = newNode(root_index);
    for(int i=0;i<n;i++) {
        vector<int> edge = edges[i];
        int vertex = edge[0];
        int left = edge[1];
        int right = edge[2];
        struct TreeNode* cur_node;
        cur_node = nodes[vertex];

        if(cur_node==NULL) {
            cur_node = newNode(vertex);
        }
        if(left!=-1) {
            if(nodes[left]==NULL){
                nodes[left] = newNode(left);
            }
            cur_node->left = nodes[left];
        }
        if(right!=-1) {
            if(nodes[right]==NULL){
                nodes[right] = newNode(right);
            }
            cur_node->right = nodes[right];
        }
        nodes[vertex] = cur_node;
    }
    return nodes[root_index];
}
    
bool is_mirror_image(struct TreeNode* root, struct TreeNode* mirror_root, ostream &fout){
    if(root==NULL && mirror_root==NULL) {
        return true;
    }
    if(root==NULL || mirror_root==NULL) {
        fout<<"Returned tree is not properly mirrored. In mirror tree returned by you, at one place, instead of ";
        if(root==NULL){
            fout<<"null node we found other node with data "<<mirror_root->data<<".\n";
        }
        if(mirror_root==NULL){
            fout<<"node with data "<<root->data<<" we found null node.\n";
        }
        return false;
    }
    if(root->data!=mirror_root->data) {
        fout<<"Returned tree is not properly mirrored. In mirror tree returned by you, at one place, mirror tree node data "<<mirror_root->data<<" is not matching with expected data "<<root->data<<".\n";
        return false;
    }
    bool left_result = is_mirror_image(root->left, mirror_root->right, fout);
    bool right_result = is_mirror_image(root->right, mirror_root->left, fout);
    
    return left_result && right_result;
}
   
void print_level_order(int n, struct TreeNode* root, ostream &fout){
    if(root==NULL) {
        return;
    }
    unordered_set<TreeNode*> visited;
    queue<TreeNode*> trace_queue; 
    trace_queue.push(root);

    visited.insert(root);

    int left_data, right_data;
    
    while(!trace_queue.empty()) {
        TreeNode* cur_node = trace_queue.front(); 
        trace_queue.pop();

        left_data = -1;
        right_data = -1;

        if(cur_node->left!=NULL) {
            if(visited.find(cur_node->left) == visited.end()){
                trace_queue.push(cur_node->left);
                visited.insert(cur_node->left);
            }
            left_data = cur_node->left->data;
        }
        if(cur_node->right!=NULL) {
            if(visited.find(cur_node->right) == visited.end()){
                trace_queue.push(cur_node->right);
                visited.insert(cur_node->right);
            }
            right_data = cur_node->right->data;
        }
        fout<< cur_node->data<<" "<<left_data<<" "<<right_data<<"\n";
    }
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


