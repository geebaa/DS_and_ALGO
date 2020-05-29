#include <bits/stdc++.h>

using namespace std;

bool hasConflict(vector<int> &board,int &row,int &col)
{
    //cout << "row : " << row << "col : " << col << endl;
    // no queens in the col
    for (int i=0;i<row;i++)
    {
        if(board[i] == col)
        {
            //cout << "true1" << endl;
            return true;
        }
       
        //                                     y   =  x  +    C 
        // diagonals are the linear equations col = row  + board[row]
        //                                     y   =  -x  +    C 
        // if the current row,col is a solution to this linear equation
        // row,col has a conflict


        if( (row - col)  ==  (i - board[i] ) ) {
            //cout << "true2" << endl;
            return true;
        }
        if( (col +  row) ==  (i + board[i]) ) {
            //cout << "true3" << endl;
            return true;
        }
        
    }
    //cout << "false" << endl;
    return false;
}

void helper(vector < vector<string> > &result_vector, vector<int> &board,int &n,int curr_row)
{
    vector<string> board2d;
    string current_row;
    if(curr_row == n)
    {
        // placed all Q's
        //cout << "Board : " ;
        for(int i=0; i < board.size(); i++)
        {
            for(int j=0;j<n;j++)
            {
                current_row.push_back('-');
            }
            int queen_at = board.at(i);
            current_row[queen_at] = 'q';
            //cout << board.at(i) << ' ';
            board2d.push_back(current_row);
            current_row.erase();
        }
        result_vector.push_back(board2d);
        //board2d.erase();
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(!hasConflict(board,curr_row,i))
        {
            //place Q at (curr_row,i)
            board[curr_row] = i;
            // Find a place for another Q in curr_row + 1
            helper(result_vector,board,n,curr_row + 1);

        }
    }
    // did not find a place for Q

}

/*
 * Complete the function below.
 */
vector < vector<string> > find_all_arrangements(int n) {

    vector < vector<string> > result_vector;
    vector<int> board(n);
    helper(result_vector,board,n,0);
    return result_vector;
}


int main()
{
    ostream &fout = cout;

    vector < vector<string> > res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = find_all_arrangements(n);
    for(int res_i = 0; res_i < res.size(); res_i++) {
        for(int res_j = 0; res_j < res[res_i].size(); res_j++) {
            fout << res[res_i][res_j] << endl;
        }
        if (res_i != res.size() - 1) {
            fout << endl;
        }
    }
    
    return 0;
}

