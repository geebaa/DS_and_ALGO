#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};
 
void printPreOrder(TreeNode* tr) {
    if(tr == NULL) {
        cout << "#";
        return;
    }
    cout << tr->value;
    printPreOrder(tr->left);
    printPreOrder(tr->right);
}

/*
 * Complete the 'constructBinaryTree' function below.
 *
 * The function accepts INTEGER_ARRAY inorder and preorder as parameter and return Root pointer of constructed binary tree.
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int value;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : value(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* helper(unordered_map<int,int> & inorder_map,int in_s,int in_e,vector<int> &preorder,int pre_s,int pre_e)
{
    TreeNode *node;
    int root_i=0;
    int num_left=0,num_right=0;
    //base case when pre_order pointers cross
    if(pre_s > pre_e){
        return NULL;
    } 
    
    //recursive case
    node = new TreeNode(preorder[pre_s]);
    // find the index of preorder[pre_s] in inorder using inorder_map
    root_i = inorder_map[preorder[pre_s]];
    num_left = root_i - in_s;
    num_right = in_e - root_i;
    // now get the left node and right node constructed

    node->left  = helper(inorder_map,in_s,in_s+num_left,preorder,pre_s+1,pre_s+num_left);
    node->right = helper(inorder_map,root_i+1,in_e,preorder,pre_s+1+num_left,pre_e);

    return node;
}

TreeNode* constructBinaryTree(vector<int> inorder, vector<int> preorder) {
    // Write your code here
    TreeNode *result;
    int n=inorder.size();

    //convert inorder vector to a map for o(1) access
    unordered_map<int,int> inorder_map;
    for(int i=0;i<n;i++){
        inorder_map[inorder[i]]=i;
    }
    result = helper(inorder_map,0,n-1,preorder,0,n-1);
    return result;    
}

int main() {

    string temp_arr_len;
    getline(cin, temp_arr_len);

    int arr_len = stoi(ltrim(rtrim(temp_arr_len)));

    vector<int> inorder(arr_len);
    vector<int> preorder(arr_len);

    for (int i = 0; i < arr_len; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        inorder[i] = arr_item;
    }
    
    getline(cin, temp_arr_len);
    arr_len = stoi(ltrim(rtrim(temp_arr_len)));
    
    for (int i = 0; i < arr_len; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        preorder[i] = arr_item;
    }

    TreeNode *root = constructBinaryTree(inorder, preorder);
    
    printPreOrder(root);
    cout << endl;
    return 0;
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


