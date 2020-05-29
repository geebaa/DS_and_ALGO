#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
int minMultiplicationCost(vector < int > mtxSizes) {
    // n represents num matrices
    int n=mtxSizes.size() - 1;

    // each cell is the minimim cost of multiplying a matrix from i to j
    vector<vector<int>> dptable(n,vector<int>(n,0));

    // base case
    // diagonal to 0
    for(int diag=0;diag<n;diag++){
        dptable[diag][diag]=0;
    }

    // matrix are from 0 to n-1
    // dim matrix[0] = mtxSizes[0]xmtxSizes[1]
    // dim matrix[1] = mtxSizes[1]xmtxSizes[2]
    // dim matrix[2] = mtxSizes[2]xmtxSizes[3]
    // dim matrix[n-1] = mtxSizes[n-1]xmtxSizes[n]

    for(int row=n-2;row>=0;row--){
        for(int col=row+1;col<n;col++){
            int mincost=INT_MAX;
            // find mincost for multiplying matrix from i to j
            // matrix dimensions are from mtxSizes[i..j+1]
            for(int k=row;k < col;k++){
                //cost of multiplying the resultant matrix
                int cost=mtxSizes[row]*mtxSizes[k+1]*mtxSizes[col+1];
                //cout << "row : " << row << " col : " << col << "cost : " << cost << endl;
                mincost = min(mincost,(dptable[row][k] + dptable[k+1][col] + cost));
            }
            dptable[row][col]=mincost;
        }
    }
    return dptable[0][n-1];

}


int main() {
    ostream &fout = cout;
    int res;
    
    int _mtxSizes_size = 0;
    cin >> _mtxSizes_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _mtxSizes;
    int _mtxSizes_item;
    for(int _mtxSizes_i=0; _mtxSizes_i<_mtxSizes_size; _mtxSizes_i++) {
        cin >> _mtxSizes_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _mtxSizes.push_back(_mtxSizes_item);
    }
    
    res = minMultiplicationCost(_mtxSizes);
    fout << res << endl;
    
    
    return 0;
}


