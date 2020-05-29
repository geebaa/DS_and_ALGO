#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
int levenshteinDistance(string strWord1, string strWord2) {
    int m=strWord1.size();
    int n=strWord2.size();

    vector< vector<int> > dptable(m+1);
    for(auto& i:dptable){
        i.resize(n+1,-1);
    }
    //base case
    for(int i=0;i<=m;i++){
        dptable[i][n] = m - i;
    }
    for(int j=0;j<=n;j++){
        dptable[m][j] = n - j;
    }

    // recursive case
    for(int i=m-1;i>=0;i--) {
        for(int j=n-1;j>=0;j--) {
            if(strWord1[i] == strWord2[j]){
                dptable[i][j] = dptable[i+1][j+1];
            } else {
                int r1=dptable[i][j+1];
                int r2=dptable[i+1][j];
                int r3=dptable[i+1][j+1];
                int minall = (r1<r2)?r1:r2;
                minall = (minall<r3)?minall:r3;
                dptable[i][j] = minall+1;
            }
        }
    }
    return dptable[0][0];
}



int main() {
    ostream &fout = cout;
    int res;
    string _strWord1;
    getline(cin, _strWord1);
    
    string _strWord2;
    getline(cin, _strWord2);
    
    res = levenshteinDistance(_strWord1, _strWord2);
    fout << res << endl;
    
    
    return 0;
}


