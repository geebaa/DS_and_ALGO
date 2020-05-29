#include <bits/stdc++.h>

using namespace std;

void helper( vector <string > &result_vector , string &s , string curr_result, int index)
{
    if(index == s.length())
    {
        //string str = curr_result.substr(0,curr_result.length() - 1);
        //cout << "Subset : " << curr_result << endl;
        result_vector.push_back(curr_result);
        return;
    }

    // call for all subsets that include "s[index]"
    curr_result.push_back(s[index]);
    //curr_result.push_back(',');
    helper(result_vector,s,curr_result,index + 1);
    curr_result.pop_back();
    //curr_result.pop_back();
    //call for all subsets that exclude "s[index"
    helper(result_vector,s,curr_result,index + 1);

}

/*
 * Complete the function below.
 */
vector <string> generate_all_subsets(string s) {

    vector <string > result_vector;
    string curr_result;
    helper(result_vector,s,curr_result,0);
    return result_vector;
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
