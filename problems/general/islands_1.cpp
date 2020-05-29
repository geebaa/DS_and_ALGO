#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    queue<pair<int,int>> bfs_queue;

    void bfs(int &r,int &c,vector<vector<char>>& grid,int &num_rows,int&num_cols){
        cout << "bfs called : row : " << r << " col : "<< c << endl; 
        pair<int,int> elem = make_pair(r,c);
        bfs_queue.push(elem);
        pair<int,int> neigh;
        //mark visited
        grid[r][c]='0';
        while(!bfs_queue.empty()){

            pair<int,int> curr_coordinate = bfs_queue.front();
            bfs_queue.pop();
            int row=curr_coordinate.first;
            int col=curr_coordinate.second;
            cout << " visited : row : "<<row<< " col : " << col<<endl; 
            //remove from to_visit
            //to_visit.erase(make_pair(row,col));
            //add neighbors to queue
            if( (row-1) >= 0 ) {
                if(grid[row-1][col] == '1'){
                    // this is a unvisited neighbor
                    neigh = make_pair(row-1,col);
                    bfs_queue.push(neigh);
                    //mark visited
                    grid[row-1][col]='0';
                }
            }
            if( (col -1) >= 0){
                if(grid[row][col-1] == '1'){
                    // this is a unvisited neighbor
                    neigh = make_pair(row,col-1);
                    bfs_queue.push(neigh);
                    //mark visited
                    grid[row][col-1]='0';
                }
                
            }
            if( (col+1) < num_cols){
                if(grid[row][col+1] == '1'){
                    // this is a unvisited neighbor
                    neigh = make_pair(row,col+1);
                    bfs_queue.push(neigh);
                    //mark visited
                    grid[row][col+1]='0';
                }
            }
            if( (row+1) < num_rows){
                if(grid[row+1][col] == '1'){
                    // this is a unvisited neighbor
                    neigh = make_pair(row+1,col);
                    bfs_queue.push(neigh);
                    //mark visited
                    grid[row+1][col]='0';
                }
            }            
        }
        return ;
    }
        
    
    int numIslands(vector<vector<char>>& grid) {
        int components=0;
        int rows=grid.size();
        int cols=rows?grid[0].size():0;
        //set < pair <int,int> > to_visit;
        //set < pair <int,int> >::iterator itr;
        int r,c;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'){
                    components++;
                    bfs(i,j,grid,rows,cols);
                    //to_visit.insert(make_pair(i,j));
                }
            }
        }    
/*
        while(!to_visit.empty()){
                itr=to_visit.begin();
                r=itr->first;
                c=itr->second;
                components++;
                bfs(r,c,grid,rows,cols,to_visit);
                //if(grid[i][j] == '1'){
                //    components++;
                //    bfs(i,j,grid,rows,cols,to_visit);
                //}
                
            
        }
*/
        cout << "finished bfs" << endl;
        return components;
    }
};
//vector<vector<char>> grid={{"1","1"},{"0","0"}};
//vector<vector<char>> grid={{'1','1','1'},{'0','1','1'}};
vector<vector<char>> grid={{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};

vector<vector<char>> grid1={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};

vector<vector<char>> grid2={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

int main()
{
    Solution mysol;
    cout << endl;
    cout << "num islands : " << mysol.numIslands(grid1)<<endl;
    cout << "num islands : " << mysol.numIslands(grid2)<<endl;
    cout << "num islands : " << mysol.numIslands(grid);

}

