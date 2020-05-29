#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
* Complete the 'findPascalTriangle' function below.
*
* The function accepts INTEGER as parameter.
* Return 2D INTEGER ARRAY.
*/
const int M=1000000007 ;
vector<vector<int>> findPascalTriangle(int n) 
{
    vector<vector<int>> result={{1}};
    // Write your code here
    

    for(int i=1;i<n;i++){
        vector<int> prev_row = result[i-1];
        vector<int> curr_row;
        //cout << "prev_row : " << i-1 << endl;
        //for(auto k:prev_row){
        //    cout << " " << k;
        //}
        //cout << endl;
        for(int j=0;j<=i;j++){
            int curr_cell = 0;
            if( (j-1)>=0 ){
                curr_cell = prev_row[j-1];
            }
            //cout << "1curr_cell : " << curr_cell;
            if(j != i){
                curr_cell += prev_row[j];
                curr_cell = curr_cell % M;
            }
            //cout << " 2curr_cell : " << curr_cell;
            curr_row.push_back(curr_cell);
            //cout << endl;
        }
        result.push_back(curr_row);
    }
    return result;
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    
    ostream &fout = cout;

    vector<vector<int>> result = findPascalTriangle(n);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
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

	
