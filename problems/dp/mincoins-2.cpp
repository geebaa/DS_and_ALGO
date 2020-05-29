#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
* Complete the 'minimum_coins' function below.
*
* The function accepts INTEGER ARRAY and INTEGER as parameter.
* Return INTEGER.
*/
int minimum_coins(vector<int> coins, int value) 
{
    vector<int> dptable(value+1,-1);
    int result;
    //base case 
    dptable[0]=0;
    for(int i=1;i<=value;i++){
        int min=INT_MAX;
        int curr=0;
        for(auto j:coins){
            if( (i - j) >= 0){
                curr=dptable[i-j];
                if(min > curr){
                    min=curr;
                }
            }
        }
        dptable[i]=min+1;
        //cout << "i : " << i << "dptable[i] : " << dptable[i] << endl;
    }
    result = dptable[value];
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


