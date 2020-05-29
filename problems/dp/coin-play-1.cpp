#include <bits/stdc++.h>

using namespace std;

// Complete the maxWin function below.
int maxWin(vector<int> v) {

    int n=v.size();

    // objective function will be given a subset of coins from indices i to j
    // max accumulated value of the coins for player 1.
    // player-1 can pick coin i or j
    // case1 - i -- player 2 can pick i+1 or j leaving player-1 with min in next 
    // pick. (i+2,j) and (i+1,j-1) are the next available coices for player1 if he picks i
    // v[i] + min( f(i+2,j) , f(i+1,j-1) )
    // case2 - j -- player 2 can pick i or j-1 leaving player-1 with min in next 
    // pick. (i+1,j-1) and (i,j-2) are the next available coices for player1 if he picks j
    // v[j] + min( f(i+1,j-1) , f(i,j-2) )

    vector<vector<int>>dptable(n,vector<int>(n,0)) ;

    //base case
    // diagonal will be the base case and the 
    // 1) value of dptable[diag][diag]=v[diag] diag ranges from 0 to n-1
    // 2) if there are 2 elements than the max of the element of (v[i],v[j]) if i=j+1
    
    for(int diag=0;diag<n;diag++){
        dptable[diag][diag]=v[diag];
        if(diag+1<n){
            dptable[diag][diag+1]=max(v[diag],v[diag+1]);
        }
    } 

    for(auto row:dptable){
        cout << endl;
        for(auto cell:row){
            cout << " " << cell ;
        }
    }

    // implementation of objective function
    // note that the game happens in the upper half of diagonal where i<=j
    // also the current i,j cell depends on row below and column left
    // so the dptable is filled from bottom row to top row and left to right
    for(int i=n-2;i >= 0 ; i--){
        int o1=INT_MAX;
        int o2=INT_MAX;
        int o3=INT_MAX;
        for(int j=i+1;j<n;j++){
            if(i==j){
                dptable[i][j]=v[i];
                continue;
            }
            if(i+2 < n){
                o1=dptable[i+2][j];
            }
            if((i+1 < n) && (j-1>=0) ){
                o2=dptable[i+1][j-1];
            }
            if(j-2>=0){
                o3=dptable[i][j-2];
            }
            
            dptable[i][j] = max(v[i]+min(o1,o2),v[j]+min(o2,o3));
        }
        
    }
    
    for(auto row:dptable){
        cout << endl;
        for(auto cell:row){
            cout << " " << cell ;
        }
    }
    cout << endl;
    return dptable[0][n-1]; // this is the first call to objective function f(0,n-1)
}


int main()
{
    ostream &fout = cout;

    int v_count;
    cin >> v_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> v(v_count);

    for (int i = 0; i < v_count; i++) {
        int v_item;
        cin >> v_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        v[i] = v_item;
    }

    int res = maxWin(v);

    fout << res << "\n";

    

    return 0;
}

