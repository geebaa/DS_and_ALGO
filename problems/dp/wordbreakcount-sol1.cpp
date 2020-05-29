#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

unordered_map<int,int> memo;

int helper(unordered_set <string> &dictionary, string &txt,int i)
{
    int result;
    if(i == txt.length()){
        return 1;
    }
    if(i>txt.length()){
        return 0;
    }
    if(memo.find(i) != memo.end()){
        return memo[i];
    }
    result=0;
    for(auto word:dictionary){
        size_t index = txt.find(word,i);
        //cout << " word : " << word << " i : " << i << " wordsize : " << word.size() <<  "index : " << index << endl;
        if(index == i){
            // recursive call 
            result = result + helper(dictionary,txt,i+word.size());
        }
    }
    memo[i]=result;
    return result;
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


