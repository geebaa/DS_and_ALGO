#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void helper(int n,int s,int d, int t,vector<vector<int>> &result){

    // base case
    if(n == 1){
        vector<int> move;
        // capture move of disk from s to d 
        move.push_back(s);
        move.push_back(d);
        result.push_back(move); 
        return;
    }

    // recursive case
    // move n-1 discs from s to t 
    helper(n-1,s,t,d,result);

    vector<int> move;
    // capture move of disk from s to d
    move.push_back(s);
    move.push_back(d);
    result.push_back(move); 

    // move n-1 discs from t to s 
    helper(n-1,t,d,s,result);

}

/*
* Complete the 'tower_of_hanoi' function below.
*
* The function accepts INTEGER as parameter.
* Return 2D INTEGER ARRAY.
*/
vector<vector<int>> tower_of_hanoi(int n) 
{
    // Write your code here
    vector<vector<int>> result;

    helper(n,1,3,2,result);
    return result;
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    
    ostream &fout = cout;

    vector<vector<int>> result = tower_of_hanoi(n);
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


