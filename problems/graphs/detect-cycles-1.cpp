#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hasCycle' function below.
 *
 * The function accepts INTEGER N, INTEGER M and 2D_INTEGER_ARRAY edges as parameter.
 * The function is expected to return a BOOLEAN.
 */

int timestamp=0;
bool dfs(int node,unordered_map<int,unordered_set<int>> &adj_list,vector<int> &visited,vector<int> &arrival,vector<int> &departure)
{
    //timestamp 
    arrival[node]=timestamp++;
    // mark visited
    visited[node]=1;

    // for each neighbor
    for(auto neighbor:adj_list[node]){
        if(visited[neighbor] == -1){
            // if any child under the subtree reported backedge , terminate and report
            // backedge
            if(dfs(neighbor,adj_list,visited,arrival,departure)) {
                return true;
            }
        }else{
            // already visited
            if(departure[neighbor] == -1){
                // backedge case
                return true;
            }
        }
    }

    // no backedge case
    departure[node]=timestamp++;
    return false;

}
bool hasCycle(int N, int M, vector<vector<int>> edges) {
	// Write your code here

    unordered_map<int,unordered_set<int>> adj_list;
    vector<int> visited(N,-1);
    vector<int> arrival(N,-1);
    vector<int> departure(N,-1);
    
    bool has_cycle=false;
    //create adj_list
    for(auto edge:edges){
        adj_list[edge[0]].insert(edge[1]);
    }

    for(int i=0;i<N;i++){
        if(visited[i] == -1){
            has_cycle = dfs(i,adj_list,visited,arrival,departure);
        }
        if(has_cycle){
            return true;
        }
    }
    return false;
}


int main()
{
    string vertices;
    getline(cin, vertices);

    int N = stoi(ltrim(rtrim(vertices)));

    string no_edges;
    getline(cin, no_edges);

    int M = stoi(ltrim(rtrim(no_edges)));

    vector<vector<int>> edges(M);

    for (int i = 0; i < M; i++) {
        edges[i].resize(2);

        string edge;
        getline(cin, edge);

        vector<string> end_points = split(rtrim(edge));

        for (int j = 0; j < 2; j++) {
            int vertex = stoi(end_points[j]);

            edges[i][j] = vertex;
        }
    }

    ostream &fout = cout;

    bool result = hasCycle(N, M, edges);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


