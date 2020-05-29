#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int helper(vector<int> &coins, int value,vector<int> &memo){

    if(value==0){
        //cout << "value : " << value << "return : " << 0 << endl; 
        memo[value] = 0;
        return 0;
    }
    if(memo[value] != -1){
        //cout << "memo[value] : " << memo[value] << endl; 
        return memo[value];
    }
    int min=INT_MAX;
    int curr=0;
    for(auto i:coins) {
        if((value - i) >= 0){
            curr=helper(coins,value-i,memo);
            if(min > curr) {
                min=curr;
            }
        }
    }
    //cout << "value : " << value << "min + 1 : " << min+1 << endl; 
    memo[value]=min+1;
    return memo[value];
}

/*
* Complete the 'minimum_coins' function below.
*
* The function accepts INTEGER ARRAY and INTEGER as parameter.
* Return INTEGER.
*/
int minimum_coins(vector<int> coins, int value) 
{
    vector<int> memo(value+1,-1);
    int result;
    // Write your code here
    result = helper(coins,value,memo);

    return result;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        string coin;
        getline(cin, coin);

        coins[i] = stoi(ltrim(rtrim(coin)));
    }
    
    string value_temp;
    getline(cin, value_temp);

    int value = stoi(ltrim(rtrim(value_temp)));
    
    ostream &fout = cout;

    int result = minimum_coins(coins, value);
    fout << result;

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


