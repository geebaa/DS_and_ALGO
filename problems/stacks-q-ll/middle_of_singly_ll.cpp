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
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
LinkedListNode* find_middle_node(LinkedListNode* head) {

    LinkedListNode *jump_single,*jump_double;

    jump_single=head;
    jump_double=head;

    while(jump_double && jump_double->next){
        jump_single=jump_single->next;
        jump_double=jump_double->next->next;
    }
    return jump_single;
}


int main()
{
    ostream &fout = cout;

    LinkedListNode* res;
    int head_size = 0;

    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;

    cin >> head_size;

    for(int i = 0; i < head_size; i++) {
        int head_item;
        cin >> head_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if(i == 0) {
            head = head_tail;
        }
    }


    res = find_middle_node(head);
    while (res != NULL) {
        fout << res->val << endl;

        res = res->next;
    }

    
    return 0;
}
