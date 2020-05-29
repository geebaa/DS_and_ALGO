#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
Complete the function findCriticalConnections
The function takes integers noOfServers, noOfConnections and 2D integer array as parameters.
Returns a 2D integer array.
*/

vector<vector<int>> critical_edges={};
int timestamp=0;

// This function does a dft on the node returns the lowest arrival time
// of all the back edges rooted at this tree and also
// determines if the tree edge leading to it is a critical connection
// if so adds it to  "critical_edges"
int dfs(int &root,int node,vector<int> &visited,vector<int> &arrival,vector<int> &departure,vector<int> &parent,unordered_map<int,unordered_set<int> > &adj_list)
{
    visited[node] = 1;
    arrival[node] = timestamp++;
    int min_backedge_arrival_time=arrival[node];
    for(auto neighbor:adj_list[node]){
        if(visited[neighbor] == -1){
            // update parent
            parent[neighbor]=node;
            // traversing tree edge
            int subtree_min_backedge_arrival_time;
            subtree_min_backedge_arrival_time = dfs(root,neighbor,visited,arrival,departure,parent,adj_list);
            min_backedge_arrival_time = min(subtree_min_backedge_arrival_time,min_backedge_arrival_time);
        }else{
            if(parent[node] == neighbor){
                // tree node
                continue;
            } else
            // non-tree node and backedge
            if(departure[neighbor] == -1 ){
                // update the min_backedge_arrival_time
                min_backedge_arrival_time = min(min_backedge_arrival_time,arrival[neighbor]);
            }
        }
    }
    // check if min_backedge_arrival_time is same as the node's arrival time
    // if so , the subtree rooted at this node does not have a backedge crossing this
    // node. Hence the tree edge from the parent to this node is a critical edge
    // add it to critical_edges.
    // node != root identifies this node to be a root since we started exploring from node root
    // by calling dfs(root,...).
    if( (node != root) && ( min_backedge_arrival_time == arrival[node])  ){
        // edge is the one between parent[node] -- node
        vector<int> critical_edge;
        critical_edge.push_back(parent[node]);
        critical_edge.push_back(node);
        critical_edges.push_back(critical_edge);

    }
    departure[node] = timestamp++;
    return min_backedge_arrival_time;
}

vector<vector<int>> findCriticalConnections(int noOfServers, int noOfConnections, vector<vector<int>> connections) {
    

    vector<int> visited(noOfServers,-1);
    vector<int> arrival(noOfServers,-1);
    vector<int> departure(noOfServers,-1);
    vector<int> parent(noOfServers,-1);
    unordered_map<int,unordered_set<int>> adj_list(noOfConnections);

    // create adj_list
    for(auto connection:connections){
        adj_list[connection[0]].insert(connection[1]);
        adj_list[connection[1]].insert(connection[0]);
    }
    //cout << "noOfServers : " << noOfServers << " noOfConnections : " << noOfConnections << " adj_list size : " << adj_list.size()<< "connections size : "<< connections.size() << endl;
    // launch dfs on node 0 .. can be any node since this
    // is a connected graph
    for(int i=0;i<noOfServers;i++){
        if(visited[i] == -1){
            dfs(i,i,visited,arrival,departure,parent,adj_list);
        }
    }
    if(!critical_edges.empty()){
        return critical_edges;
    }else{
        return {{-1,-1}};
    }

}


int main()
{
    ostream &fout = cout;
    
    string noOfServers_temp;
    getline(cin, noOfServers_temp);

    int noOfServers = stoi(ltrim(rtrim(noOfServers_temp)));
    
    string noOfConnections_temp;
    getline(cin, noOfConnections_temp);
    
    int noOfConnections = stoi(ltrim(rtrim(noOfConnections_temp)));

    vector<vector<int>> connections(noOfConnections);

    for (int i = 0; i < noOfConnections; i++) {
        connections[i].resize(2);

        string connections_row_temp_temp;
        getline(cin, connections_row_temp_temp);

        vector<string> connections_row_temp = split(rtrim(connections_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int connections_row_item = stoi(connections_row_temp[j]);

            connections[i][j] = connections_row_item;
        }
    }

    vector<vector<int>> result = findCriticalConnections(noOfServers, noOfConnections, connections);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

