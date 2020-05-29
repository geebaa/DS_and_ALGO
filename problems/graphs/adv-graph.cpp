#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> edge_list; // edges in graph
vector<pair<pair<int,int>,int>> weighted_edge_list; // weighted edges in graph
int n; // number of vertices 0 to n-1

void add_edge(int s,int d){
    pair<int,int> edge=make_pair(s,d);;
    edge_list.push_back(edge);
}

void add_weighted_edge(int s,int d,int weight){
    pair<int,int> edge=make_pair(s,d);
    pair<pair<int,int>,int> weighted_edge(edge,weight);
    weighted_edge_list.push_back(weighted_edge);
}


// Root is a node that is its own parent
// recurse and point all the children as 
// the recursion unwinds to the root
int find_root(int vertex,vector<int> &parent)
{
    if(vertex == parent[vertex]){
        return vertex;
    }
    parent[vertex] = find_root(parent[vertex],parent);
    return parent[vertex];
}

bool compare(const pair<pair<int,int>,int> &i, const pair<pair<int,int>,int> &j)
{
    return i.second < j.second;
}

vector<pair<int,int>> kruskal_MST(int n,vector<pair<pair<int,int>,int>> &weighted_edge_list)
{
    vector<pair<int,int>> mst;
    int total_cost=0;
    // size of trees rooted at vertex i in o to n-1
    vector<int>size(n,1);

    // parent is the root of the tree a vertex belongs to
    vector<int>parent(n);

    // total num of components
    // start with n componenets
    int num_components=n;
   
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    // ::::: very important step for kruskal is to start with sorted edges :::::
    sort(weighted_edge_list.begin(),weighted_edge_list.end(),compare);

    for(auto edge:weighted_edge_list){
        int root_src=find_root(edge.first.first,parent);
        int root_dst=find_root(edge.first.second,parent);
        if(root_src != root_dst){
            if( size[root_src] < size[root_dst] ) {
                parent[root_src] = root_dst;
                size[root_dst] += size[root_src];
            } else {
                parent[root_dst] = root_src;
                size[root_src] += size[root_dst];
            }
            num_components--;
            total_cost += edge.second;
            mst.push_back(make_pair(edge.first.first,edge.first.second));
            if(num_components == 1){
                cout << "Kruskal's total cost-1 : " << total_cost << endl; 
                return mst;
            }
        }
        else{
            //cycle
        }
    }
    if(num_components != 1){
        return {};
    }
    cout << "Kruskal's total cost-2 : " << total_cost << endl; 
    return mst;
}

int union_find(int n,vector<pair<int,int>> &edge_list)
{
    // size of trees rooted at vertex i in o to n-1
    vector<int>size(n,1);

    // parent is the root of the tree a vertex belongs to
    vector<int>parent(n);


    // total num of components
    // start with n componenets
    int num_components=n;
   
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    // as and when an edge (src,dst) arrives
    for(auto edge:edge_list){
        int root_src = find_root(edge.first,parent);
        int root_dst = find_root(edge.second,parent);
        if(root_src != root_dst){
            // merge the 2 components
            if(size[root_src] < size[root_dst]){
                parent[root_src]=root_dst;
                size[root_dst] += size[root_src];
            }else{
                parent[root_dst]=root_src;
                size[root_src] += size[root_dst];
            }
            num_components--;
        }   

    }
    return num_components;

}

vector<pair<int,int>> prim_MST(int n,vector<pair<pair<int,int>,int>> &weighted_edge_list)
{
    // map of vertex to a set of pair<vertex,cost> 
    map<int,set<pair<int,int>>> adj_list;
    vector<pair<int,int>> mst;
    int total_cost=0;

    // number of vertices captured
    int num_captured=0;
    //priority_queue<pair<int,pair<int,int>>> pq;

    // creation of min priority queue based on 1st element of pair
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
    // captured array of all vertices
    vector<int> captured(n,-1);
    
    // build the graph a.k.a adj_list
    for(auto edge:weighted_edge_list){
        // undirected graph and hence 2 updates
        adj_list[edge.first.first].insert(make_pair(edge.first.second,edge.second));
        adj_list[edge.first.second].insert(make_pair(edge.first.first,edge.second)); 

    }

    // pick any vertex,capture it and start building the tree
    captured[0]=1;
    num_captured++;
    for(auto neighbor:adj_list[0]){
        pair<int,int> edge;
        pair<int,pair<int,int>> weighted_edge;
        // neighbor.first is the neighbor vertex
        edge = make_pair(0,neighbor.first);
        // neighbor.second is the weight of edge (0<-->neighbor.first)
        weighted_edge = make_pair(neighbor.second,edge);
        pq.push(weighted_edge);
    }

    while(!pq.empty()){
        pair<int,pair<int,int>> node=pq.top();
        pq.pop();
        // already captured continue since pq will 
        // have same vertex queued with different priorities
        if(captured[node.second.second] == 1){
            continue;
        }
        
        //capture the node
        captured[node.second.second]=1;
        // add the edge to mst
        mst.push_back(node.second);
        // update cost
        total_cost += node.first;
        // update number of captured verticies
        num_captured++;
        for(auto neighbor : adj_list[node.second.second]){
            pair<int,int> edge;
            pair<int,pair<int,int>> weighted_edge;
            // neighbor.first is the neighbor vertex of
            // node.second.second
            edge = make_pair(node.second.second,neighbor.first);
            // neighbor.second is the weight 
            // of edge (node.second.second<-->neighbor.second)
            weighted_edge = make_pair(neighbor.second,edge); 
            pq.push(weighted_edge);
            
        }

    }
    if(num_captured != n){
        // did not capture all vertices
        return {};
    }
    cout << " Prim's total cost : " << total_cost << endl;
    return mst;

}

