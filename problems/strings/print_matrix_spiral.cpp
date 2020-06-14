#include <bits/stdc++.h>

using namespace std;

string printSpirally(vector < vector < char > > matrix) {
    string result;
    int nrows=matrix.size();
    int ncols=(nrows==0)?0:matrix[0].size();

    int sr=0,sc=0,er=nrows-1,ec=ncols-1;

    bool toprint=true;
    while(toprint){
        toprint=false;
        //print top row l to r
        for(int c=sc;c<=ec;c++){
            if(sr<=er){
                result.push_back(matrix[sr][c]);
                toprint=true;
            }
        }
        sr++;
        // print right col t to b
        for(int r=sr;r<=er;r++){
            if(sc<=ec){
                result.push_back(matrix[r][ec]);
                toprint=true;
            }
        }
        ec--;
        // print bottom row r to l
        for(int c=ec;c>=sc;c--){
            if(sr<=er){
                result.push_back(matrix[er][c]);
                toprint=true;
            }
        }
        er--;
        // print left col b to t
        for(int r=er;r>=sr;r--){
            if(sc<=ec){
                result.push_back(matrix[r][sc]);
                toprint=true;
            }
        }
        sc++;
    }
    return result;
}


int main() {
    ostream &fout = cout;
    string res;
    
    int _matrix_rows = 0;
    int _matrix_cols = 0;
    cin >> _matrix_rows >> _matrix_cols;
    vector< vector < char > > _matrix(_matrix_rows);
    for(int _matrix_i=0; _matrix_i<_matrix_rows; _matrix_i++) {
        for(int _matrix_j=0; _matrix_j<_matrix_cols; _matrix_j++) {
            char _matrix_tmp;
            cin >> _matrix_tmp;
            _matrix[_matrix_i].push_back(_matrix_tmp);
        }
    }
    
    res = printSpirally(_matrix);
    fout << res << endl;
    
    
    return 0;
}


