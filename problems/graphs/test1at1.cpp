#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector <char > adjlist[26];
string find_order(vector <string> words) {

    int num_words;
    int max_word_size;
    num_words=words.size();
    max_word_size=0
    int found_char_weight[26]; // the iteration in which the words were found
    vector ith_iteration_new_char_order; // order of new characters found in ith iteration
    for (int i=0;i< num_words;i++) {
        if(max_word_size < words[i].size()) {
            max_word_size = words[i].size();
        }
    }

    //iterate each word upto its max size

    for(int i = 0;i<max_word_size;i++) {
        for(j=0;j<num_words;j++) {
            char prev_new_char=0;
            if(words[j].size() <= max_word_size) {
                char curr_char = words[j][i];
                // store the iteration when the word was first discovered
                if(!found(curr_char)) {
                    found_char_weight[curr_char - 'a'] = i;
                    // start building adj list
                    if(prev_new_char == 0) {
                        //first new character in the current iteration
                        prev_new_char = curr_char;
                        // order of new characters discovered in ith iteration
                        ith_iteration_new_char_order.pushback(curr_char);
                    }
                }
            } 
        }
    }


}

int main()
{
    ostream &fout = cout;

    string res;
    int words_size = 0;
    cin >> words_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<string> words;
    for(int i = 0; i < words_size; i++) {
        string words_item;
        //getline(cin, words_item);
        cin >> words_item;
        words.push_back(words_item);
    }

    res = find_order(words);
    fout << res << endl;

    
    return 0;
}

