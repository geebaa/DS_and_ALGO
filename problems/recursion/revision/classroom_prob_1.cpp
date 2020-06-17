#include<bits/stdc++.h>
using namespace std;

// problem is to enumerate all possible strings by permuting letters as capital
// and small


vector<string> str_list;

void helper(string &str,int i,string &result)
{
    //base case 
    if(i == str.size()){
        str_list.push_back(result);
        cout << result<<endl;
        return;
    }

    //recursive case
    if( (tolower(str[i]) >='a') && (tolower(str[i])<='z') )
    {
        result.push_back(tolower(str[i]));
        helper(str,i+1,result);
        result.pop_back();
        result.push_back(toupper(str[i]));
        helper(str,i+1,result);
        result.pop_back();

    }else
    {
        result.push_back(str[i]);
        helper(str,i+1,result);
        result.pop_back();
    }
}

void permute_str(string &str)
{
    string result;
    helper(str,0,result);
}

int main()
{
    string str;
    cout << " enter string : " ;
    cin >> str;
    permute_str(str);

}

