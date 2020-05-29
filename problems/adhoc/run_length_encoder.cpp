#include <bits/stdc++.h>

using namespace std;

/*
    Complete the function below
    Input: A string "strInput" denoting the input string
    Output: A string
*/

string RLE(string strInput){

    int ctr=0;
    int rd=0,wr=0;
    int n = strInput.length();
    int i=0;
    string result;
    for(i=0;i<n;i++){
        ctr=1;
        while((i+1) < n){
            if(strInput[i] == strInput[i+1]){
                i=i+1;
                ctr++;
            }else{
                break;
            }
        }
        if(ctr>1){
            result.append(to_string(ctr));
        }
        result += strInput[i];
    }

    return result;
}

int main(){
    string s;
    cin>>s;
    string result = RLE(s);
    cout<<result<<endl;
    return 0;
}


