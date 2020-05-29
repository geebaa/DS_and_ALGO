#include <bits/stdc++.h>

using namespace std;

long long int n_choose_k(int n,int k) {

    // 2d array dptable[n+1][k+1]
    // each cell represents the value of nCk 
    vector<vector<long long int>> dptable(n+1 , vector<long long int> (k+1,0));

    // base case 
    // for all n and k==0 is 1 . number of ways of choosing an empty set from
    // a set of n
    for(auto &row:dptable){
        row[0]=1;
    }
    //for all n == k dptable[n][k]=1
    for(int col=0;col<=k;col++){
        dptable[col][col]=1;
    }
    // all other cases    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i,k);j++){
                          // include jth elem   exclude jth elem
            dptable[i][j]=dptable[i-1][j-1]  +  dptable[i-1][j];
        }
    }
    for(auto row:dptable){
        cout << endl;
        for(auto cell:row){
            cout << cell << " ";
        }
    }
    return dptable[n][k];
}

int main()
{
    ostream &fout = cout;

    int n,k;
    cin >> n;
    cin >> k;

    long long int res = n_choose_k(n,k);

    fout << res << "\n";

    return 0;
}

