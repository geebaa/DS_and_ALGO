#include <bits/stdc++.h>

using namespace std;

void helper(string &s,int i,int target,string &slate,vector <string> &result){

    //base case
    if(i == s.length()){
        result.push_back(slate);
        return;
    }

    //recursive case
    // join choice
    slate.push_back(s[i]);
    helper(s,i+1,target,slate,result);
    slate.pop_back();
    // '*' choice
    slate.push_back('*');
    slate.push_back(s[i]);
    helper(s,i+1,target,slate,result);
    slate.pop_back();
    slate.pop_back();
    // '+' choice
    slate.push_back('+');
    slate.push_back(s[i]);
    helper(s,i+1,target,slate,result);
    slate.pop_back();
    slate.pop_back();

}

/*
 * Complete the function below.
 */
vector <string> generate_all_expressions(string s, long long int target) {
    vector <string> result;
    string slate;        
    slate.push_back(s[0]);
    helper(s,1,target,slate,result);
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

