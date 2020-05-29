#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> edge_list; // edges in graph
int n; // number of vertices 0 to n-1

void add_edge(int s,int d){
    pair<int,int> edge=make_pair(s,d);;
    edge_list.push_back(edge);
}


// Root is a node that is its own parent
// recurse and point all the children as 
// the recursion unwinds to the root
int find_root(int vertex,vector<int> &parent){
    if(vertex == parent[vertex]){
        return vertex;
    }
    parent[vertex] = find_root(parent[vertex],parent);
    return parent[vertex];
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
}

