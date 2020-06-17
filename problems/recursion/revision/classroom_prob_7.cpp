#include<bits/stdc++.h>
using namespace std;

bool regex_matcher(string &input,string &pattern,int i,int j)
{
    //cout << " i : " << i << " j : " << j << endl; 
    //base case 
    if( (i == input.size()) && (j == pattern.size()))
    {
        // pattern and string completely processed
        return true;
    }
    if(j == pattern.size()){
        // pattern ended but string did not
        return false;
    }
    if(i == input.size()){
        // string ended but pattern  did not
        // check if the rest of the pattern is "*" since it can
        // match 0 or more characters
        while(j<pattern.size()){
            if(pattern[j]!='*'){
                return false;
            }
            j++;
        }
        //cout << "returning true"<<endl;
        return true;
    }
 
    //recursive case
    bool result;
    if(pattern[j] == '*'){
        // '*' matchs one character of string 
        result=regex_matcher(input,pattern,i+1,j);
        // '*' matchs zero characters of string 
        result = result || regex_matcher(input,pattern,i,j+1);
    }else{
        // pattern and string mist match characters 
        // at the jth and ith location respectively
        if(input[i] == pattern[j]){
            result = regex_matcher(input,pattern,i+1,j+1);
        }else{
            result = false;
        }
    }
    return result;
}


int main()
{
    string pattern;
    string input;
    cout << "enter string : " ;
    cin >> input;
    cout << "enter pattern : " ;
    cin >> pattern;

    cout << " match is  : " << regex_matcher(input,pattern,0,0)<<endl;
}

