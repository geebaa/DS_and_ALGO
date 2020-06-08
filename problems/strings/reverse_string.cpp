#include <bits/stdc++.h>
using namespace std;

string reverse_str(string &str)
{
    int n=str.size();
    int s=0,e=n-1;
    char tmp;
    while(s<e){
        tmp    = str[e];
        str[e] = str[s];
        str[s] = tmp;
        s++;
        e--;
    }
    return str;
}

int main()
{
    string str,rev_str;
    cin >> str;
    rev_str = reverse_str(str);
    cout <<endl << "str : " << str << " rev_str : " << rev_str <<endl;
    return 0;
}

