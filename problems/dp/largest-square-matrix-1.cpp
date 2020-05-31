#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


// @param n : number of rows in mat
// @param m : number of columns in mat
// @param mat: 2D matrix of zeros and ones
int largest_sub_square_matrix(int n, int m, vector<vector<int>> &mat)
{
    // this is an optimization problem with combinatorial explosion.
    // the possibilities of largest square matrix in a nxm matrix is 
    // exponential from a 1x1 to a mxn sub problems and many of these 
    // subproblems have to be evaluated multiple times
    // lets write a objective function f(i,j) as an extension of the  
    // square matrix f(i-1,j-1) 
    // 

    vector<vector<int>> dptable(n,vector<int>(m,0));

    // base cases
    // row 0 and col 0 
    // each element of the above row and col try to extend a previous 
    // matrix (non existant) . So they will be 1 if mat[0][col] = 1
    // and mat[row][0] = 1
    // these are the definitions of  matrices of size [1][1]
    int max_sub_square=0;
    for(int r=0;r<n;r++){
        dptable[r][0] = mat[r][0];
        max_sub_square = max(max_sub_square,dptable[r][0]);
    }
    for(int c=0;c<m;c++){
        dptable[0][c] = mat[0][c];
        max_sub_square = max(max_sub_square,dptable[0][c]);
    }
    cout << "init done " << endl;
    // for a general r,c
    
    for(int r=1;r<n;r++){
        for(int c=1;c<m;c++){
            // this will be dptable[r-1][c-1] + 1 if
            // it extends the square matrix
            // else it will be mat[r][c]
            if(mat[r][c] == 0){
                dptable[r][c]=0;
            }else{
                // there is a possibility element could extend the matrix
                // num of cols and rows to check for 1 is dptable[r-1][c-1]
                int num_cells_to_check=dptable[r-1][c-1];
                bool extends=true;    
                //check cells to the left
                for(int offset=1;offset<=num_cells_to_check;offset++){
                    if(dptable[r][c-offset] == 0){
                        extends=false;
                    }
                }
                //check cells above  
                for(int offset=1;offset<=num_cells_to_check;offset++){
                    if(dptable[r-offset][c] == 0){
                        extends=false;
                    }
                }
                if(extends == false){
                    dptable[r][c]=mat[r][c];
                }else{
                    dptable[r][c]=dptable[r-1][c-1]+1;
                }
                max_sub_square = max(max_sub_square,dptable[r][c]);
            }
        }
    }
#if 1
    // print the dptable
    for(auto row:dptable){
        cout << endl;
        for(auto cell : row){
            cout << " " << cell;
        }
    }
#endif
    //find the max element in the dptable    
    return max_sub_square; 
}


int main()
{
    string mat_rows_temp;
    getline(cin, mat_rows_temp);

    int n = stoi(ltrim(rtrim(mat_rows_temp)));

    string mat_columns_temp;
    getline(cin, mat_columns_temp);

    int m = stoi(ltrim(rtrim(mat_columns_temp)));

    vector<vector<int>> mat(n);

    for (int i = 0; i < n; i++)
    {
        mat[i].resize(m);
        string mat_row_temp_temp;
        getline(cin, mat_row_temp_temp);

        vector<string> mat_row_temp = split(rtrim(mat_row_temp_temp));

        for (int j = 0; j < m; j++)
        {
            int mat_row_item = stoi(mat_row_temp[j]);
            mat[i][j] = mat_row_item;
        }
    }
    ostream &fout = cout;
    int ans = largest_sub_square_matrix(n, m, mat);
    cout << ans << endl;

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