vector<pair<int,int>> dijkstra_SPFT(int n,int src,int dst,vector<pair<pair<int,int>,int>> &weighted_edge_list)
{
    // distance of every vertex from src
    vector<int> distance(n,-1);
    // init distance[src] to 0
    distance[src]=0;

    // captured array for every node
    vector<int> captured(n,-1);
    // initialize captured[src] to 1
    captured[src]=1;

    // list of edges that form the spf tree
    vector<pair<int,int>> spft;

    // define graph as adj_list
    // vertex[0] -> {(vertex-01,cost-01) , (vertex-02,cost-02) .... }
    // vertex[1] -> {(vertex-11,cost-11) , (vertex-12,cost-12) .... }
    // vertex[n-1] -> {(vertex..1,cost..1) , (vertex..2,cost..2) .... }
    map<int,set<pair<int,int>>> adj_list;

    // build graph - since this is a directed graph 
    // we dont do the other direction
    for(auto edge:weighted_edge_list){
        adj_list[edge.first.first].insert(make_pair(edge.first.second,edge.second));
    }

    // define the datastructure for holding the vertices forming fringe edge
    // priority - u--->v where u is the vertex that is capturing vertex v
    //priority_queue<pair<int,pair<int,int>>> pq;
    // creation of min priority queue based on 1st element of pair
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;

    // add all neighbors of src to the pq
    for(auto neighbor:adj_list[src]){
        // distance to the current vertex is 
        // the distance to source + weight of edge
        // difference between Prim's and Dijkstra
        int weight=distance[src] + neighbor.second;
        pair<int,int> edge=make_pair(src,neighbor.first);
        pair<int,pair<int,int>> weighted_edge=make_pair(weight,edge);
        pq.push(weighted_edge);
    }

    while(!pq.empty()){
        pair<int,pair<int,int>> node = pq.top();
        pq.pop();

        if(captured[node.second.second] != -1){
            continue;
        }
        //capture the node
        captured[node.second.second] = 1;
        // update distance
        distance[node.second.second]=node.first;
        // update the spft
        spft.push_back(node.second);
        for(auto neighbor:adj_list[node.second.second]){
            if(captured[neighbor.first] == -1){
                // distnce to the current vertex is 
                // the distance to source + weight of edge
                // difference between Prim's and Dijkstra
                int weight=distance[node.second.second] + neighbor.second;
                pair<int,int> edge=make_pair(node.second.second,neighbor.first);
                pair<int,pair<int,int>> weighted_edge=make_pair(weight,edge);
                pq.push(weighted_edge);
            }
        }
    }
    cout << "Dijkstra's shortest distance between : " << src << " , " << dst << " is : " << distance[dst] << endl;
    return spft;

}


int main()
{
    n=10;
    add_edge(0,1);
    add_edge(1,2);
    add_edge(2,3);
    add_edge(0,2);
    add_edge(0,3);
    add_edge(0,4);

    add_edge(2,7);

    add_edge(4,5);
    add_edge(6,7);
    add_edge(6,9);
    add_edge(8,9);
    cout << "num components : " << union_find(n,edge_list)<<endl;
    add_weighted_edge(0,1,1);
    add_weighted_edge(1,2,2);
    add_weighted_edge(2,3,3);
    add_weighted_edge(0,2,4);
    add_weighted_edge(0,3,5);
    add_weighted_edge(0,4,6);

    add_weighted_edge(2,7,7);

    add_weighted_edge(4,5,8);
    add_weighted_edge(6,7,9);
    add_weighted_edge(6,9,10);
    add_weighted_edge(8,9,11);
    add_weighted_edge(7,8,12);
    vector<pair<int,int>> k_mst = kruskal_MST(n,weighted_edge_list);
    cout << " Kruskal MST  : " << endl;
    for(auto edge:k_mst){
        cout << " " << edge.first << "---" << edge.second << endl;
    }
    vector<pair<int,int>> p_mst = prim_MST(n,weighted_edge_list);
    cout << " Prim MST  : " << endl;
    for(auto edge:p_mst){
        cout << " " << edge.first << "---" << edge.second << endl;
    }
    int src=0;
    int dst=6;
    vector<pair<int,int>> d_spft = dijkstra_SPFT(n,src,dst,weighted_edge_list);
    cout << " dijkstra SPFT rooted at : " << src << endl;
    for(auto edge:d_spft){
        cout << " " << edge.first << "---" << edge.second << endl;
    }

}

