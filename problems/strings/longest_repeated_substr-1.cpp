#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'getLongestRepeatedSubstring' function below.
 */

string getLongestRepeatedSubstring(string inputStr) {
    string result;
    int maxlen=0;
    int n=inputStr.length();
    int k=0;
    // enumerate all substrings
    for(int i=0;i<n;i++){
        k=i+1;//start of searchhere
        for(int j=i;j<n;j++){
            // substring is inputStr[i:j]
            string substr=inputStr.substr(i,j-i+1);
            // where to search inputStr[j+1:n-1]
            //string searchhere=inputStr.substr(k);
            //cout << " substr : " << substr << " searchhere : " << searchhere << endl;
            //if(searchhere.find(substr) != string::npos){
            if(inputStr.find(substr,k) != string::npos){
                //update result 
                if(maxlen < substr.length()){
                    maxlen=substr.length();
                    result=substr;
                    //cout << " maxlen : " << maxlen << " result : " << result << endl;
                }
            }else{
                // no way a longer substring will exist we need to move to the next i
                break;
            }
        }
    }
    return result;
}


int main()
{
    string inputStr;
    getline(cin, inputStr);

    ostream &fout = cout;

    string result = getLongestRepeatedSubstring(inputStr);

    fout << result << "\n";


    return 0;
}


