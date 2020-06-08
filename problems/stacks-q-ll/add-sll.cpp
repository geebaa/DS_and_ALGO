#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
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

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* addTwoNumbers(SinglyLinkedListNode* l_a, SinglyLinkedListNode* l_b) {
    SinglyLinkedListNode *result=NULL,*curr=NULL;
    int carry=0; // start with 0 as carry
    SinglyLinkedListNode *digit1_ptr=l_a,*digit2_ptr=l_b; 
    SinglyLinkedListNode *new_node;    
    while(digit1_ptr && digit2_ptr){
        int digit3 = (digit1_ptr->data + digit2_ptr->data + carry)%10;
        carry = (digit1_ptr->data + digit2_ptr->data + carry)/10;
 
        if(result==NULL){
            //first node
            new_node=new SinglyLinkedListNode(digit3);
            new_node->next=NULL;
            curr= new_node;
            result=curr;
        }else{
            new_node=new SinglyLinkedListNode(digit3);
            new_node->next=NULL;
            curr->next= new_node;
            curr=curr->next;
        }
        // move ahead to next digit
        digit1_ptr = digit1_ptr->next;
        digit2_ptr = digit2_ptr->next;
    }

    while(digit1_ptr){
        int digit3 = (digit1_ptr->data + carry)%10;
        carry = (digit1_ptr->data + carry)/10;
        if(result==NULL){
            //first node
            new_node=new SinglyLinkedListNode(digit3);
            new_node->next=NULL;
            curr= new_node;
            result=curr;
        }else{
            new_node=new SinglyLinkedListNode(digit3);
            new_node->next=NULL;
            curr->next= new_node;
            curr=curr->next;
        }
        // move ahead to next digit
        digit1_ptr = digit1_ptr->next;
    }

    while(digit2_ptr){
        int digit3 = (digit2_ptr->data + carry)%10;
        carry = (digit2_ptr->data + carry)/10;
        if(result==NULL){
            //first node
            new_node=new SinglyLinkedListNode(digit3);
            new_node->next=NULL;
            curr= new_node;
            result=curr;
        }else{
            new_node=new SinglyLinkedListNode(digit3);
            new_node->next=NULL;
            curr->next= new_node;
            curr=curr->next;
        }
        // move ahead to next digit
        digit2_ptr = digit2_ptr->next;
    }
    if(carry != 0){
        new_node=new SinglyLinkedListNode(carry);
        new_node->next=NULL;
        curr->next= new_node;
        curr=curr->next;
    }
    return result;
}


int main()
{
    SinglyLinkedList* l_a = new SinglyLinkedList();

    string l_a_count_temp;
    getline(cin, l_a_count_temp);

    int l_a_count = stoi(ltrim(rtrim(l_a_count_temp)));

    for (int i = 0; i < l_a_count; i++) {
        string l_a_item_temp;
        getline(cin, l_a_item_temp);

        int l_a_item = stoi(ltrim(rtrim(l_a_item_temp)));

        l_a->insert_node(l_a_item);
    }


    SinglyLinkedList* l_b = new SinglyLinkedList();

    string l_b_count_temp;
    getline(cin, l_b_count_temp);

    int l_b_count = stoi(ltrim(rtrim(l_b_count_temp)));

    for (int i = 0; i < l_b_count; i++) {
        string l_b_item_temp;
        getline(cin, l_b_item_temp);

        int l_b_item = stoi(ltrim(rtrim(l_b_item_temp)));

        l_b->insert_node(l_b_item);
    }

    ostream &fout = cout;

    SinglyLinkedListNode* result = addTwoNumbers(l_a->head, l_b->head);

    print_singly_linked_list(result, "\n", fout);
    fout << "\n";

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

