#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center)

    1
   / \
  2   2
 / \ / \
3  4 4  3

return true

    1
   / \
  2   2
   \   \
   3   3

return false
*/


#if 0
bool check_mirror(vector<pair<bool,int>> &level_elems){
    int n=level_elems.size();
    // start and end pointers
    int s=0,e=n-1;
    while(s<=e){
        pair<bool,int> s_elem=level_elems[level_elems.begin()+s];
        pair<bool,int> e_elem=level_elems[level_elems.begin()+e];
        //check for equality 
        if((s_elem.first == true) && (e_elem.first == true)){
            //valid elements at the sth and eth location
            if(s_elem.second != e_elem.second){
                return false;
            }
        }else if((s_elem.first == false) && (e_elem.first == false)){
            //do nothing gap at both ends while in that level
        }else{
            // gap at one end and element at other 
            return false;
        }
        s++;
        e--;
    }
    // survived the mirror check
    return true;    
}

bool bfs(Node *root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        // size at that level
        int n=q.size();
        vector<pair<bool,int>> level_elems;
        for(int i=0;i<n;i++){
            Node *curr = q.front();
            q.pop();

            //collect the elements in the level
            if(curr == NULL){
                level_elems.push_back(make_pair(false,0));
                continue;
            }else{
                level_elems.push_back(true,curr->val);
            }
            // push elements of next level
            // push NULL if no child so that next iteration can collect
            // dummy values 
            if(curr->left){
                q.push(curr->left);
            }else{
                q.push(NULL);
            }
            if(curr->right){
                q.push(curr->right);
            }else{
                q.push(NULL);
            }
        }
        // check for mirror of that level
        if(!check_mirror(level_elems)){
            return false;
        }
        level_elems.clear();
    }
    // all levels passed mirror check
    return true;
}
#endif

int main()
{
    return 0;
}

