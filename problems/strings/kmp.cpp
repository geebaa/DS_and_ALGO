#include <bits/stdc++.h>

using namespace std;

// Complete the KMP function below.
vector<int> brute_force(string t, string p) {

    /*
        brute force approach is to look for every start index i from 0 to length of t
        match each character from p from 0 to length of p
    */
    vector<int> result;
    int n=t.size();
    int m=p.size();
    for(int i=0;i<=n-m;i++){
        bool all_matched=true;
        for(int j=0;j<m;j++){
            if(t[i+j] != p[j]){
                all_matched=false;
                break;
            }
        }
        // we could be here because a character did not match
        // or all characters matched
        if(all_matched){
            result.push_back(i); // store the start i
        }
    }
    if(result.empty()){
        result.push_back(-1);
    }
    return result;

}

void computeLPS(vector<int> &lps,string &p)
{
    // this function preprocesses the pattern and computes the offsets
    // in pattern to skip for each prefix of pattern
    // 2 pointers that indicate len and i to iterate over all the characters
    // in pattern . len is the length of the prefix and i is the current element 
    // in the pattern . start with len=0 and i=1 until i<n where n is length of pattern
    
    int n = p.size();
    int len=0,i=1;
    lps[len]=0;
    while (i < n){
        if(p[len] == p[i]){
            // for substring p[0..i] the offset to skip
            // when a mismatch occurs at p[i+1]
            lps[i] = len+1;
            i++;
            len++;
        }else{
            if(len == 0){
                // we are the begining and see a mismatch at i
                lps[i]=0;
                i++;
            }else{
                len=lps[len-1];
            }
        }
    }
    //cout << endl << "lps : ";
    //for(auto skip:lps){
    //    cout << " " << skip;
    //}
    //cout << endl;
}

vector<int> KMP(string t, string p) {
    vector<int> result;
    int n=t.size();
    int m=p.size();
    // this is the longest prefix that is also a suffix for each prefix p[0..i] where 0<=i<m 
    vector<int>lps(m,0); 
    // lps is computed on the pattern . It studies the pattern and programs the table
    computeLPS(lps,p);

    // we use 2 indices i and j to traverse the text and pattern
    // in KMP i is never retracted back
    int i=0,j=0;
    while(i < n ){
        
        if(t[i] == p[j]){
            // if current character matches move both i and j to next
            i++;
            j++;
            //cout <<"match : "<< endl;
            //cout << " i : " << i;
            //cout << " j : " << j;
        }else {
            if(j!=0){
                // retract the pointer enough to cover the prefix, hold the same i
                j=lps[j-1]; 
            }else{
                // here the comparision failed at the first j . we move forward with i 
                i++;
                //cout <<"mismatch : "<< endl;
                //cout << " i : " << i;
                //cout << " j : " << j;
            }
        }
        if(j==m){
            // one complete pattern matched from (i-j)th location
            result.push_back(i-j);
            // continue searching by retracting j and holding the i
            j=lps[j-1];
            //cout << "i : " << i << " j : " << j<< endl;
        }
    }
    if(result.empty()){
        result.push_back(-1);
    }
    return result;    
}

int main()
{
    ostream &fout = cout;

    string t;
    getline(cin, t);

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < q; ++i)
    {
        string p;
        getline(cin, p);

        vector<int> res = KMP(t, p);

        for (int i = 0; i < res.size(); i++) {
            fout << res[i];

            if (i != res.size() - 1) {
                fout << "\n";
            }
        }

        fout << "\n";
    }
    

    return 0;
}

