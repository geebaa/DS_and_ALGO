#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'find_shortest_distance_from_a_guard' function below.
 *
 * The function accepts the 2D CHARACTER ARRAY.
 * Returns 2D INTEGER ARRAY.
 */ 
int n_rows;
int n_cols;
// adj list for every cell in grid
map<pair<int,int>,vector<pair<int,int>>> adj_list;

bool isNodeWall(pair<int,int> &node,vector<vector<char>> &grid){
    return (grid[node.first][node.second] == 'W');
}
bool isNodeGuard(pair<int,int> &node,vector<vector<char>> &grid){
    return (grid[node.first][node.second] == 'G');
}
bool isNeighbor(pair<int,int> &node,vector<vector<char>> &grid)
{
    
    // valid neighbor is with in grid 
    //            and
    // not a wall
    if(node.first<0 || node.first >= n_rows || node.second < 0 || node.second >= n_cols){
        return false;
    }
    if(isNodeWall(node,grid)){
        return false;
    }


    return true;
}


vector<pair<int,int>> getNeighbors(pair<int,int> &node,vector<vector<char>> &grid)
{
    vector<pair<int,int>> neighbors;
    pair<int,int> potential_neighbor;
    // 4 potential neighbors
    potential_neighbor=make_pair(node.first-1,node.second);
    if(isNeighbor(potential_neighbor,grid)){
        neighbors.push_back(potential_neighbor);
    }
    potential_neighbor=make_pair(node.first+1,node.second);
    if(isNeighbor(potential_neighbor,grid)){
        neighbors.push_back(potential_neighbor);
    }
    potential_neighbor=make_pair(node.first,node.second-1);
    if(isNeighbor(potential_neighbor,grid)){
        neighbors.push_back(potential_neighbor);
    }
    potential_neighbor=make_pair(node.first,node.second+1);
    if(isNeighbor(potential_neighbor,grid)){
        neighbors.push_back(potential_neighbor);
    }
    return neighbors;

}

void bfs(vector<vector<char>> &grid,int r,int c,vector<vector<int>> &parent,vector<vector<int>> &visited,vector<vector<int>> &nearest_gaurd)
{

    // find the nearest gaurd from r,c
    queue<pair<int,int>> q;
    // accumulate distance in visited
    visited[r][c]=0;
    q.push(make_pair(r,c));
    vector<pair<int,int>> neighbors;
    pair<int,int> node=make_pair(r,c);
    if(isNodeWall(node,grid)){
        //terminating condition no graph exploration needed if 
        // current node is a wall
        nearest_gaurd[r][c]=-1;
        return;
    }
    while(!q.empty()){
        node=q.front();
        q.pop();
        if(isNodeGuard(node,grid)){
            //terminating condition
            // copy accumulated distance for r,c from visited 
            nearest_gaurd[r][c]=visited[node.first][node.second];
            return;
        }
        //neighbors = getNeighbors(node,grid);
        neighbors = adj_list[node];
        for(auto neighbor:neighbors){
            if(visited[neighbor.first][neighbor.second] == -1){
                //unexplored node accumulate distance as distance to parent +1
                // "node" is the parent of "neighbor"
                visited[neighbor.first][neighbor.second]=visited[node.first][node.second]+1;
                //add neighbor to q
                q.push(make_pair(neighbor.first,neighbor.second));
            }
        }
    }
    // no path to any guard store infinity
    nearest_gaurd[r][c] = -1;
    return;
}

vector<vector<int>> find_shortest_distance_from_a_guard(vector<vector<char>> grid) {
    n_rows=grid.size();
    n_cols=(n_rows==0)?0:grid[0].size();

    vector<vector<int>> nearest_gaurd(n_rows,vector<int>(n_cols,-1));


    for(int r=0;r<n_rows;r++){
        for(int c=0;c<n_cols;c++){
            pair<int,int> node=make_pair(r,c);
            vector<pair<int,int>> neighbors=getNeighbors(node,grid);
            for(auto neighbor:neighbors){
                adj_list[make_pair(r,c)].push_back(neighbor);
            }
        }
    }
    
    for(int r=0;r<n_rows;r++){
        for(int c=0;c<n_cols;c++){
            // for every vertex in the graph (cell in the grid)
            // calculate nearest distance
            vector<vector<int>> visited(n_rows,vector<int>(n_cols,-1));
            vector<vector<int>> parent(n_rows,vector<int>(n_cols,-1));
            //nearest_gaurd[r][c] will be populated with the nearest gaurd
            bfs(grid,r,c,parent,visited,nearest_gaurd);
        }
    }
    return nearest_gaurd;

}

int main()
{
    ostream &fout = cout;

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<char>> grid(n);

    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        string grid_row_temp = ltrim(rtrim(grid_row_temp_temp));

        for (int j = 0; j < m; j++) {
            char grid_row_item = grid_row_temp[j];

            grid[i][j] = grid_row_item;
        }
    }
    
    vector<vector<int>> result = find_shortest_distance_from_a_guard(grid);

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


