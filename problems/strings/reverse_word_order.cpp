#include <bits/stdc++.h>

using namespace std;

void reverse_word(string &s,int wb,int we)
{
    char tmp;
    while(wb<=we){
        tmp=s[wb];
        s[wb]=s[we];
        s[we]=tmp;
        wb++;
        we--;
    }
}

string reverse_ordering_of_words(string s) {
    /*
     * General idea is to use 2 indices to reverse the string.
     * make one more pass to reverse the words in the string
     */
    int n=s.size();
    int b=0,e=n-1;
    char tmp;
    while(b<=e){
        tmp=s[b];
        s[b]=s[e];
        s[e]=tmp;
        b++;
        e--;
    }
    //cout << " reverse : " << s << endl;


    //wb = word begin and we = word end
    // reverse each word in the string
    int wb=0,we=0;
    wb=s.find_first_not_of(' ');
    while(wb != string::npos){
        we=s.find_first_of(' ',wb);
        if(we != string::npos){
            reverse_word(s,wb,we-1);
        }else{
            reverse_word(s,wb,n-1);
        }
        wb=s.find_first_not_of(' ',we);
    }
    //cout << " reversed words : " << s << endl;

    return s;

}


int main()
{
    ostream &fout = cout;

    string s;
    getline(cin, s);

    string res = reverse_ordering_of_words(s);

    fout << res << "\n";

    

    return 0;
}


