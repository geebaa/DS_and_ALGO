#include <bits/stdc++.h>

using namespace std;

class LinkedListNode {
public:
    int val;
    LinkedListNode* next;
    
    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode* head, LinkedListNode* tail, int val) {
    if (!head) {
        head = new LinkedListNode(val);
        tail = head;
    } else {
        LinkedListNode* node = new LinkedListNode(val);
        tail->next = node;
        tail = tail->next;
    }
    
    return tail;
}

/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode* next;
};
*/
LinkedListNode* reverse_linked_list_in_groups_of_k(LinkedListNode* head, int k) {
    stack<LinkedListNode *> ptr_stack;
    bool first_time=true;
    LinkedListNode *curr=head;
    LinkedListNode *rev_curr=NULL;
    LinkedListNode *curr_tail=NULL;
    while(curr){
        // push k elements or until elements in list onto a stack
        cout << "Pushing : " << endl;
        for(int i=0;(i<k) && (curr);i++){
            cout << " " << curr ;
            ptr_stack.push(curr);
            curr=curr->next;
        }
        cout << endl;
        if(first_time){
            head=ptr_stack.top();
            first_time = !first_time;
        }else{
            if(!ptr_stack.empty()){
                curr_tail->next=ptr_stack.top();
            }
        }
        rev_curr=ptr_stack.top();
        rev_curr->next=NULL;
        ptr_stack.pop();
        while(!ptr_stack.empty()){
            rev_curr->next=ptr_stack.top();
            ptr_stack.pop();
            rev_curr=rev_curr->next;
            rev_curr->next=NULL;
        }
        curr_tail=rev_curr;
    }    
    return head; 
}


int main()
{
    ostream &fout = cout;

    int head_size;
    cin >> head_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;

    for (int head_i = 0; head_i < head_size; head_i++) {
        int head_item;
        cin >> head_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if (!head_i) {
            head = head_tail;
        }
    }


    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    LinkedListNode* res = reverse_linked_list_in_groups_of_k(head, k);

    while (res) {
        fout << res->val;

        if (res->next) {
            fout << "\n";
        }

        res = res->next;
    }

    fout << "\n";
    
    
    return 0;
}


