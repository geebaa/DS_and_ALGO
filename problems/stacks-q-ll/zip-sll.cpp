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
LinkedListNode *getPrevLast(LinkedListNode *node)
{
    LinkedListNode *prev=NULL,*curr=node;
    while(curr && curr->next){
        //cout << "curr : "<< curr << " prev : " <<prev<<endl;
        prev=curr;
        curr=curr->next;
    }
    return prev;
}

/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode* next;
};
*/
LinkedListNode* zip_given_linked_list(LinkedListNode* head) {
    
    LinkedListNode *curr=head,*prev_last=NULL,*last=NULL;
    /*
        brief idea is to run thru the list and at each iteration 
        fetch the last element and adjust the pointer.
        prev_last element is what we get from a function
        and derive the last pointer from that.
        important is to move the current to the next valid current
        and also set the prev_last->next to NULL to avoid loop.
    */    
    while(curr){
        //cout << " curr : " << curr << endl;
        prev_last=getPrevLast(curr);
        
        if(prev_last){
            last=prev_last->next;
            prev_last->next=NULL;
        }else{
            last=NULL;
        }

        if(last==NULL){
            // we are done zipping
            break;
        }else{
            // insert last after curr
            // move curr to the next valid curr
            // 
            LinkedListNode *tmp=curr->next;
            last->next=curr->next;
            curr->next=last;
            curr=tmp;
        }

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


    LinkedListNode* res = zip_given_linked_list(head);

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


