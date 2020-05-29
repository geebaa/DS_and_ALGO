#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
Complete the fumction numberOfPaths
The fumction takes integers 2D integer array, matrix, as parameter.
*/
int numberOfPaths(vector<vector<int>> matrix) {
    int result ;
    vector<int> row=matrix[0];
    int num_cols = row.size();
    int num_rows = matrix.size();
    int cell_value;
    int divisor=pow(10,9)+7;;
    vector<int> prev_row;
    vector<int> new_row;
    for(int r=0;r<num_rows;r++){
        for(int c=0;c<num_cols;c++){
            if(matrix[r][c] == 0){
                cell_value=0;
            }else if( (r==0) && (c==0 )) {
                cell_value=matrix[r][c];
            }else if(r==0){
                cell_value=new_row[c-1];
            }else if(c==0) {
                cell_value=prev_row[c];
            } else {
                cell_value=new_row[c-1]+prev_row[c];
            }
            cell_value=(cell_value)%(divisor);
            new_row.push_back(cell_value);
        }
        prev_row=new_row;
        new_row.clear();
    }
    result = prev_row[num_cols-1];
    return result;
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

