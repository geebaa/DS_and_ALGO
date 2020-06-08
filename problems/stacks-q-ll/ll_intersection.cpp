#include <bits/stdc++.h>

using namespace std;
class LinkedListNode {
public:
    int val;
    LinkedListNode *next;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
    if(head == NULL) {
        head = new LinkedListNode(val);
        tail = head;
    }
    else {
        LinkedListNode *node = new LinkedListNode(val);
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
int find_intersection(LinkedListNode* l1, LinkedListNode* l2) {

    /*
    */

    LinkedListNode *curr1=l1,*curr2=l2;
    unordered_set<LinkedListNode *>node_ptr_set;
        
    while(curr1 && curr2){
        if(curr1 == curr2){
            return curr1->val;
        }
        // has curr1 been seen already
        if(node_ptr_set.find(curr1) != node_ptr_set.end()){
            return curr1->val;
        }
        node_ptr_set.insert(curr1);
        // has curr2 been seen already
        if(node_ptr_set.find(curr2) != node_ptr_set.end()){
            return curr2->val;
        }
        node_ptr_set.insert(curr2);
        curr1=curr1->next;
        curr2=curr2->next;
    }

    // itrerate thru remaining elements of l1 
    while(curr1){
        // has curr1 been seen already
        if(node_ptr_set.find(curr1) != node_ptr_set.end()){
            return curr1->val;
        }
        curr1=curr1->next;
    }
    // itrerate thru remaining elements of l2 
    while(curr2){
        // has curr1 been seen already
        if(node_ptr_set.find(curr2) != node_ptr_set.end()){
            return curr2->val;
        }
        curr2=curr2->next;
    }

    return -1;
}


int main()
{
    ostream &fout = cout;

    int res;
    int l1_size = 0;

    LinkedListNode* l1 = NULL;
    LinkedListNode* l1_tail = NULL;

    cin >> l1_size;

    for(int i = 0; i < l1_size; i++) {
        int l1_item;
        cin >> l1_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        l1_tail = _insert_node_into_singlylinkedlist(l1, l1_tail, l1_item);

        if(i == 0) {
            l1 = l1_tail;
        }
    }


    int l2_size = 0;

    LinkedListNode* l2 = NULL;
    LinkedListNode* l2_tail = NULL;

    cin >> l2_size;

    for(int i = 0; i < l2_size; i++) {
        int l2_item;
        cin >> l2_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        l2_tail = _insert_node_into_singlylinkedlist(l2, l2_tail, l2_item);

        if(i == 0) {
            l2 = l2_tail;
        }
    }

    //----added manually----
    int merge_at;
    cin >> merge_at;
    LinkedListNode* l1_temp = l1;
    for (int i = 0; i < merge_at; i++)
    {
        l1_temp = l1_temp->next;        
    }
    if (l2_tail == NULL)
    {
        l2 = l1_temp;
    }
    else
    {
        l2_tail->next = l1_temp;     
    }
    //--------
    
    res = find_intersection(l1, l2);
    fout << res << endl;

    
    return 0;
}


