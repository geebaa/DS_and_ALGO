#include <bits/stdc++.h>

using namespace std;

pair<char,char> getedge(string &p,string &c,unordered_map<char,unordered_set<char>> &adj_map)
{
    /*
        this function returns the edge and also adds vertices that are not found in adj_map
    */
    int i=0;
    int plen=p.size();
    int clen=c.size();
    pair<char,char> result=make_pair(' ' ,' ');
    while( (i< plen) && (i < clen) ){
        if(p[i] != c[i]){
            result=make_pair(p[i],c[i]);
            if(adj_map.find(p[i]) == adj_map.end()){
                //add the node with no edge
                adj_map[p[i]]={};
            }
            if(adj_map.find(c[i]) == adj_map.end()){
                //add the node with no edge
                adj_map[c[i]]={};
            }

            break;
        }else{
            if(adj_map.find(p[i]) == adj_map.end()){
                //add the node with no edge
                adj_map[p[i]]={};
            }
            i++;
        }
    }
    //cout << " edge : " << result.first << " -> " << result.second<<endl;
    return result;

}

void topo_sort(unordered_map<char,unordered_set<char>> &adj_map,
               char node,
               vector<char> &topo_sorted,
               unordered_set<char>  &visited)
{

    queue<char> q;
    q.push(node);
    visited.insert(node);
    //cout << " node : " << node <<endl;
    while(!q.empty()){
        char curr = q.front();
        q.pop();
        for(auto neighbor : adj_map[curr]){
            if(visited.find(neighbor) == visited.end()){
                topo_sort(adj_map,neighbor,topo_sorted,visited);
            }
        }
        // to topologically sort the node , the current node is inserted
        // in the begining
        topo_sorted.insert(topo_sorted.begin(),node);
    }
}
 
string find_order(vector <string> words) {

    // since the array of words is sorted,
    // we can find the order of alphabets
    int p=0;
    int c=1;
    pair<char,char> edge;
    unordered_set<char> alphabets;
    unordered_map<char,unordered_set<char>>adj_map;
    unordered_map<char,unordered_set<char>>::iterator itr;
    int n=words.size();
    if(n == 1){
        return words[0].substr(0,1);
    }
    
    //cout << " n : " << n<<endl;
    for(;c<n;p++,c++){
        //cout << " c : " << c<< " p : " << p<<endl;
        edge = getedge(words[p],words[c],adj_map);
        if(edge.first != ' '){
            // update the adj_map representation of graph
            adj_map[edge.first].insert(edge.second);
        }
    }
    //cout << "adj map constructed : size = "<<adj_map.size() << endl;
    // topologically sort the graph
    vector<char> topo_sorted;
    int num_vertices=adj_map.size();
    unordered_set<char> visited; // one for each alphabet
    itr = adj_map.begin();
    while(itr != adj_map.end()){
        if(visited.find(itr->first) == visited.end()){
            topo_sort(adj_map,itr->first,topo_sorted,visited);
        }
        itr++;
    }
    return string(topo_sorted.begin(),topo_sorted.end());

}


int main()
{
    ostream &fout = cout;

    string res;
    int words_size = 0;
    cin >> words_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<string> words;
    for(int i = 0; i < words_size; i++) {
        string words_item;
        //getline(cin, words_item);
        cin >> words_item;
        words.push_back(words_item);
    }

    res = find_order(words);
    fout << res << endl;

    
    return 0;
}


