#include <bits/stdc++.h>

using namespace std;

int helper(string &w1, string &w2,int i,int j,vector< vector<int> > &memo) {

    //base case
    if(i == w1.size()){
        memo[i][j] = (w2.size() - j);
        return memo[i][j];
        //return (w2.size() - j) ; 
    }
    if(j == w2.size()){
        memo[i][j] = (w1.size() - i);
        return memo[i][j];
        //return (w1.size() - i) ; 
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    if(w1[i] == w2[j]){
        int r = helper(w1,w2,i+1,j+1,memo);
        memo[i][j] = r; // no operation since curr letters are equal
        return memo[i][j] ;
    } else {
        int r1=helper(w1,w2,i,j+1,memo); // insert
        int r2=helper(w1,w2,i+1,j,memo); // delete
        int r3=helper(w1,w2,i+1,j+1,memo); // replace

        int minall=r1<r2?r1:r2;
        minall=minall<r3?minall:r3;
        memo[i][j] = minall+1 ;
        return memo[i][j] ;
    }

}
/*
 * Complete the function below.
 */
int levenshteinDistance(string strWord1, string strWord2) {
    vector< vector<int> > memo(strWord1.size()+1);
    for(auto& i:memo){
        i.resize(strWord2.size()+1,-1);
    }
    return helper(strWord1,strWord2,0,0,memo);
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


