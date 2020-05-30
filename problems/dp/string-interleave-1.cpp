#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'doStringsInterleave' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 *  3. STRING i
 */

bool doStringsInterleave(string a, string b, string i) {
    // this can be visualized as an alignment of 'a' and 'b' to form 'i'
    // the following condotions have to be met
    // i.size() == a.size() + b.size()
    // and last character of 'i' could match
    //          1) last character of 'a'
    //          2) last character of 'b'
    //          3) last character of both 'a' and 'b'
    // in each case the subproblem reduces by one character 
    // in the respective strings 
    // a generic f(i,j) is defined to be true is a[0..i] , b[0..j] form
    // an alignment of i[0..i+j]
    // base case would be the first row and first column
    // first cell null string + nullstring is al alignment of null string
    // therefore dptable[0][0]=true

    int n=a.size();
    int m=b.size();
    //special case
    if(i.size() != m+n){
        return false;
    }

    vector<vector<bool>> dptable(n+1,vector<bool>(m+1,false));
    // base case
    dptable[0][0]=true;
    for(int r=1;r<=n;r++)
    {
        // can a string a[0..r-1] with a null string form 
        // an alignment of i[0..r-1]
        // this decisoin can be made by comparing the decision
        // of a[0..r-2] being an alignment of i[0..r-2] stored
        // at dptable[r-1][0] and checking the rth character of 
        // 'a' and 'i'
       dptable[r][0] = dptable[r-1][0] & (a[r-1] == i[r-1]);
    }
    for(int c=1;c<=m;c++)
    {
        // refer explaination for prev for loop 
       dptable[0][c] = dptable[0][c-1] & (b[c-1] == i[c-1]);
    }
    // for a general i,j
    for(int r=1;r<=n;r++){
        for(int c=1;c<=m;c++){
            // if any of the following is true then
            // i[0..r+c] is an alignment of a[0..r] , b[0..c]
            dptable[r][c] = dptable[r-1][c] & (a[r-1] == i[r+c-1])
                                           ||
                            dptable[r][c-1] & (b[c-1] == i[r+c-1]);
        }
    }

    return dptable[n][m];
}

int main()
{
    ostream &fout = cout;

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    string i;
    getline(cin, i);

    bool result = doStringsInterleave(a, b, i);

    fout << result << "\n";

    

    return 0;
}


