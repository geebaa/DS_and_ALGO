#include <bits/stdc++.h>

using namespace std;

void helper(string &s,int i,vector <string > &result,string &curr_result){
    //base case
    if(i==s.length()){
        result.push_back(curr_result);
        return;
    }

    // recursive case

    // include path
    curr_result.push_back(s[i]);
    helper(s,i+1,result,curr_result);
    curr_result.pop_back();
    // exclude path
    helper(s,i+1,result,curr_result);
}

vector <string> generate_all_subsets(string s) {

    vector <string > result;
    string curr_result="";
    helper(s,0,result,curr_result);
    return result;

}


int main()
{
    ostream &fout = cout;

    vector <string> res;
    string s;
    getline(cin, s);

    res = generate_all_subsets(s);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}

