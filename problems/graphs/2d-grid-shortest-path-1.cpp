#include <bits/stdc++.h>

using namespace std;

// since a node can be visited multiple times ,
// parent is not a single node but a stack of nodes
// each node is a pair <int,int> representing a cell
// in the grid
map<pair<int,int>,stack<pair<int,int>>> parent;

// this is a bag of keys collected while traversing the maze 

unordered_set<char> keys;
// start and goal coordinates
pair<int,int> start={-1,-1};
pair<int,int> goal={-1,-1};
int n_rows=0;
int n_cols=0;

bool isNeighbor(pair<int,int> node,vector <string> &grid,unordered_set<char> &keys,set<pair<int,int>> &curr_q)
{
    // node is a valid neighbor 
    // if its not in curr_q already
    //       and
    // if its inside the grid
    //       and 
    // its not water
    //       and
    // its not locked door (door with out key)

    // node already queued up for processing
    if(curr_q.find(node) != curr_q.end()){
        return false;
    }

    // node off the grid
    if( (node.first <0) || (node.first>=n_rows) || (node.second < 0) || (node.second >= n_cols) ){
        return false;
    }
    // if node is water
    if(grid[node.first][node.second] == '#'){
        return false;
    }
    // door without key
    if(grid[node.first][node.second] >= 'A' && grid[node.first][node.second] <= 'J'){
        if(keys.find(tolower(grid[node.first][node.second])) == keys.end()){
            return false;
        }
    }
    // either land or door with key and not already in the q
    return true;
}


vector<pair<int,int>> getNeighbors(vector <string> &grid,pair<int,int>node,unordered_set<char> &keys,set<pair<int,int>> &curr_q)
{
    vector<pair<int,int>> neighbors;
    // potential neighbors are 4 cells (node,bottom,right,left)
    pair<int,int> potential_neighbor;

    //top
    potential_neighbor=make_pair(node.first-1,node.second);
    if(isNeighbor(potential_neighbor,grid,keys,curr_q)){
        neighbors.push_back(potential_neighbor);
    }

    //left
    potential_neighbor=make_pair(node.first,node.second-1);
    if(isNeighbor(potential_neighbor,grid,keys,curr_q)){
        neighbors.push_back(potential_neighbor);
    }

    //right
    potential_neighbor=make_pair(node.first,node.second+1);
    if(isNeighbor(potential_neighbor,grid,keys,curr_q)){
        neighbors.push_back(potential_neighbor);
    }

    //bottom
    potential_neighbor=make_pair(node.first+1,node.second);
    if(isNeighbor(potential_neighbor,grid,keys,curr_q)){
        neighbors.push_back(potential_neighbor);
    }

    return neighbors;
}
// traverses from start to goal accumulating the
// parent array information.

void bfs(pair<int,int> &start,pair<int,int> &goal,vector <string> &grid){

    
    queue<pair<int,int>> q;
    set<pair<int,int>> curr_q; // set of nodes already backed up in q

    // this is used by get neighbors to check if it is
    // returning the same neighbor under processing 
    q.push(start);
    curr_q.insert(start);
    // note - there is no visited tracking since
    // cells can be visited multiple times
    // terminating condition will be that the goal is reached
    // suppose the goal cannot be reached -- this will loop for ever!!!!
    while(!q.empty()){
        pair<int,int> node =q.front();
        q.pop();
        curr_q.erase(node); // remove the node from set
        // if the node is a key collect it
        if(grid[node.first][node.second] >= 'a' && grid[node.first][node.second] <= 'j'){
            keys.insert(grid[node.first][node.second]);
        }
        vector<pair<int,int>> neighbors;
        neighbors = getNeighbors(grid,node,keys,curr_q);
        for(auto neighbor:neighbors){
            if(neighbor == goal){
                //reached the goal
                cout << "parent of : " << neighbor.first << " , " << neighbor.second << " is " << node.first << " , " << node.second << endl;
                parent[neighbor].push(node);
                return;
            }else{
                
                cout << "parent of : " << neighbor.first << " , " << neighbor.second << " is " << node.first << " , " << node.second << endl;
                // explore this neighbor
                parent[neighbor].push(node);
                q.push(neighbor);
                // insert the node in set
                curr_q.insert(neighbor);
            }
        }
    }

    // This algorithm will never have q empty
    // will not reach here
    return;
}

/*
 * Complete the function below.
 */
vector < vector<int> > find_shortest_path(vector <string> grid) {
    vector < vector<int> > shortest_path;
    n_rows=grid.size();
    n_cols=n_rows?grid[0].size():0;

    //traverse the grid to find the start and goal
    for(int i=0;i<n_rows;i++){
        for(int j=0;j<n_cols;j++){
            if(grid[i][j] == '@'){
                start=make_pair(i,j);
            }
            if(grid[i][j] == '+'){
                goal=make_pair(i,j);
            }
            if( (start != make_pair(-1,-1) ) && (goal != make_pair(-1,-1)  ) )
            {
                // found both start and goal coordinates
                break; //from inner for loop
            }
        }
        if( (start != make_pair(-1,-1) ) && (goal != make_pair(-1,-1)  ) )
        {
            // found both start and goal coordinates
            break; // from outer for loop
        }
    }
    cout << "start : " << start.first << " , " << start.second << " goal : " << goal.first << " , " << goal.second << endl;  
    // launch bfs to find shortest path

    bfs(start,goal,grid);

    cout << "bfs returned " << endl;
    // construct the path from start to goal from 
    // parent
    pair<int,int> curr_node=goal;
    vector<int> curr_node_vector;
    while(true)
    {
        curr_node_vector.clear();
        curr_node_vector.push_back(curr_node.first);
        curr_node_vector.push_back(curr_node.second);
        shortest_path.push_back(curr_node_vector);
        if(!parent[curr_node].empty()){
            pair<int,int> next_node; 
            next_node=parent[curr_node].top();
            parent[curr_node].pop();
            curr_node=next_node;
        }else{
            break;
        }
    } 
    curr_node_vector.clear();
    curr_node_vector.push_back(start.first);
    curr_node_vector.push_back(start.second);
    shortest_path.push_back(curr_node_vector);
    reverse(shortest_path.begin(),shortest_path.end());

    return shortest_path;
}


int main()
{
    ostream &fout = cout;

    vector < vector<int> > res;
    int grid_size = 0;
    cin >> grid_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<string> grid;
    for(int i = 0; i < grid_size; i++) {
        string grid_item;
        getline(cin, grid_item);
        grid.push_back(grid_item);
    }

    res = find_shortest_path(grid);
    for(int res_i = 0; res_i < res.size(); res_i++) {
        for(int res_j = 0; res_j < res[res_i].size(); res_j++) {
            fout << res[res_i][res_j] << " ";;
        }
        fout << endl;
    }

    
    return 0;
}


