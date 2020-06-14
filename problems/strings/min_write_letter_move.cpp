#include <bits/stdc++.h>

using namespace std;

string move_letters_to_left_side_with_minimizing_memory_writes(string s) {
    /*
     * basic idea is to have write and read pointer.
     * write pointer always points to the next writable index
     * read pointer walks the entire length of string picking up characters
     */
    int w_ptr=0;
    for(auto letter:s){
        if(tolower(letter) >= 'a' && tolower(letter) <= 'z'){
            s[w_ptr] = letter;
            w_ptr++;
        }
    }
    return s;
}

int main()
{
    ostream &fout = cout;

    string s;
    getline(cin, s);

    string res = move_letters_to_left_side_with_minimizing_memory_writes(s);

    fout << res << "\n";

    

    return 0;
}

