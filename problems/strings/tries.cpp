#include<bits/stdc++.h>
using namespace std;

typedef class _TrieNode{
    private :
        // is a flag that indicates if this node is also a leaf besides being
        // an internal node
        bool isLeaf;
        unordered_map<char,class _TrieNode *> children;
    public :
        _TrieNode()
        {
            isLeaf=false;
        }
        void set_leaf()
        {
            isLeaf=true;
        }
        void reset_leaf()
        {
            isLeaf=false;
        }
        bool is_leaf()
        {
            return isLeaf;
        }
        _TrieNode *get_child(char c)
        {
            if(children.find(c) != children.end()){
                return children[c];
            }else{
                return NULL;
            }
        }
        void set_child(char c,_TrieNode *child)
        {
            children[c]=child;
        }

} TrieNode;

typedef class _Trie{
    private :
        TrieNode *head;
    public :
        _Trie(){
            head=new(TrieNode);
        }
        void insert_string(string s){
            TrieNode *curr=head;
            int n=s.size();;
            for(int i=0;i<n;i++){
                if(curr->get_child(s[i]) == NULL){
                    TrieNode *new_node = new(TrieNode);
                    curr->set_child(s[i],new_node);
                }
                curr = curr->get_child(s[i]);
            }    
            curr->set_leaf();
        }
        void delete_string(string s) {
        }

        void print_trie_words_helper(vector<string> &result,string &s)
        {
            //base case
        }
        vector<string> print_trie_words(){
            vector<string> result;
            string s;
            print_trie_words_helper(result,s);
            return result;
        }
        bool prefix_exists(string s){
            TrieNode *curr=head;
            int n=s.size();;
            for(int i=0;i<n;i++){
                if(curr->get_child(s[i]) != NULL){
                    curr = curr->get_child(s[i]);
                }else{
                    return false;
                }
            }    
            return true;
        }
        bool word_exists(string s){
            TrieNode *curr=head;
            int n=s.size();;
            for(int i=0;i<n;i++){
                if(curr->get_child(s[i]) != NULL){
                    curr = curr->get_child(s[i]);
                }else{
                    return false;
                }
            }
            if(curr->is_leaf()){
                return true;
            }   
            return false;
        }

} Trie;

int main()
{
    string s;
    Trie *my_trie = new(Trie);
    cout << " Input String : ";
    cin >> s;
    my_trie->insert_string(s);
    my_trie->insert_string("hello world");
    //my_trie->insert_string(s);
    //my_trie->insert_string(s);
    //my_trie->insert_string("hello world");
    //my_trie->insert_string("hello world");
    cout << "word " << s << " exists : " << my_trie->word_exists(s)<<endl;
    cout << "prefix " << s << " exists : " << my_trie->word_exists(s)<<endl;
    cout << "word " << "abracadabraa" << " exists : " << my_trie->word_exists("abracadabraa")<<endl;
    cout << "word " << "abracadabr" << " exists : " << my_trie->word_exists("abracadabr")<<endl;
    cout << "prefix " << "abracadabraa" << " exists : " << my_trie->prefix_exists("abracadabraa")<<endl;
    cout << "prefix " << "abracadabr" << " exists : " << my_trie->prefix_exists("abracadabr")<<endl;



    cout << "word " << "hello world" << " exists : " << my_trie->word_exists("hello world")<<endl;
    cout << "prefix " << "hello world" << " exists : " << my_trie->word_exists("hello world")<<endl;
    cout << "word " << "helloworld" << " exists : " << my_trie->word_exists("helloworld")<<endl;
    cout << "word " << "hello world1" << " exists : " << my_trie->word_exists("hello world1")<<endl;
    cout << "prefix " << "hello world1" << " exists : " << my_trie->prefix_exists("hello world1")<<endl;
    cout << "prefix " << "hello wo" << " exists : " << my_trie->prefix_exists("hello wo")<<endl;
}

