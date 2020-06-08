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

SinglyLinkedListNode* merge(SinglyLinkedListNode *l , SinglyLinkedListNode *r)
{
    // current pointer for l , r and a new head
    SinglyLinkedListNode *l_curr=l,*r_curr=r,*head=NULL,*h_curr=NULL;
    
    if(head == NULL){
        // construct the first node
        // if both lists are non-empty then head 
        // will point to the element from the list that has
        // min value of data
        if(l_curr && r_curr){
            head = (l_curr->data < r_curr->data)?l_curr:r_curr;
        }else{
            head = (r_curr==NULL)?l_curr:r_curr;
        } 
        // move the appropriate pointers
        if(head==l_curr){
            l_curr=l_curr->next;
        }else{
            r_curr=r_curr->next;
        }
        h_curr=head;
    }

    while(l_curr && r_curr){
        h_curr->next=(l_curr->data < r_curr->data)?l_curr:r_curr;
        h_curr=h_curr->next;
        // move the appropriate pointers
        if(h_curr==l_curr){
            l_curr=l_curr->next;
        }else{
            r_curr=r_curr->next;
        }
    }

    //append all remaining elements if any from l_curr
    while(l_curr){
        h_curr->next=l_curr;
        h_curr=h_curr->next;
        l_curr=l_curr->next;
    }
    //append all remaining elements if any from r_curr
    while(r_curr){
        h_curr->next=r_curr;
        h_curr=h_curr->next;
        r_curr=r_curr->next;
    }
    return head;
}

int getLength(SinglyLinkedListNode *head)
{
    int c=0;
    SinglyLinkedListNode *curr=head;
    while(curr){
        c++;
        curr=curr->next;
    }
    return c;
}

int getLength2(SinglyLinkedListNode *head)
{
    int c=0;
    SinglyLinkedListNode *s=head,*f=head;
    while(f && f->next){
        s=s->next;
        f=f->next->next;
        c++;
    }
    if(f){
        return (2*c) + 1;
    }else{
        return 2*c;
    }
}

SinglyLinkedListNode* merge_sort_helper(SinglyLinkedListNode* head,int s,int e)
{

    //base case
    if(s>e){
        return NULL;
    }
    if(s==e)
    {
        //int n=getLength(head);
        // create a new node for sth or eth element and return
        // s , e ,c are all 0 based. i.e s=0 means 1st node in the 
        // linked list
        // since this is a linked list , we need to handle s=0 as
        // a special case else it will interfere in our iteration.
        SinglyLinkedListNode*curr=head;
        if(s==0){
            return new SinglyLinkedListNode(curr->data);
            //return curr;
        }
        for(int i=0;i<s;i++){
            curr=curr->next;
        }
        return new SinglyLinkedListNode(curr->data);
        //return curr;
    }

    int m = s + (e-s)/2;
    SinglyLinkedListNode* l=merge_sort_helper(head,s,m);
    SinglyLinkedListNode* r=merge_sort_helper(head,m+1,e);
    
    return merge(l,r);
}


SinglyLinkedListNode* merge_sort(SinglyLinkedListNode* head) {

    int n=getLength2(head);
    SinglyLinkedListNode* sorted = merge_sort_helper(head,0,n-1);
    return sorted;
}

int main()
{
    ostream &fout = cout;

    SinglyLinkedList* head = new SinglyLinkedList();

    string head_count_temp;
    getline(cin, head_count_temp);

    int head_count = stoi(ltrim(rtrim(head_count_temp)));

    for (int i = 0; i < head_count; i++) {
        string head_item_temp;
        getline(cin, head_item_temp);

        int head_item = stoi(ltrim(rtrim(head_item_temp)));

        head->insert_node(head_item);
    }

    SinglyLinkedListNode* result = merge_sort(head->head);

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


