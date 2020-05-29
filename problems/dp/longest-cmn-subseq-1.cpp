#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'lcs' function below.
 *
 * The function accepts STRING a and STRING b as parameter.
 * The function is expected to return a STRING.
 */
//string lcs(string a, string b) {
int lcs(string a, string b) {
    // longest common subsequence is an alignment problem where we
    // maximize alignment for matches. This is the inverse so to speak
    // of the min_distance between 2 strings
    // our objective function f(i,j) is defined as the 
    // longest subsequence of strings a[0..i] and b[0..i]
    // while aligning a character we have an insertion,deletion
    // mismatch or a match. In this problem we reward a match with 
    // value 1 and do not reward insertion,deletion or mismatch
    // then our objective function f(i,j)=max(f(i-1,j),f(i,j-1),f(i-1,j-1) + s)
    // where s=1 if ith character of string 'a' matches 
    // jth character of string 'b' i.e a[i-1] == b[j-1] then s=1 else 0
    // base case 
    // row 0 represents longest common subsequence between a null string 
    // various prefixes of 'b'
    // column 0 represents longest common subsequence between a null string
    // and various prefixes of 'a'
    // hence row 0 and col 0 are all 0's

    int n=a.size(),m=b.size();
    vector<vector<int>> dptable(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dptable[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        dptable[0][i]=0;
    }

    // general (i,j)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int s=0;
            if(a[i-1] == b[j-1]){
                // match case reward with 1
                s=1;
            }
            dptable[i][j]=max(dptable[i-1][j-1]+s,
                              max(dptable[i-1][j],dptable[i][j-1])
                             );
        }
    }

    //for(auto row:dptable){
    //    cout <<endl;
    //    for(auto cell:row){
    //        cout << " "<<cell;
    //    }
    //}
    //cout <<endl;
    // reconstruct the lcs string
    string lcs;
    int i=n,j=m;
    while(i>0 && j>0){
        // traverse the diagonal from dptable[n][m] 
        // until 0th row or oth col is reached
        // only when the diagonal element is not equal and the above == left
        // we have added the character from the original string.
        // in all other cases need to traverse left or right

        //cout << "i : " << i<< " j : "<<j<<endl;
        if((dptable[i-1][j-1] != dptable[i][j]) && (dptable[i-1][j] == dptable[i][j-1])){
            // we have added character from a[i-1] or j[i-1]
            lcs+=a[i-1];
            //traverse the table diagonally up
            i--;
            j--;
        }else{
            if(dptable[i-1][j] == dptable[i][j]){
                //traverse up
                i--;
            }else{
                //traverse left
                j--;
            }
        }
    }
    reverse(lcs.begin(),lcs.end());
    //cout << " lcs : " << lcs<<endl;;

    return dptable[n][m];

}


int main()
{
    ostream &fout = cout;

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    //string result = lcs(a, b);
    int result = lcs(a, b);

    fout << result << "\n";

    return 0;
}

