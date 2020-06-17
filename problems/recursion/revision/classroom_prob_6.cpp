#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void print_board(vector<int> &board)
{
    for(auto cell:board){
        cout << " " << cell;
    }
    cout <<endl;
}

void print_all_boards(vector<vector<int>> &result)
{
    for(auto board:result){
        print_board(board);
    }
}

bool isConflict(vector<int> &board,int index)
{
    // board is a chess board where the index is row and 
    // value is column
    if(index<0){
        return false;
    }
    //check if the placement at index with rest of the board
    int x2=index;
    int y2=board[index];
    for(int i=0;i<index;i++){
        int x1=i;
        int y1=board[i];

        // check for same column
        if(y1 == y2){
            return true;
        }
        // check diagonals
        if( ((x2-x1) == (y2-y1)) ||
            ((x2-x1) == -(y2-y1))
        ){
            return true;
        }
    }
    return false;
}

// place_nq1 approach spawns a recursive child for every possible placement 
// in the recursive child it check if the previous placement 
// is in conflict and backtracks
void place_nq1(int &n,int i,vector<int> &board)
{
    // backtracking case
    // if the last placement resulted in conflict backtrack
    if( isConflict(board,i-1)){
        //backtrack
        return;
    }
    //base case
    if(i==n){
        // placed all queens on the board
        result.push_back(board);
        //print_board(board);
        return;
    }

    //recursive case
    for(int j=0;j<n;j++){
        board[i]=j;//place queen at i,j
        if(i+1 <= n) {
            place_nq1(n,i+1,board);
        }
        board[i]=-1;
    }
}

// place_nq2 approach does not spawn a recursive child
// if the current placement has a conflict
void place_nq2(int &n,int i,vector<int> &board)
{
    //base case
    if(i==n){
        // placed all queens on the board
        result.push_back(board);
        return;
    }

    //recursive case
    for(int j=0;j<n;j++){
        board[i]=j;//place queen at i,j
        if(isConflict(board,i)){
            continue;
        }
        place_nq2(n,i+1,board);// move to next_position
        board[i]=-1;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> board(n,-1);
    //place_nq1(n,0,board);
    place_nq2(n,0,board);
    print_all_boards(result);
}

