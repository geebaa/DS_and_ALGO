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

void helper(vector <string> &result_vector,string & curr_result,string &input,int index)
{

    // base case 
    // if index = input.length() we have completed a pass and found
    // a palindrome decomposition. Add the curr_result to result_vector
    if(index == input.length())
    {
        string newstr = curr_result.substr(0,curr_result.length() - 1);
        result_vector.push_back(newstr);
        return;
    }

  
    // for all substring "a","ab","abc" ... fullstring 
    // if the substring is a palindrome , add it to curr_result
    // call helper with the pending string index
    for(int i=index;i<input.length();i++)
    {
        // get a substring input[index .. i]
        int substr_length = (i+1) - index; 
        string str = input.substr(index,substr_length );
        if(isPalindrome(str ))
        {
            curr_result.append(str);
            curr_result.push_back('|');
            helper(result_vector,curr_result,input,i+1);
            int added_length = str.length() + 1 ;
            int erase_start = curr_result.length() - added_length;
            curr_result.erase(erase_start);
        }
    }
}




/*
 * Complete the function below.
 */
vector <string> generate_palindromic_decompositions(string s) {

    vector <string> result_vector;
    string curr_result;
    helper(result_vector,curr_result,s,0);

    return result_vector;
}


int main()
{
    ostream &fout = cout;

    vector <string> res;
    string s;
    getline(cin, s);

    //cout << "a : " << isPalindrome("a") << endl;
    //cout << "ab : " << isPalindrome("ab") << endl;
    //cout << "aba : " << isPalindrome("aba") << endl;
    //cout << "abba : " << isPalindrome("abba") << endl;
    //cout << "aa : " << isPalindrome("aa") << endl;
    //cout << "abc : " << isPalindrome("abc") << endl;


    res = generate_palindromic_decompositions(s);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}


