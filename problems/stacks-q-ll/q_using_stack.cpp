#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = NULL;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = NULL;
            this->tail = NULL;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ostream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* implement_queue(SinglyLinkedListNode* operations) {
    /*
     * Write your code here.
     */
    
    stack<int> enq_stack,deq_stack;
    SinglyLinkedListNode *head_result=NULL,*curr_result=NULL,*curr=operations;
    while(curr){
        SinglyLinkedListNode *new_node=NULL;
        switch(curr->data){
            case -1: 
                if(!deq_stack.empty()){
                    new_node = new SinglyLinkedListNode(deq_stack.top());
                    deq_stack.pop();
                }else{
                    if(enq_stack.empty()){
                        //enq stack is also empty return -1
                        new_node = new SinglyLinkedListNode(-1);
                    }else{
                        // empty enq_stack into deq_stack and return top
                        while(!enq_stack.empty()){
                            deq_stack.push(enq_stack.top());
                            enq_stack.pop();
                        }
                        new_node = new SinglyLinkedListNode(deq_stack.top());
                        deq_stack.pop();
                    }
                }
                // newnode has the desired result from above logic
                // add it to the linkedlist head_result
                if(head_result==NULL){
                    head_result=new_node;
                    curr_result=head_result;
                }else{
                    curr_result->next=new_node;
                    curr_result=curr_result->next;
                }
                break;
            default :
                enq_stack.push(curr->data);
                break;
        }
        curr=curr->next;
    }
    return head_result; 
    

}
int main()
{
    ostream &fout = cout;

    SinglyLinkedList* operations = new SinglyLinkedList();

    int operations_count;
    cin >> operations_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int operations_itr = 0; operations_itr < operations_count; operations_itr++) {
        int operations_item;
        cin >> operations_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        operations->insert_node(operations_item);
    }

    SinglyLinkedListNode* res = implement_queue(operations->head);

    print_singly_linked_list(res, "\n", fout);
    fout << "\n";

    free_singly_linked_list(res);

    

    return 0;
}


