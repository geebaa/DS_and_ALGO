#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector<pair<int,int> > getNeighbors(int rows,int cols,pair<int,int>node){
    // this function returns set of positions that 
    // a knight can reach from node.rows and cols define 
    // boundary .max size of return vactor will be 8
    int r=node.first,c=node.second;
    pair<int,int>neighbor;
    vector<pair<int,int> > neighbor_list;
    if ( (r-2) >= 0){
        if(c-1 >= 0){
            //neighbor-1
            neighbor = make_pair(r-2,c-1);
            neighbor_list.push_back(neighbor);
        }
        if(c+1 < cols){
            //neighbor-2
            neighbor = make_pair(r-2,c+1);
            neighbor_list.push_back(neighbor);
        }
    }
    if ( (r-1) >= 0){
        if(c-2 >= 0){
            //neighbor-3
            neighbor = make_pair(r-1,c-2);
            neighbor_list.push_back(neighbor);
        }
        if(c+2 < cols){
            //neighbor-4
            neighbor = make_pair(r-1,c+2);
            neighbor_list.push_back(neighbor);
        }
    }
    if ( (r+1) < rows){
        if(c-2 >= 0){
            //neighbor-5
            neighbor = make_pair(r+1,c-2);
            neighbor_list.push_back(neighbor);
        }
        if(c+2 < cols){
            //neighbor-6
            neighbor = make_pair(r+1,c+2);
            neighbor_list.push_back(neighbor);
        }
    }
    if ( (r+2) < rows){
        if(c-1 >= 0){
            //neighbor-7
            neighbor = make_pair(r+2,c-1);
            neighbor_list.push_back(neighbor);
        }
        if(c+1 < cols){
            //neighbor-8
            neighbor = make_pair(r+2,c+1);
            neighbor_list.push_back(neighbor);
        }
    }
    return neighbor_list;
}

void bfs(int rows,int cols,int start_row,int start_col,int end_row,int end_col,map <pair<int,int>,int> &visited,map <pair<int,int>,int> &distance)
{
    queue<pair<int,int> > q;
    pair <int,int> node=make_pair(start_row,start_col);
    pair <int,int> dest_node=make_pair(end_row,end_col);
    // mark visited
    visited[node]=1;
    distance[node]=0;
    distance[dest_node]=-1; // in case destination not reachable
    if(node == dest_node){
        //reached destination node
        distance[dest_node]=0; // dest_node is at a distance of 0 from node
        return;
    }
    // add to q to capture later
    q.push(node);

    while(!q.empty()){
        // capture the node
        node = q.front();
        q.pop();
        vector<pair<int,int> > neighbors=getNeighbors(rows,cols,node);
        cout << " Neighbor of : " << node.first << " , " << node.second << " - " << endl; 
        // iterate thru all neighbors
        for(auto neighbor:neighbors){
            cout  << neighbor.first << " , " << neighbor.second <<  endl; 
            if(visited.find(neighbor) == visited.end()){
                // node not visited 
                
                visited[neighbor]=1;
                distance[neighbor] = distance[node]+1;
                if(neighbor == dest_node){
                    // reached destination
                    cout  << "destination reached : "<< neighbor.first << " , " << neighbor.second <<  endl; 
                    return;
                }else{
                     // explore 
                     q.push(neighbor);
                }

            } else {
                //already visited node. do nothing
            }
        }
    }
    //cout << " q empty but not reached destination" << endl;
    return;
}
int find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col) {
    // Write your code here.

    map <pair<int,int>,int> visited,distance;
    bfs(rows,cols,start_row,start_col,end_row,end_col,visited,distance);
    return distance[make_pair(end_row,end_col)];


}


int main()
{
    ostream &fout = cout;

    int rows;
    cin >> rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int cols;
    cin >> cols;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int start_row;
    cin >> start_row;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int start_col;
    cin >> start_col;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int end_row;
    cin >> end_row;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int end_col;
    cin >> end_col;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int res = find_minimum_number_of_moves(rows, cols, start_row, start_col, end_row, end_col);

    fout << res << "\n";

    

    return 0;
}

