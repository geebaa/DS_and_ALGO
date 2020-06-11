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
        bool has_children()
        {
            return !children.empty();
        }
        unordered_map<char,class _TrieNode *> get_children()
        {
            return children;
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
            if(child == NULL){
                children.erase(c);
            }else{
                children[c]=child;
            }
        }

} TrieNode;

typedef class _Trie{
    private :
        TrieNode *head;
    public :
        _Trie(){
            head=new(TrieNode);
        }
        void insert_word(string s){
            TrieNode *curr=head;
            int n=s.size();
            for(int i=0;i<n;i++){
                if(curr->get_child(s[i]) == NULL){
                    TrieNode *new_node = new(TrieNode);
                    curr->set_child(s[i],new_node);
                }
                curr = curr->get_child(s[i]);
            }    
            curr->set_leaf();
        }

        void delete_word(string s) {
        }

        void get_trie_words_helper(TrieNode *node,vector<string> &result,string &s)
        {
            //base case
            if(node==NULL){
                return;
            }

            // recursive case
            if(node->is_leaf()){
                // prefix s is also a word
                // push it to result
                //cout << " word : " << s<<endl;
                result.push_back(s);
            }
            // for every child launch the word search
            unordered_map<char,class _TrieNode *> children = node->get_children(); 
            for(auto child:children){
                s = s+child.first; // append the character
                get_trie_words_helper(child.second,result,s);
                //remove the last character
                s.pop_back();
            }
        }
        vector<string> get_trie_words(){
            vector<string> result;
            string s;
            get_trie_words_helper(head,result,s);
            return result;
        }
        bool prefix_exists(string s){
            TrieNode *curr=head;
            int n=s.size();
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
            int n=s.size();
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

typedef class _SuffixTrie{
    private :
        Trie t;
    public :
        _SuffixTrie(string s)
        {
            int n=s.size();
            //build a suffix trie for all the suffixes
            for(int i=n-1;i>=0;i--){
                // i is the starting character of the suffix
                int suffix_len=n-i;
                t.insert_word(s.substr(i,suffix_len)); 
            }
        }
        vector<string> get_trie_words()
        {
            return t.get_trie_words();
        }
} SuffixTrie;

typedef class _PrefixTrie{
    private :
        Trie t;
    public :
        _PrefixTrie(string s)
        {
            int n=s.size();
            //build a prefix trie for all the prefixes
            for(int i=1;i<=n;i++){
                // i is length of the prefix
                t.insert_word(s.substr(0,i)); 
            }
        }
        vector<string> get_trie_words()
        {
            return t.get_trie_words();
        }
} PrefixTrie;


int main()
{
    string s="abracadabra";
    vector<string> words;
    Trie *my_trie = new(Trie);
    SuffixTrie *s_trie = new SuffixTrie("hello world");
    PrefixTrie *p_trie = new PrefixTrie("hello world");
    my_trie->insert_word(s);
    my_trie->insert_word("hello world");
    my_trie->insert_word("hello");
    my_trie->insert_word("hello universe");
    my_trie->delete_word("hello world");
    words=s_trie->get_trie_words();
    cout<< endl;
    for(auto word:words){
        cout << word<<endl;
    }
    cout<< endl;
    words=p_trie->get_trie_words();
    cout<< endl;
    for(auto word:words){
        cout << word<<endl;
    }
    cout<< endl;

}

