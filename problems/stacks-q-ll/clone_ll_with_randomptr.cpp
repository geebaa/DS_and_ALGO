#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode
{
  public:
    int data;
    SinglyLinkedListNode *next;
    SinglyLinkedListNode *randomPointer;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
        this->randomPointer = nullptr;
    }

    void link_random_node(SinglyLinkedListNode *random_node)
    {
        this->randomPointer = random_node;
    }
};

class SinglyLinkedList
{
  public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list_with_random_node(SinglyLinkedListNode *node, string sep);
bool cloneCheck(SinglyLinkedListNode *head, unordered_set<SinglyLinkedListNode *> originalNodes);


/*
 * @param head: pointer to the head node of the original linkedList
 * @returns the pointer to the newly cloned linkedList head node
 *  For your reference:
 *  class SinglyLinkedListNode
 *  {
 *      int data;
 *      SinglyLinkedListNode *next;
 *      SinglyLinkedListNode *randomPointer;
 *  }
 */
SinglyLinkedListNode *cloneLinkedList(SinglyLinkedListNode *list)
{

    /*
        General idea is to traverse the list from begining to end using
        next pointer and maintain a unordered_map of "data" to the "new pointer for data"
        before any allocation check the map and allocate a pointer only if not found in map  
    */
    SinglyLinkedListNode *head_clone=NULL;
    SinglyLinkedListNode *curr=list,*curr_clone=NULL;
    unordered_map<int,SinglyLinkedListNode *> data_ptr_map;
    while(curr){
        if(head_clone==NULL){
            if(data_ptr_map.find(curr->data) == data_ptr_map.end()){
                //allocating the first node
                SinglyLinkedListNode *new_node = new SinglyLinkedListNode(curr->data); 
                cout << "creating : " << curr->data << endl;
                //add to the map
                data_ptr_map[curr->data]=new_node;
                curr_clone=new_node;
                // fix the head_clone which will be returned
                head_clone=curr_clone;
            }else{
                curr_clone = data_ptr_map[curr->data];
            }
            // check the random pointer
            if(curr->randomPointer){
                // since random pointer could be self , there is a possibility of
                // it being allocated already . check in the map before new allocation
                if(data_ptr_map.find(curr->randomPointer->data) == data_ptr_map.end()){
                    SinglyLinkedListNode *new_node = new SinglyLinkedListNode(curr->randomPointer->data);
                    cout << "creating : " << curr->randomPointer->data << endl;
                    //add to the map
                    data_ptr_map[curr->randomPointer->data]=new_node;
                    curr_clone->randomPointer=new_node;
                }else{
                    curr_clone->randomPointer = data_ptr_map[curr->randomPointer->data];
                }
            }
        }else{
            if(data_ptr_map.find(curr->data) == data_ptr_map.end()){
                //allocating the first node
                SinglyLinkedListNode *new_node = new SinglyLinkedListNode(curr->data); 
                cout << "creating : " << curr->data << endl;
                //add to the map
                data_ptr_map[curr->data]=new_node;
                curr_clone->next=new_node;
                // check the random pointer
            }else{
                curr_clone->next = data_ptr_map[curr->data];
            }
            if(curr->randomPointer){
                // there is a possibility of randomPointer
                // it being allocated already . check in the map before new allocation
                if(data_ptr_map.find(curr->randomPointer->data) == data_ptr_map.end()){
                    SinglyLinkedListNode *new_node = new SinglyLinkedListNode(curr->randomPointer->data);
                    cout << "creating : " << curr->randomPointer->data << endl;
                    //add to the map
                    data_ptr_map[curr->randomPointer->data]=new_node;
                    curr_clone->next->randomPointer=new_node;
                }else{
                    curr_clone->next->randomPointer = data_ptr_map[curr->randomPointer->data];
                }
            }
            curr_clone=curr_clone->next;    
        }
        curr=curr->next;
    }

    return head_clone;
}



int main()
{
    ostream &ferr = cerr;
    unordered_map<int, SinglyLinkedListNode *> mapper;
    unordered_set<SinglyLinkedListNode *> originalNodes;
    SinglyLinkedList *List = new SinglyLinkedList();

    string linkedList_count_temp;

    getline(cin, linkedList_count_temp);

    int linkedList_count = stoi(ltrim(rtrim(linkedList_count_temp)));

    for (int i = 1; i <= linkedList_count; i++)
    {
        List->insert_node(i);
        mapper[i] = List->tail;
        originalNodes.insert(List->tail);
    }

    for (int i = 1; i <= linkedList_count; i++)
    {
        string linkedList_item_temp;
        getline(cin, linkedList_item_temp);
        int linkedList_item = stoi(ltrim(rtrim(linkedList_item_temp)));
        if (linkedList_item != -1)
            mapper[i]->link_random_node(mapper[linkedList_item]);
    }

    SinglyLinkedListNode *clonedListHeadNode = cloneLinkedList(List->head);

    if (cloneCheck(clonedListHeadNode, originalNodes) == false)
    {
        ferr << "Instead of creating new node, you have used node from the input linked list.";
        ferr << "Any node from the input linked list must not be used in the cloned linked list";
    }
    else
    {
        string seperator = "\n";
        print_singly_linked_list_with_random_node(clonedListHeadNode, seperator);
    }

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

void print_singly_linked_list_with_random_node(SinglyLinkedListNode *node, string sep)
{
    ostream &fout = cout;
    ostream &ferr = cerr;
    unordered_set<SinglyLinkedListNode *> visited;
    string delimitter = " ";
    while (node)
    {
        visited.insert(node);
        if (node->next != nullptr and visited.find(node->next) != visited.end())
        {
            ferr << "The next pointer links in the cloned list are forming a loop";
            return;
        }
        fout << node->data << delimitter;

        if (node->next != nullptr)
        {
            fout << node->next->data << delimitter;
        }
        else
            fout << -1 << delimitter;

        if (node->randomPointer != nullptr)
        {
            fout << node->randomPointer->data;
        }
        else
        {
            fout << "-1";
        }

        node = node->next;

        if (node)
        {
            fout << sep;
        }
    }
}

bool cloneCheck(SinglyLinkedListNode *head, unordered_set<SinglyLinkedListNode *> originalNodes)
{
    SinglyLinkedListNode *tmp = head;
    while (tmp)
    {
        if (originalNodes.find(tmp) != originalNodes.end())
        {
            return false;
        }
        tmp = tmp->next;
    }
    return true;
}


