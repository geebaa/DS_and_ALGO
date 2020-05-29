#include<bits/stdc++.h>
using namespace std;

// LC 72
// the objective is to find an optimal alignment for w1 and w2.
// lets say the words were "horse" and "ros"
// for example align the words as follows      
//                          horse
//                          ro-s-
//   this means that replace 1st letter 'h' with 'r'
//                   dont do any operation on 2nd letter
//                   relete 3rd letter from w1
//                   dont do any operation on 4th letter
//                   delete 5th letter from w1
//   objective function f(i,j) will be the minimum cost of
//   converting w1[0..i] to w2[0..j]
//   then our problem is f(n,m) where n=w1.length() and m=w2.length()
//   suppose we define a grid of size dptable(n+1,m+1)
//   then row0 represents the way to convert null string to prefixes of w2
//   col0 represents the way to convert various prefixes of w1 to a null string
//   base case will be the 0th row and 0th column
//   dpteble[0][i] 0<=i<=m will be i 
//   (number of insert required to construct word w2[0..i]). 
//   dptable[j][0] 0<=j<=n will be j 
//   (number of delete required to construct null string from word w1[0..j]).
 
int min_distance(string w1,string w2){

    int n=w1.size(),m=w2.size();
    vector<vector<int>> dptable(n+1,vector<int>(m+1,0));

    // base case
    // 0th column
    for(int i=0;i<=n;i++){
        dptable[i][0]=i;
    }
    // 0th row 
    for(int j=0;j<=m;j++){
        dptable[0][j]=j;
    }
    // a general [i][j]
    // convert w1[0..i] to w2[0..i]
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int s=0;// no change from dptable[i-1][j-1]
            if(w1[i-1] != w2[j-1]){ // 0 based index
                s=1;// replace operation from dptable[i-1][j-1]
            }
            dptable[i][j]=min(dptable[i-1][j-1]+s,
                              min(dptable[i-1][j],dptable[i][j-1])+1
                             );
        }
    }
    return dptable[n][m];
    
}


int main()
{
    cout << min_distance("horse","ros");
    cout << min_distance("intention","execution");
    return 0;
}

