#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<pair<int,int>> get_neighbor(vector<vector<char>> &grid,
                                   pair<int,int> &node,
                                   int &nrows,
                                   int &ncols)
{
    vector<pair<int,int>> neighbors;
    int r=node.first;
    int c=node.second;
    if(r-1>=0){
        if(grid[r-1][c] == 'O'){
            neighbors.push_back(make_pair(r-1,c));
        }
    }
    if(r+1 < nrows){
        if(grid[r+1][c] == 'O'){
            neighbors.push_back(make_pair(r+1,c));
        }
    }
    if(c-1>=0){
        if(grid[r][c-1] == 'O'){
            neighbors.push_back(make_pair(r,c-1));
        }
    }
    if(c+1<ncols){
        if(grid[r][c+1] == 'O'){
            neighbors.push_back(make_pair(r,c+1));
        }
    }
    return neighbors;
}

void bfs(vector<vector<char>> &grid,
         vector<vector<int>> &distance_grid,
         vector<vector<int>> &visited_grid,
         int &nrows,
         int &ncols)
{
    //find all guards and add to the q
    queue<pair<int,int>> q;
    for(int r=0;r<nrows;r++){
        for(int c=0;c<ncols;c++){
            if(grid[r][c]=='G'){
                q.push(make_pair(r,c));
                distance_grid[r][c]=0;
            }
        }
    }

    while(!q.empty()){
        pair<int,int> node=q.front();
        q.pop();
        vector<pair<int,int>> neighbors = get_neighbor(grid,node,nrows,ncols);
        for(auto neighbor : neighbors){
            if(distance_grid[neighbor.first][neighbor.second] == -1){
                // this 'neighbor' is reached first from 'node'
                distance_grid[neighbor.first][neighbor.second] = distance_grid[node.first][node.second] + 1;
                q.push(neighbor);
            }
        }
    }

}
vector<vector<int>> find_shortest_distance_from_a_guard(vector<vector<char>> grid) {

    /*
        every gaurd is a source and we start bfs from every source.
        start the bfs by adding all guards to the queue 
        then store the distance value when a cell is first reached
    */
    int nrows=grid.size();
    int ncols=(nrows==0)?0:grid[0].size();
    vector<vector<int>> distance_grid(nrows,vector<int>(ncols,-1));
    vector<vector<int>> visited_grid(nrows,vector<int>(ncols,-1));

    bfs(grid,distance_grid,visited_grid,nrows,ncols);

    return distance_grid;

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


