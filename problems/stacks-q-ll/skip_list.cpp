#include <bits/stdc++.h>

using namespace std;

// Declaration of skip list structure
class SkipList{
private :
    typedef struct _Node{
        int val;
        struct _Node *next;
    } Node;
    Node *head;
public:
    // constructor
    // It accepts an integer value
    SkipList(int numberOfQueries){
        head = NULL;
    }

    // A function to insert a new node into the skip list
    // It accepts an integer value
    // It returns nothing
    void insert(int val){
        if(head == NULL){
            //first node
            Node *new_node=new Node;
            new_node->val=val;
            new_node->next=NULL;
            head=new_node;
        }else {
            // insert in increasing order
            Node *curr=head,*prev=NULL;
            while(curr && (curr->val < val)){
                prev=curr;
                curr=curr->next;
            }
            if(prev == NULL){
                //check for duplicate
                if(val == curr->val){
                    //nothing to do
                    return;
                }
                Node *new_node=new Node;
                new_node->val=val;
                new_node->next=head;
                head=new_node;
            }else{
                // insert between prev and curr
                Node *new_node=new Node;
                new_node->val=val;
                new_node->next=prev->next;
                prev->next=new_node;
            }
        }
    }

    // A function to search node in the skip list
    // It accepts an integer value
    // It returns a boolean value
    bool isPresent(int val){
        Node *curr=head;
        while(curr ){
            if(val == curr->val){
                return true;
            }
            curr=curr->next;
        }
        return false;
    }

    // A function to renove node from the skip list
    // It accepts an integer value
    // It returns nothing
    void remove(int val){
        Node *curr=head,*prev=NULL;
        while(curr && (val != curr->val)){
            curr=curr->next;
        }
        if(curr != NULL){
            if(prev==NULL){
                //remove first element
                head=head->next;
                delete curr;
            }else{
                prev->next=curr->next;
                delete curr;
            }
        }

    }
};


int main(){
    int numberOfQueries;
    cin>>numberOfQueries;
    SkipList skipList = SkipList(numberOfQueries);
    for(int i = 0; i < numberOfQueries; i++){
        string instruction;
        int val;
        cin>>instruction>>val;
        if(instruction == "insert"){
            skipList.insert(val);
        } else if(instruction == "search"){
            if(skipList.isPresent(val)){
                cout<<1<<endl;
            } else {
                cout<<0<<endl;
            }
        } else {
            skipList.remove(val);
        }
    }
    return 0;
}


