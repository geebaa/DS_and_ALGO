#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
bool bfs(string &start,string &stop,unordered_map<string,unordered_set<string> >adj_list,unordered_map<string,int>&visited,unordered_map<string,string> &parent)
{
    // mark visited
    visited[start]=1;
    queue<string> q;
    q.push(start);
    
    while(!q.empty()){
        string node=q.front();
        q.pop();
        for(auto neighbor:adj_list[node]){
            if(visited[neighbor] == -1){
                // current neighbor is explored by the node
                parent[neighbor] = node;
                if(neighbor==stop){
                    // transform complete
                    return true;
                } 
                // not yet visited , visit and explore
                visited[neighbor]=1;
                q.push(neighbor);
            }else{
                // specific case where start == stop. 
                // in this case visitor[start] would have been marked 1 
                // when we come here looking for stop  
                if(start == stop){
                    parent[neighbor] = node;
                    return true;
                }
            }
        }
    }
    // unable to transform from start to stop
    return false;
}

/* two words are neighbors iff they differ at exactly one place*/
bool wordsAreNeighbors(string &str1,string &str2,int word_len){
    int i=0;
    while( (i<word_len) && (str1[i] == str2[i]) ){
        i++;
    }
    if(i==word_len){
        //no character differed
        return false;
    }
    // one character differed at i
    i++;
    while( (i<word_len) && (str1[i] == str2[i]) ){
        i++;
    }
    if(i==word_len){
        return true;
    }
    // more than 1 character differed
    return false;
    
}
/*
 * Complete the function below.
 */
void buildAdjList1(string &start,vector<string> &words,string &stop,unordered_map<string,int> &visited,unordered_map<string,unordered_set<string> > &adj_list)
{
    int word_len=start.size();

    // check if start & stop are adjacent
    if(wordsAreNeighbors(start,stop,word_len)){
        adj_list[start].insert(stop);
        adj_list[stop].insert(start);
    }

    // build adjlist for all words with start and stop
    for(auto str:words){
        if(wordsAreNeighbors(start,str,word_len)){
            adj_list[start].insert(str);
            adj_list[str].insert(start);
        }
        if(wordsAreNeighbors(stop,str,word_len)){
            adj_list[stop].insert(str);
            adj_list[str].insert(stop);
        }

    }

    // build adjlist for all words with other words
    
    for(auto str1:words){
        for(auto str2:words){
            if(wordsAreNeighbors(str1,str2,word_len)){
                adj_list[str1].insert(str2);
                adj_list[str2].insert(str1);
            }
        }
    }

    // set visited to -1
    visited[start] = -1;
    visited[stop]  = -1;
    for(auto node:words){
        visited[node] = -1;
    }
}
vector<string> string_transformation(vector<string> words, string start, string stop) {
    vector<string> result;
    unordered_map<string,int> visited;
    // a map to hold "discovered by" relation"
    unordered_map<string,string> parent;
    unordered_map<string,string>::iterator parent_itr;
    bool isTransformPossible=false;
    // map of string (vertex) to set of strings neighbors
    unordered_map<string,unordered_set<string> > adj_list; 
    
    buildAdjList1(start,words,stop,visited,adj_list);
    
    if(bfs(start,stop,adj_list,visited,parent) == true){
        //cout << "bfs returned true : " << endl;
        // compute result from the parent array
        parent_itr = parent.find(stop);
        result.push_back(parent_itr->first);
        while(parent_itr != parent.end()){
            result.push_back(parent_itr->second);
            parent_itr = parent.find(parent_itr->second);
            if( (parent_itr != parent.end() ) && (parent_itr->second == start) ){
                result.push_back(start);
                break;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
    //cout << "bfs returned false : " << endl;
    return {"-1"};
    
}


int main()
{
    ostream &fout = cout;

    int words_size;
    cin >> words_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> words(words_size);
    for (int words_i = 0; words_i < words_size; words_i++) {
        string words_item;
        getline(cin, words_item);

        words[words_i] = words_item;
    }

    string start;
    getline(cin, start);

    string stop;
    getline(cin, stop);

    vector<string> res = string_transformation(words, start, stop);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
    
    
    return 0;
}


