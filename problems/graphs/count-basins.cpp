#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

void printMatrix(int row_count, int col_count, vector< vector<int> > matrix) {
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int i=0;
pair<int,int> get_neighbor(pair<int,int> curr_cell,vector< vector<int> > &matrix,int &nrows,int &ncols)
{
    /*
        this function will look at the 5 cells (r,c) , (r-1,c),(r+1,c)
        (c-1,r), (c+1,r) and return the coordinate of the minimum value 
        in the matrix. Will start by assuming min is at (r,c)
    */
    int r=curr_cell.first;
    int c=curr_cell.second;
    int min=matrix[r][c];
    int nr=r,nc=c;
    if(r-1>=0){
        if(min > matrix[r-1][c]){
            min=matrix[r-1][c];
            nr=r-1;
            nc=c;
        }
    }
    if(r+1<nrows){
        if(min > matrix[r+1][c]){
            min=matrix[r+1][c];
            nr=r+1;
            nc=c;
        }
    }
    if(c-1>=0){
        if(min > matrix[r][c-1]){
            min=matrix[r][c-1];
            nc=c-1;
            nr=r;
        }
    }
    if(c+1<ncols){
        if(min > matrix[r][c+1]){
            min=matrix[r][c+1];
            nc=c+1;
            nr=r;
        }
    }
    return make_pair(nr,nc);
}

pair<int,int> find_sink(pair<int,int> curr_cell,vector< vector<int> > &matrix,vector< vector<int> > &newmatrix,int &nrows,int &ncols)
{
    pair<int,int> neighbor,sink;
    neighbor = get_neighbor(curr_cell,matrix,nrows,ncols);
    //base case -- we have reached sink if our neighbor is ourself
    if(neighbor == curr_cell){
        if(newmatrix[curr_cell.first][curr_cell.second] == -1){
            //new sink - use a new id
            newmatrix[curr_cell.first][curr_cell.second] = i;
            i++;
        }
        return curr_cell;
    }
    //recursive case - follow the path of neighbor till sink is reached.
    // optimization - launch recursive call only if the newmatrix has -1
    // in the neighbor cell
    if(newmatrix[neighbor.first][neighbor.second] == -1){
        sink = find_sink(neighbor,matrix,newmatrix,nrows,ncols);
        newmatrix[curr_cell.first][curr_cell.second]=newmatrix[sink.first][sink.second];
    }else{
        // if our neighbor is already found to be part of a basin 
        // just return neighbor
        sink=neighbor;
    }

    return sink;
}

vector<int> find_basins(vector< vector<int> > matrix) {
    //Write your code here
    // brute force
    int nrows=matrix.size();
    int ncols=(nrows==0)?0:matrix[0].size();
    vector<int> result;
    // assign unique id's to each cell in a new matrix
    vector< vector<int> > newmatrix(nrows,vector<int>(ncols,-1));

    // iterate thru the matrix to find the sink of every cell
    for(int r=0;r<nrows;r++){
        for(int c=0;c<ncols;c++){
            pair<int,int> curr_cell=make_pair(r,c);
            pair<int,int> sink_cell=find_sink(curr_cell,matrix,newmatrix,nrows,ncols);
            newmatrix[r][c]=newmatrix[sink_cell.first][sink_cell.second];
        }
    }

    // now the matrix is filled with one id for one basin . Definition of basin
    // is a list of neighbors that drain to the same sink.
    
    vector<int>basin_count(i,0) ;
    // i is the numbe of basins
    vector<int>count(i,0); // number of distinct counts possible

    for(int r=0;r<nrows;r++){
        //cout <<endl;
        for(int c=0;c<ncols;c++){
            //cout << " " << newmatrix[r][c];
            basin_count[newmatrix[r][c]]++;
        }
    }
    sort(basin_count.begin(),basin_count.end());
    return basin_count; 

}


int main() {
    string row_count_temp;
    getline(cin, row_count_temp);

    int row_count = stoi(ltrim(rtrim(row_count_temp)));

    string col_count_temp;
    getline(cin, col_count_temp);

    int col_count = stoi(ltrim(rtrim(col_count_temp)));

    vector< vector<int> > matrix(row_count);
    for (int i = 0; i < row_count; i++) {
        matrix[i].resize(col_count);

        string row;
        getline(cin, row);

        vector<string> values = split(rtrim(row));

        for (int j = 0; j < col_count; j++) {
            matrix[i][j] = stoi(values[j]);
        }
    }

    ostream &fout = cout;

    // printMatrix(row_count, col_count, matrix);

    vector<int> basin_sizes = find_basins(matrix);

    for (int i = 0; i < basin_sizes.size(); i++)
        fout << basin_sizes[i] << endl;

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

