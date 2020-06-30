#include <bits/stdc++.h>
using namespace std;

void prims(vector<vector<int>> &adj_matrix,int &min_cost,int start)
{
    // number of nodes 0 to n-1
    int n = adj_matrix.size();
    unordered_set<int> captured;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_pq;
    
    //setup for prims
    // capture the start node , push all its neighbors to the min_pq
    captured.insert(start);
    min_cost=0;
    for(int c=0;c<n;c++){
        if(adj_matrix[start][c]==0){
            continue;
        }else{
            min_pq.push(make_pair(adj_matrix[start][c],c));
        }
    }
    
    // explore the graph
    while(!min_pq.empty()){
        pair<int,int> weighted_edge=min_pq.top();
        min_pq.pop();
        if(captured.find(weighted_edge.second)!= captured.end()){
            continue;
        }
        
        // while capturing an edge , update min_cost
        captured.insert(weighted_edge.second);
        min_cost+=weighted_edge.first;
        
        for(int c=0;c<n;c++){
            if(adj_matrix[weighted_edge.second][c]==0){
                continue;
            }else{
                min_pq.push(make_pair(adj_matrix[weighted_edge.second][c],c));
            }
        }
        
    }
}

int main() {
    int min_cost;
    vector<vector<int>> adj_matrix1={{0, 1, 2, 3, 4},
                                    {1, 0, 5, 0, 7},
                                    {2, 5, 0, 6, 0},
                                    {3, 0, 6, 0, 0},
                                    {4, 7, 0, 0, 0}};

    vector<vector<int>> adj_matrix2={{0, 1, 1, 100, 0, 0},
                                     {1, 0, 1, 0, 0, 0},
                                     {1, 1, 0, 0, 0, 0},
                                     {100, 0, 0, 0, 2, 2},
                                     {0, 0, 0, 2, 0, 2},
                                     {0, 0, 0, 2, 2, 0}};
                                    
    prims(adj_matrix1,min_cost,0);
    cout << "min cost 1 : "<< min_cost<<endl;
    prims(adj_matrix2,min_cost,0);
    cout << "min cost 2 : "<< min_cost<<endl;
    return min_cost;
}
