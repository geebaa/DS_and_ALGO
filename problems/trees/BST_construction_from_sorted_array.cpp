#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, MAX_VAL = 2000000000;

struct TreeNode
{
	int val;
	TreeNode* left_ptr;
	TreeNode* right_ptr;

	TreeNode(int _val = 0)
	{
		val = _val;
		left_ptr = NULL;
		right_ptr = NULL;
	}
};
/*
 * Complete the function below.
 */

/*
    For your reference. 

    struct TreeNode
    {
        int val;
        TreeNode* left_ptr;
        TreeNode* right_ptr;

        TreeNode(int _val = 0)
        {
            val = _val;
            left_ptr = NULL;
            right_ptr = NULL;
        }
    };
*/
TreeNode * helper(vector<int> &a,int s,int e)
{
    //base case
    if(s > e){
        //nothing to construct
        return NULL;
    }
    if(s == e){
        // create a single TreeNode
        return new TreeNode(a[s]);
    }

    //recursive case
    // select the middle element as root since the array
    // is sorted and create a right subtree of a[mod+1,e] 
    // create a left subtree of a[s,mid-1]
    int mid = (s + (e-s)/2 );
    TreeNode *node = new TreeNode(a[mid]);
    if(node){
        node->left_ptr =  helper(a,s,mid-1);
        node->right_ptr =  helper(a,mid+1,e);
    }
    
    return node;
}
TreeNode * build_balanced_bst(vector<int> a)
{
    TreeNode *root;
    int s,e;
    s=0;
    e=a.size()-1;
    root = helper(a,s,e);
    return root;
	
}


bool check_balanced_bst(TreeNode *root, int l, int r, vector<int>& a)
{
    if (l > r && root == NULL)                              // If no value in [l, r] and tree is also empty.
    {
        return true;
    }
    else if (l > r && root != NULL)                         // If no value in [l, r] but tree contains something. 
    {
        return false;
    }
    if (root == NULL)                                       // If some values in [l, r] but tree is empty.
    {
        return false;
    }
    
    int mid1 = l + (r - l) / 2;
    int mid2 = l + (r - l + 1) / 2;
    
    bool valid1 = (root->val == a[mid1] && check_balanced_bst(root->left_ptr, l, mid1 - 1, a) && check_balanced_bst(root->right_ptr, mid1 + 1, r, a));
    if (valid1)                                             // actually we are doing valid1 || valid2 but when valid1 is true then no need to find valid2
    {
        return true;        
    }
    if (mid1 == mid2)                                       // when odd no of elements in [l, r] then mid1 = mid2 so valid1 = valid2 and no need to find valid2.  
    {
        return false;        
    }
    return (root->val == a[mid2] && check_balanced_bst(root->left_ptr, l, mid2 - 1, a) && check_balanced_bst(root->right_ptr, mid2 + 1, r, a));  
}

int main()
{
    ostream &fout = cout;

    int a_size = 0;
    cin >> a_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> a;
    for(int i = 0; i < a_size; i++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        a.push_back(a_item);
    }

    TreeNode* root = build_balanced_bst(a);
    if (check_balanced_bst(root, 0, a_size - 1, a))
    {
        fout << "Valid Balanced BST" << endl;
    }
    else
    {
        fout << "Invalid Balanced BST" << endl;
    }

    
    return 0;
}


