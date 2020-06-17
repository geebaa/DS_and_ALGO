#include<bits/stdc++.h>
using namespace std;

void print_all(string &str,vector<pair<int,int>> &result)
{
    for(auto elem:result){
        cout << str.substr(elem.first,elem.second-elem.first+1)<<"|";
    }
    cout <<endl;
}

bool isPalindrome(string & str,int i,int j)
{
    while(i<=j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void palindromic_partition_helper(string &str,int i,vector<pair<int,int>> &result)
{
    if(i==str.size()){
        print_all(str,result);
        return;
    }
    int n=str.size();
    for(int j=i;j<str.size();j++){
        if(isPalindrome(str,i,j)){
            result.push_back(make_pair(i,j));
            palindromic_partition_helper(str,j+1,result);
            result.pop_back();
        }
    }
}

void palindromic_partition(string &str)
{   vector<pair<int,int>>result;
    palindromic_partition_helper(str,0,result);
}

int main()
{
    string str;
    str = "madam";
    palindromic_partition(str);
}

