#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
Complete the fumction numberOfPaths
The fumction takes integers 2D integer array, matrix, as parameter.
*/
int maxPathSum(vector<vector<int>> matrix) {

    int n_rows = matrix.size();
    int n_cols = (n_rows==0)?0:matrix[0].size();

    vector<vector<int>> dptable(n_rows,vector<int>(n_cols,0));
    //basecase 0th row and 0th col
    dptable[0][0] = matrix[0][0];
    for(int row=1;row<n_rows;row++){
        dptable[row][0] = dptable[row-1][0] + matrix[row][0];
    }
    for(int col=1;col<n_cols;col++){
        dptable[0][col] = dptable[0][col-1] + matrix[0][col];
    }

    // build up the matrix along the DAG row by row
    for(int row=1;row<n_rows;row++){
        for(int col=1;col<n_cols;col++){
            dptable[row][col] = max(dptable[row-1][col],dptable[row][col-1]) + matrix[row][col];
        }
    }

    // retrace the path
    int r=n_rows-1,c=n_cols-1;
    stack <pair<int,int>> path;
    path.push(make_pair(r,c));
    while(r!=0 && c != 0 ){
        // check from where we landed
        if(dptable[r-1][c] < dptable[r][c-1]){
            //came from (r,c-1)
            c--;
        }else{
            //came from (r-1,c)
            r--;
        }
        path.push(make_pair(r,c));
    }

    while(r!=0 ){
       r--;
       path.push(make_pair(r,c));
    }
    while(c!=0 ){
       c--;
       path.push(make_pair(r,c));
    }

    while(!path.empty()){
        pair<int,int> cell;
        cell = path.top();
        path.pop();
        cout << cell.first << " " << cell.second << endl;
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

    int result = maxPathSum(matrix);

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

