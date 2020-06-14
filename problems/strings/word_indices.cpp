#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
* Complete the 'find_words' function below.
*
* The function accepts STRING and STRING ARRAY as parameter.
* Return 2D INTEGER ARRAY.
*/
vector<vector<int>> find_words(string text, vector<string> words) 
{
    // broad idea is to iterate the string words and have a start and end
    // pointer for every word found. 

    vector<vector<int>> result;
    unordered_map<string,vector<int>> word_index_list;
    unordered_set<string> words_dict(words.begin(),words.end());
    int s=0,e=0;
    int n=text.size();
    int inp;
    while(s != string::npos ){
        string curr_word;
        s=text.find_first_not_of(" ",e);
        if(s == string::npos){
            break;
        }
        e=text.find_first_of(" ",s); 
        // word is 
        if(e != string::npos){
            curr_word=text.substr(s,e-s);
            //cout << "word : " << curr_word<<endl;
        }else{
            curr_word=text.substr(s,n-s);
            //cout << "word : " << curr_word<<endl;
            
        }
        // if curr_word is found in dictionary , save its start
        if(words_dict.find(curr_word) != words_dict.end()){
            word_index_list[curr_word].push_back(s);
        }
    }
    // reconstruct the result from the word_index_list
    int i=0;
    for(auto word:words){
        if(word_index_list.find(word) != word_index_list.end()){
            vector<int> arr=word_index_list[word];
            result.push_back(arr);
        }else{
            result.push_back({-1});
        }
        i++;
    }
    return result; 

}

int main()
{
    string text;
    getline(cin, text);
    
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<string> words(q);

    for (int i = 0; i < q; i++) {
        string word;
        getline(cin, word);

        words[i] = word;
    }
    
    ostream &fout = cout;

    vector<vector<int>> result = find_words(text, words);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

