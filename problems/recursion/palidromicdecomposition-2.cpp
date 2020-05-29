#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    int n = s.length();
    for(int i=0,j=n-1;i<=j;i++,j--)
    {
        if(s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}
void helper(string &s,int start, vector <string> &result,vector <string> &curr){

    // base case 
    if(start == s.length()){
        // curr has a successful partition
        string newstr;
        for(auto i:curr){
            newstr.append(i);
            newstr.push_back('|');
        }
        newstr.pop_back(); // erase the last '|'
        result.push_back(newstr);
        return;
    }

    //recursive case
    for(int i=start;i<s.length();i++){
        int substr_length = (i+1) - start;
        string str = s.substr(start,substr_length );
        if(isPalindrome(str)){
            curr.push_back(str);
            helper(s,i+1,result,curr);
            curr.pop_back();
        }
    }
}

vector <string> generate_palindromic_decompositions(string s) {
    vector <string> result;
    vector<string> curr;
    helper(s,0,result,curr);
    return result;

}
int main()
{
    ostream &fout = cout;

    vector <string> res;
    string s;
    getline(cin, s);

    res = generate_palindromic_decompositions(s);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}

