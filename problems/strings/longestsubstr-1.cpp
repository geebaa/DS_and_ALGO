#include <bits/stdc++.h>

using namespace std;

// Complete the getLongestSubstringLengthExactly2DistinctChars function below.
int getLongestSubstringLengthExactly2DistinctChars(string s) {
    // bruteforce solution
    int i=0,j=0;
    int n = s.length();
    int curr_window_distinct_char;
    unordered_map<char,int> curr_window_char_count;
    unordered_map<char,int>::iterator itr;
    int max_len=0;
    while(j < n){

        // accept the character at j into the window and update the map 
        itr=curr_window_char_count.find(s[j]);
        if(itr == curr_window_char_count.end()){
            curr_window_char_count[s[j]]=1;
        }else{
            curr_window_char_count[s[j]]=curr_window_char_count[s[j]]+1;
        }

        // if more than 2 distinct characters are present
        // remove from the left  
        while(curr_window_char_count.size() > 2){
            itr=curr_window_char_count.find(s[i]);
            if(itr == curr_window_char_count.end()){
                cout << "Cannot be here : 1" << endl;
            }else{
                if(curr_window_char_count[s[i]]== 1){
                    curr_window_char_count.erase(s[i]);
                }else{
                    curr_window_char_count[s[i]] = curr_window_char_count[s[i]]-1;
                }
            }
            i++;
        }

        // if exactly 2 distinct characters are present
        if(curr_window_char_count.size() == 2){
            max_len=max(max_len,j-i+1);
        }
        j++;
    }
    return max_len;
}


int main()
{
    ostream &fout = cout;

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < q; ++i)
    {
        string s;
        getline(cin, s);

        int res = getLongestSubstringLengthExactly2DistinctChars(s);

        fout << res << "\n";
    }
    
    

    return 0;
}

