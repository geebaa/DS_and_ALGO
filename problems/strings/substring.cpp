#include <bits/stdc++.h>
using namespace std;
// brute force algo
bool is_substr(string &str2,string &str1)
{
    // to check if str2 is a substr of str1
    int n=str1.size(),m=str2.size();
    if(m>n){
        return false;
    }
    int o=n-m;
    int i,j;
    // for every possible start in str1
    for(i=0;i<=o;i++){
        int k=i;
        for(j=0;j<m;j++){
            if(str1[k+j] == str2[j]){
                continue;
            }else{
                break;
            }
        }
        if(j==m){
            // whole string matched
            return true;
        }
    }
    return false;
    
}

int main()
{
    string str1,str2;
    cin >> str1;
    cin >> str2;
    
    cout <<endl << is_substr(str2,str1) <<  endl;
    return 0;
}

