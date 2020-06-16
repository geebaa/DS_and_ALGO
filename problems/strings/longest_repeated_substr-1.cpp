#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'getLongestRepeatedSubstring' function below.
 */

string getLongestRepeatedSubstringBruteForce(string inputStr) {
    string result;
    int maxlen=0;
    int n=inputStr.length();
    int k=0;
    // enumerate all substrings
    for(int i=0;i<n;i++){
        k=i+1;//start of searchhere
        for(int j=i;j<n;j++){
            // substring is inputStr[i:j]
            string substr=inputStr.substr(i,j-i+1);
            // where to search inputStr[j+1:n-1]
            //string searchhere=inputStr.substr(k);
            //cout << " substr : " << substr << " searchhere : " << searchhere << endl;
            //if(searchhere.find(substr) != string::npos){
            if(inputStr.find(substr,k) != string::npos){
                //update result 
                if(maxlen < substr.length()){
                    maxlen=substr.length();
                    result=substr;
                    //cout << " maxlen : " << maxlen << " result : " << result << endl;
                }
            }else{
                // no way a longer substring will exist we need to move to the next i
                break;
            }
        }
    }
    return result;
}

void computeLPS(string &inputStr,int p_s,int p_e,vector<int> &lps)
{
    int len=0,i=1;
    int n = p_e - p_s + 1;// length of the pattern
    lps[len]=0 ;

    while(i<n){
        if(inputStr[p_s+i] == inputStr[p_s+len]){
            lps[i]=len+1;
            i++;
            len++;
        }else{
            if(len == 0){
                // seeing mismatch in the begining hence set to 0
                lps[i]=0;
                // move to next
                i++;
            }else{
                // retract only the len and stay with the same i
                len=lps[len-1];
            }
        }
    }
}

/*
    kmp search pattern is inputStr[p_s..p_e] and text is inputStr[t_s..t_e]
    first s lps of length p_e - p_s + 1 is allocated and prepared
    then the string is searched 
*/
bool kmp(string &inputStr,int p_s,int p_e,int t_s,int t_e)
{
    int m=p_e - p_s + 1;//length of pattern
    int n=t_e - t_s + 1;//length of text
    if(m>n){
        return false;
    }
    vector<int>lps(m,0);
    computeLPS(inputStr,p_s,p_e,lps);
    
    int i=0;
    int j=0;
    // iterate over the length of the text
    while(i<n){
        if(inputStr[t_s+i] == inputStr[p_s+j]){
            // characters match in pattern and text
            // move both forward
            i++;
            j++;
        }else{
            if(j==0){
                // first character of pattern mismatch
                // move i forward
                i++;
            }else{
                // retract j back
                j=lps[j-1];
            }
        }
        // at any time when j reaches m , we have exhausted all characters
        // in pattern and hence it a match was found 
        if(j == m){
            return true;
        }
    }
    return false;
}

string getLongestRepeatedSubstringKMP(string inputStr) {
    string result;
    int maxlen=0;
    pair<int,int> substr_index(-1,-1);
    int n=inputStr.length();
    int k=0;
    // enumerate all substrings
    // i is the starting location and 
    // j is the ending location in inputStr
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            // use KMP to find if substring exists in the remaining text
            if(kmp(inputStr,i,j,i+1,n-1)){
                // pattern is inputStr[i,j]
                // txt is inputStr[j+1,n-1]
                //cout << " substr : " << inputStr.substr(i,j-i+1)<<endl;
                if(maxlen < j-i+1){
                    //found new longer repeating string 
                    maxlen = j-i+1;
                    substr_index.first=i;
                    substr_index.second=j;
                    
                }
            }
        }
    }
    if(substr_index.first == -1){
        // no repeating substring found
    }else{
        // repeating string index is substr_index
        int i=substr_index.first;
        int j=substr_index.second;
        result = inputStr.substr(i,j-i+1);
    }
    return result;
}
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
        int num_children()
        {
            return children.size();
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

        void get_longest_repeated_substring_helper(TrieNode *&node,string &result,string &partial_result){
            // base case
            if(!node->has_children()){
                return;
            }

            //recursive case
            // if there are more then 1 children then we have a potential repeated substring
            // store the partial_result appropriately based on length of current result
            // node->is_leaf() means that the current node is a suffix and has children
            // which is equivalent of a branch
            if( (node->num_children() > 1) || (node->is_leaf()) ){
                if(result.size() < partial_result.size()){
                    // longer repeated substring
                    result = partial_result; 
                    cout << "partial_result : " << partial_result<<endl;
                }
            }
            // for every child explore
            unordered_map<char,class _TrieNode *> children = node->get_children();
            for(auto child:children){
                partial_result = partial_result+child.first; // append the character
                get_longest_repeated_substring_helper(child.second,result,partial_result);
                //remove the last character
                partial_result.pop_back();
            }
        }

        string get_longest_repeated_substring()
        {
            string result;
            string partial_result;
            get_longest_repeated_substring_helper(head,result,partial_result);
            return result;
        }

} Trie;
typedef class _SuffixTrie{
    private :
        Trie t;
    public :
        _SuffixTrie(string s)
        {
            int n=s.size();
            cout << "String size : " << n;
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


        string get_longest_repeated_substring()
        {
            return t.get_longest_repeated_substring();
        }

} SuffixTrie;
SuffixTrie *s_trie;
string getLongestRepeatedSubstring(string inputStr) {
    s_trie = new SuffixTrie(inputStr);
    //vector<string> suffixes=s_trie->get_trie_words();
    //cout <<endl;
    //int i=0;
    //for(auto suffix : suffixes){
        //cout << suffix<<endl;
        //cout << i++<<endl;
    //}    
    //cout<<endl;
    string result=s_trie->get_longest_repeated_substring();
    //cout << " lrs : "<<result<<endl;
    return result;
}

int main()
{
    string inputStr;
    getline(cin, inputStr);

    ostream &fout = cout;

    string result = getLongestRepeatedSubstring(inputStr);

    fout << result << "\n";


    return 0;
}


