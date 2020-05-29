#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the join_words_to_make_a_palindrome function below.
 */

bool isPalindrome(vector<string> &words,int i,int j){
    string word=words[i];
    word.append(words[j]);
    int left=0,right=word.length()-1;
    while(left <= right){
        if(word[left] != word[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
vector<string> join_words_to_make_a_palindrome(vector<string> &words) {
    /*
     * Write your code here.
     */
    int n=words.size();
    vector<string> failure{"NOTFOUND","DNUOFTON"};
    vector<string> success;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(isPalindrome(words,i,j)){
                success.push_back(words[i]);
                success.push_back(words[j]);
            }
        }
    }
    if(success.size() == 0){
        return failure;
    }
    return success;
}
int main()
{
    ostream &fout = cout;

    int words_count;
    cin >> words_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> words(words_count);

    for (int words_itr = 0; words_itr < words_count; words_itr++) {
        string words_item;
        getline(cin, words_item);

        words[words_itr] = words_item;
    }

    vector<string> res = join_words_to_make_a_palindrome(words);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    

    return 0;
}


