#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

unordered_map<int,int> memo;

#define MOD 1000000007 
int helper(unordered_set <string> &dictionary, string &txt,int i)
{
    int result;
    if(i == txt.length()){
        return 1;
    }
    if(memo.find(i) != memo.end()){
        return memo[i];
    }
    result=0;

    /*Find all substrings of txt starting at i and 
      search for it in the dictionary. If substring
      is found then call helper with a new i that 
      is updated by length of found substr. If end  
      of text is reached, it means there is a trailing 
      substring of txt in this path that is not in dictionary
      return false. Base condition is that you call helper with 
      an i that is just past the string txt . In this case i 
      will be equal to txt.size() and return true here because
      txt is completely broken into proper words from 
      dictionary. Add memoization by maintaining a memo for all "i"
   */

    for(int j=i;j<txt.size();j++) {
        /* substr is txt[i:j]*/
        if(dictionary.find(txt.substr(i,(j-i)+1)) != dictionary.end()){
            /*a substring txt[i:j] is found
              try to continue finding for all substrings 
              of txt begining j+1 till txt.size()
            */
            result += helper(dictionary,txt,j+1);
            result = result%MOD;          
        }
    }

    memo[i]=result%MOD;
    return memo[i];
}

/*
 * Complete the wordBreakCount function below.
 *
 * The function accepts STRING_ARRAY dictionary as parameter.
 * and string txt on which segmentation is to be
 * performed.
 * The function returns the count of all possible segmentation 
 */

int wordBreakCount(vector<string> &dictionary, string &txt)
{
    int result;
    unordered_set <string> dict(dictionary.begin(),dictionary.end());
    result = helper(dict,txt,0);

    return result;
}


int main()
{
    string dictionary_count_temp;
    getline(cin, dictionary_count_temp);
    int dictionary_count = stoi(ltrim(rtrim(dictionary_count_temp)));

    vector<string> dictionary(dictionary_count);

    for (int i = 0; i < dictionary_count; i++)
    {
        string dictionary_item;
        getline(cin, dictionary_item);
        dictionary[i] = ltrim(rtrim(dictionary_item));
    }

    string txt;
    getline(cin, txt);

    ostream &fout = cout;

    int result = wordBreakCount(dictionary, txt);

    fout << result << endl;

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}


