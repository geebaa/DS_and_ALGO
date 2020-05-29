#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector <string> generate_all_expressions(string s, long long int target) {
    vector <string> result;
    return result;
}


int main()
{
    ostream &fout = cout;

    vector <string> res;
    string s;
    getline(cin, s);

    long long int target;
    cin >> target;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = generate_all_expressions(s, target);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}

