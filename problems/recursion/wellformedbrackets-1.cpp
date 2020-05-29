#include <bits/stdc++.h>

using namespace std;


void helper(int &n,int left_count,int right_count,vector <string> &result,string &slate){

    // back tracking case
    if( (n-right_count) > (n-left_count) ){
        return;
    }

    //base case
    if( (left_count == 0) && (right_count == 0) ){
        result.push_back(slate);
        return;
    }

    // recursive case
    // choose "("
    if(left_count != 0){    
        slate.push_back('(');
        helper(n,left_count - 1,right_count,result,slate);
        slate.pop_back();
    }

    // choose ")"
    if(right_count != 0){    
        slate.push_back(')');
        helper(n,left_count,right_count - 1,result,slate);
        slate.pop_back();
    }
}


/*
 * Complete the function below.
 */
vector <string> find_all_well_formed_brackets(int n) {
    vector <string> result;
    string slate;
    helper(n,n,n,result,slate);
    return result;
}


int main()
{
    ostream &fout = cout;

    vector <string> res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = find_all_well_formed_brackets(n);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}
