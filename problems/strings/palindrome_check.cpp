#include <bits/stdc++.h>
using namespace std;

bool is_str_palindrome(string &str)
{
    int n=str.size();
    int s=0,e=n-1;
    char tmp;
    while(s<e){
        if(str[s]!=str[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main()
{
    string str;
    cin >> str;
    
    cout <<endl << "string " << str << " is " << (is_str_palindrome(str)?"a":"not a") << " palindrome " <<endl;
    return 0;
}

