#include<bits/stdc++.h>
using namespace std ;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

void parse_input( vector< pair< int , int > >&edges, struct Node * arr_stub[])
{
    for(int i=0;i<edges.size();i++)
    {
        int from = edges[i].first ;
        int to = edges[i].second ;
        if( (arr_stub[from]->left) == NULL )
            arr_stub[from]->left = arr_stub[to] ;
        else
            arr_stub[from]->right = arr_stub[to] ;
    }
}
void pre_order(Node * head)
{
    if( head == NULL )
        return ;
    pre_order(head->left) ;
    pre_order(head->right);
}

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d) 
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

*/
typedef enum {RECORD_START=1,RECORD_STOP,RECORD_LOOKUP} eState;
void helper(Node *node, Node *&a, Node *&b,eState &state,unordered_set<Node *> &bag,Node *&lca)
{
    // base case
    if(node == NULL){
        return;
    }
    
    // recursive case

    // preorder processing -- if the state is RECORD start record the path
    if(state == RECORD_START){
        bag.insert(node);
    }

    helper(node->left,a,b,state,bag,lca);
    // inorder processing 
    // manipulate state and bag , if we have hit either of 
    // our desired node
    // state machine is -- start recording path in pre order , stop recording 
    // when desired node is hit inorder for first time.
    // when desired node is hit inorder second time we start lookup in post order 
    if( (node == a) || (node == b) ){
        switch(state){
            case RECORD_START :
                bag.insert(node);
                state = RECORD_STOP;
                break;
            case RECORD_STOP :
                state = RECORD_LOOKUP;
                break;
            case RECORD_LOOKUP :
                cout << " unexpected RECORD_LOOKUP : while processing inorder" << endl;
            default :
                break;
        }
    }

    helper(node->right,a,b,state,bag,lca);
    // postorder processing -- if the state is RECORD_LOOKUP start looking up
    // to find the least common ancestor
    if(state == RECORD_LOOKUP){
        if(lca == NULL){
            //update lca only if we have not previously found a lca
            if(bag.find(node) != bag.end()){
                lca = node;
            }
        }
    }
}

int lca( Node *root, Node *a, Node *b)
{
    eState state=RECORD_START;
    unordered_set<Node *> bag;
    Node *lca=NULL;
    if(root == NULL || a == NULL || b == NULL ){
        return 0;
    }
    if(a == b){
        // its the same node and hence common ancestor 
        // is the same node
        return a->data;
    }

    helper(root,a, b,state,bag,lca);
    if(lca){
        return lca->data;
    }
    return 0;
}


int main()
{
    int i , n, a, b;
    vector< pair< int , int > >edges ;
    cin >> n >> a >> b ;
    struct Node * arr_stub[100020] ;
    
    for(i=1;i<=n;i++)
        arr_stub[i] = new Node(i) ;
    for(i=1;i<n;i++)
    {
        int st,en ;
        cin >> st >> en ;
        edges.push_back(make_pair( st,en )) ;
    }
    parse_input( edges , arr_stub);
    int answer = lca( arr_stub[1] , arr_stub[a] , arr_stub[b] ) ;
    // we passed the head pointer basically which is arr_stub[1]
    cout<<answer<<endl;
    return 0;
}


