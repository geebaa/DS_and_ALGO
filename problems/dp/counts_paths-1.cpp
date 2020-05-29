#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
Complete the fumction numberOfPaths
The fumction takes integers 2D integer array, matrix, as parameter.
*/
int M=1000000007;
int numberOfPaths(vector<vector<int>> matrix) {
    int n_rows=matrix.size();
    int n_cols=(n_rows==0)?0:matrix[0].size();

    // 2D grid initialized to 0
    vector<vector<int>> dptable(n_rows,vector<int>(n_cols,0));

    // base cases
    // row 0 .. horizontal moves only
    // col 0 .. vertical moves only
    
    dptable[0][0]=matrix[0][0];
    // start from 1 so that col-1 does not fall of the dptable
    for(int col=1;col<n_cols;col++){
        if(matrix[0][col] == 0){
            dptable[0][col]=0;
        } else {
            dptable[0][col] = (dptable[0][col-1] % M); // ways to reach 
        }
    }
    // start from 1 so that row-1 does not fall of the dptable
    for(int row=1;row<n_rows;row++){
        if(matrix[row][0] == 0){
            dptable[row][0]=0;
        } else {
            dptable[row][0] = (dptable[row-1][0] % M); // ways to reach 
        }
    }

    for(int row=1;row<n_rows;row++){
        for(int col=1;col<n_cols;col++){
            if(matrix[row][col] == 0){
                //cell is blocked and paths is 0
                dptable[row][col] = 0;
            }else{
                // this cell can be reached from above and left
                dptable[row][col] = ((dptable[row-1][col] + dptable[row][col-1])%M);
            }
        }
    }
    return dptable[n_rows-1][n_cols-1];
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

    vector<vector<int>> matrix(n);

    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    int result = numberOfPaths(matrix);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


