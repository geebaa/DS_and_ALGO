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
void swap(int &a,int&b)
{
    int tmp=a;
    a=b;
    b=tmp;
}

/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode* next;
};
*/

LinkedListNode* swap_nodes(LinkedListNode* head, int k) {
    
    // we will use a stack as we traverse the linked list 
    // and pop out the last few pointers to make this swap
    // suppose the elements are numbered 1 to N and 1<=K<=N
    // then the two elements to swap are K and N+1 - K
    // if these 2 elements are equal we do nothing.
    // K and N+1 - K will be equal in one case when N is odd
    // for example N=1 and K=1 
    // another example N=3 and K=2
    // another example N=5 and K=3

    int n=0;

    stack<LinkedListNode*> ptr_stack;
    LinkedListNode *curr=head; 
    // push all the pointers in the stack 
    while(curr){
        n++;
        ptr_stack.push(curr);
        curr=curr->next;
    }
    cout << " n : " << n << endl;
    int k_rev=n+1-k; // element from the reverse
    if(k == k_rev){
        return head;
    }
    // k and k_rev can be swapped to make sure k is < k_rev
    if(k>k_rev){
        swap(k,k_rev);
    }
    cout << " k : " << k << " k_rev : "<<k_rev<<endl;
    //these are the pointers needed to make the swap
    LinkedListNode *prev_k=NULL,*prev_k_rev=NULL,*curr_k,*curr_k_rev;
    curr_k=head;
    curr_k_rev=ptr_stack.top();
    ptr_stack.pop();
    for(int i=1;i<k;i++){
        // pointer from the begining
        prev_k=curr_k;
        curr_k=curr_k->next;

        //pointer from the last
        curr_k_rev=ptr_stack.top();
        ptr_stack.pop();
    }
    if(!ptr_stack.empty()){
        // one pointer before the curr_k_rev
        prev_k_rev=ptr_stack.top();
        ptr_stack.pop();
    }

    cout << "curr_k : " << curr_k << " prev_k : " << prev_k<<endl;
    cout << "curr_k_rev : " << curr_k_rev << " prev_k_rev : " << prev_k_rev<<endl;
    // we have the following pointers
    // prev_k , curr_k , prev_k_rev,curr_k_rev
    // curr_k and curr_k_rev needs to be swapped
    // prev_k and prev_k_rev are the preceeding pointers
    // if prev_k is NULL we are swapping 1st node with last node
    //  
    // prev_k_rev will be equal to curr_k when swapping 2 adjacent nodes
    
    if(prev_k_rev == curr_k){
        //swapping 2 adjacent nodes
        if(prev_k == NULL){
            // swapping 1 with 2 in a 2 node list
            head=curr_k->next;
            head->next=curr_k;
            curr_k->next=NULL;
        }else{
            // order of these swaps are important
            prev_k->next=curr_k_rev;
            curr_k->next=curr_k_rev->next;
            curr_k_rev->next=curr_k;
                        
        }
    }else{
        if(prev_k == NULL){
            // first node swapped with last node
            // set the prev pointers
            prev_k_rev->next=curr_k;
            curr_k_rev->next=curr_k->next;
            curr_k->next=NULL; // since this is the last node
            head=curr_k_rev; // reset head after swap
        }else{
            // normal case
            // set the prev pointers
            prev_k->next=curr_k_rev;
            prev_k_rev->next=curr_k;
            // swap the forward pointers for curr_k and curr_k_rev
            LinkedListNode *tmp;
            tmp=curr_k->next;
            curr_k->next=curr_k_rev->next;
            curr_k_rev->next=tmp;
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


    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    LinkedListNode* res = swap_nodes(head, k);

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

