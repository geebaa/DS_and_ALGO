#include<bits/stdc++.h>
using namespace std;

typedef struct _SLL {
    int val;
    struct _SLL *next;
} SLL;

SLL *add_elem(SLL *head,int elem_val){
    SLL *new_elem=new(SLL);
    new_elem->val=elem_val;
    new_elem->next = head;
    return new_elem;
}

void print_list(SLL *head){
    while(head){
        cout << " " << head->val;
        head=head->next;
    }
    cout << endl;
}

// another method is to use fast and slow pointers
// one pointer moves one step and the other pointer
// moves 2 steps at a time
bool is_looped_2(SLL *head){
    SLL *slow=head,*fast=head;
    while(fast && fast->next){
        slow = slow->next;
        fast=fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}
// use a unordered set to record the visited pointers and 
// if visited already then the list is looped

bool is_looped_1(SLL *head){
    unordered_set<SLL *> visited;
    while(head){
        if(visited.find(head) != visited.end()){
            // loop identified and also loop start is head
            return true;
        }else{
            //add to visitor and move forward
            visited.insert(head);
            head=head->next;
        }
    }
    return false;
}

SLL *find_loop_start(SLL *head){
    unordered_set<SLL *> visited;
    while(head){
        if(visited.find(head) != visited.end()){
            // loop identified and also loop start is head
            return head;
        }else{
            //add to visitor and move forward
            visited.insert(head);
            head=head->next;
        }
    }
    return NULL;
}
int main()
{
    SLL *head=NULL;
    SLL *tail,*loop_start;
    int val=0;
    head=add_elem(head,1);
    tail=head; // store the tail
         
#if 0
    // single element loop. 
    // change to #if 1 for that test case
    tail->next=head;
#else
    head=add_elem(head,2);        
    head=add_elem(head,3);        
    head=add_elem(head,4);        
    head=add_elem(head,5);        
    head=add_elem(head,6);        
    head=add_elem(head,7);        
    tail->next=head;
    head=add_elem(head,8);        
    head=add_elem(head,9);        
    head=add_elem(head,10);        
    head=add_elem(head,11);        
    head=add_elem(head,12);        
#endif    
    //print_list(head);
    cout << " Is Looped 1 : " << is_looped_1(head) << endl;
    cout << " Is Looped 2 : " << is_looped_2(head) << endl;
    loop_start=find_loop_start(head);
    val=(loop_start==NULL)?0:loop_start->val;
    cout << " Loop Start : " << loop_start << " Value : " << val << endl;
    return 0;
}

