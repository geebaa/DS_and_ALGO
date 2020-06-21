#include <bits/stdc++.h>

using namespace std;

void dfs(unordered_map<int,vector<pair<int,int>>> &adj_map,
         vector <int> &topo_sorted,
         int node,
         vector<int> &visited)
{
    visited[node]=1;

    for(auto neighbor : adj_map[node]){
        // note - we dont check for cycles in the 
        // else part since the input is a weighted DAG
        if(visited[neighbor.first] == -1){
            dfs(adj_map,topo_sorted,neighbor.first,visited);
        }
    }
    // insert node in the begining , this would make it automatically topologically sorted
    topo_sorted.insert(topo_sorted.begin(),node);
}

void topo_sort(unordered_map<int,vector<pair<int,int>>> &adj_map,vector <int> &topo_sorted,vector<int> &visited)
{
    int n=visited.size();
    // launch DFS on all nodes
    // nodes are from 1 to n
    for(int i=1;i<=n;i++){
        if(visited[i] == -1){
            dfs(adj_map,topo_sorted,i,visited);
        }
    }
}

/*
	For the weighted graph:
	1. The number of nodes is <name>_nodes.
	2. The number of edges is <name>_edges.
	3. An edge exists between <name>_from[i] to <name>_to[i] and the weight of the edge is <name>_weight[i].
*/
vector <int> find_longest_path(int dag_nodes, vector <int> dag_from, vector <int> dag_to, vector <int> dag_weight, int from_node, int to_node) {
    //create weighted graph
    unordered_map<int,vector<pair<int,int>>>adj_map;

    // visited array for graph traversal
    // n+1 because nodes start from 1 to n
    // 0 is unused
    vector<int> visited(dag_nodes+1,-1);

    // number of edges
    // can be size of dag_to or dag_weights also
    int nedges=dag_from.size();

    // graph construction
    for(int i=0;i<nedges;i++){
        //each edge is a pair of adj_map[from] = adj_map[from] + <to,weight>
        adj_map[dag_from[i]].push_back(make_pair(dag_to[i],dag_weight[i]));
    }

    // toposort the DAG
    vector <int> topo_sorted;
    topo_sort(adj_map,topo_sorted,visited);

    // print topo_sorted
    //cout << endl;
    //for(auto node:topo_sorted){
    //    cout << " " << node;
    //}
    //cout << endl;

    // iterate thru the topo_sorted and find the distance between from_node to to_node
    // maintain distance array and parent array for tracing the path

    vector<long long int> longest_path(dag_nodes + 1, -1);
    vector<int> parent(dag_nodes + 1, 0);

    //initialize the path from from_node to from_node to 0
    longest_path[from_node] = 0;

    //cout << "topo sort done " << endl;
    // compute longest path for every dag node
    for(int i=0;i<dag_nodes;i++){
        int from = topo_sorted[i];
        // will not get into this if till we reach the from_node since
        // all other nodes except the from_node is initialized to 0
        //cout << "for every dag node : "<<i << endl;
        if (longest_path[from] >= 0){
            //already reached the destination node
            // nothing more the compute
            if (from == to_node)
            {
                break;
            }

            // for all the neighbors 'to' of 'from'
            // calculate the longest_path from 'from' to 'to'
            for (int j = 0; j < adj_map[from].size(); j++)
            {  
                //cout << "    for every neighbor : "<<j << endl;
                int to = adj_map[from][j].first;
                long long int weight = adj_map[from][j].second;
                // If longer path possible then update. 
                if (longest_path[to] <= longest_path[from] + weight)
                {
                    longest_path[to] = longest_path[from] + weight;
                    // Also keep track of node through which it gets updated. 
                    parent[to] = from;
                }
            }
        }


    }

    //cout << "computed longest distance "<< endl;
    //for(auto elem:parent){
    //    cout << " "<<elem;
    //}
    //cout<<endl; 
    // Find the path in reverse order! And then reverse it! 
    vector<int> path;
    path.push_back(to_node);
    while (to_node != from_node)
    {
        to_node = parent[to_node];
        path.push_back(to_node);
    }
    // Till now we have found the path in reverse order. 
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ostream &fout = cout;

    vector <int> res;
    int dag_nodes = 0;
    int dag_edges = 0;

    cin >> dag_nodes >> dag_edges;

    vector<int> dag_from(dag_edges);
    vector<int> dag_to(dag_edges);
    vector<int> dag_weight(dag_edges);

    for (int dag_i = 0; dag_i < dag_edges; dag_i++) {
        cin >> dag_from[dag_i] >> dag_to[dag_i] >> dag_weight[dag_i];
    }

    int from_node;
    cin >> from_node;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int to_node;
    cin >> to_node;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = find_longest_path(dag_nodes, dag_from, dag_to, dag_weight, from_node, to_node);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}


