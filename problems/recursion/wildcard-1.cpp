#include <bits/stdc++.h>

using namespace std;

void helper(string &s,int i,string &slate,vector<string> &result)
{
    //base case 
    if(i == s.length()){
        result.push_back(slate);
        return;
    }

    if(s[i] == '?'){
        // make choice '0'
        slate.push_back('0');
        helper(s,i+1,slate,result);
        slate.pop_back();

        // make choice '1'
        slate.push_back('1');
        helper(s,i+1,slate,result);
        slate.pop_back();
    }else{
        slate.push_back(s[i]);
        helper(s,i+1,slate,result);
        slate.pop_back();
    }


}

/*
 * Complete the find_all_possibilities function below.
 */
vector<string> find_all_possibilities(string s) {
    /*
     * Write your code here.
     */
    vector<string> result;
    string slate;
    helper(s,0,slate,result);
    return result;
}

int main()
{
    ostream &fout = cout;

    string s;
    getline(cin, s);

    vector<string> res = find_all_possibilities(s);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    

    return 0;
}

