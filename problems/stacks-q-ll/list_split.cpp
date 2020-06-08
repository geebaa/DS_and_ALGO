#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>
#include <unordered_set>

using namespace std;

struct LinkedListNode{
    int val;
    LinkedListNode *next;

    LinkedListNode(int _val){
        val = _val;
        next = NULL;
    }
};

LinkedListNode* createLinkedList(int *inputArray, int inputSize){
    LinkedListNode *head = NULL;
    LinkedListNode *tail = NULL;
    for(int i = 0; i<inputSize; i++){
        LinkedListNode *currentNode = new LinkedListNode(inputArray[i]);
        if(head == NULL){
            head = currentNode;
            tail = head;
        } else{
            tail->next = currentNode;
            tail = tail->next;
        }
    }
    return head;
}

LinkedListNode* readInput(){
    int n; cin>>n;
    int *ar;
    ar = new int[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    return createLinkedList(ar, n);
}


vector<LinkedListNode*> alternativeSplit(LinkedListNode *head){
    /*
        basic idea is to iterate thru the original list and all odd elements go to odd_list and 
        even elements go to even list

    */    
    LinkedListNode *curr=head;
    vector<LinkedListNode *> new_list(2,NULL);
    vector<LinkedListNode *> new_list_curr(2,NULL);

    int elem=0;

    while(curr){
        if(new_list[elem&1] == NULL){
            //first element in the list
            LinkedListNode *new_elem=new LinkedListNode(curr->val);
            new_list[elem&1]=new_elem;
            new_list_curr[elem&1]=new_elem;
        }else{
            LinkedListNode *new_elem=new LinkedListNode(curr->val);
            new_list_curr[elem&1]->next=new_elem;
            new_list_curr[elem&1]=new_list_curr[elem&1]->next;
        }
        curr=curr->next;
        elem++;
    }
    return new_list;

}


void printList(LinkedListNode *head){
    int id = 0;
    while(head){
        if(id > 0) cout<<" ";
        cout<<head->val;
        head = head->next;
        id++;
    }
    cout<<endl;
}

int getArraySize(vector<LinkedListNode*> array){
    return array.size();
}

int main(){
    LinkedListNode *head = readInput();
    vector<LinkedListNode*> result = alternativeSplit(head);
    int outputArraySize = getArraySize(result);
    if(outputArraySize != 2){
        cerr<<"Output must be an array with 2 LinkedListNode"<<endl;
        return 0;
    }
    printList(result[0]);
    printList(result[1]);
    return 0;
}


