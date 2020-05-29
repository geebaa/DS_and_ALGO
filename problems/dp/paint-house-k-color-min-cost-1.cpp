#include<bits/stdc++.h>
using namespace std;

// n houses - can be painted in k colors c0,c1,c2...ck-1 
// cost of painting each house with each color is cost[i-1][0] .. cost[i-1][k-1]
// no 2 adj house can have same color
// minimize the cost of painting n houses

// a general choice for painting the nth house is to paint it c1,c2...ck-1
// cost of painting i houses with ith being c0 is   
// min cost of painting i-1 houses with color not being 0 + cost[i-1][0]
// dptable will be a 2d array of dptable[n][k]
// each cell [i][i] represents the min cost of painting i houses with the 
// ith house being of color cj
// our answer will be the min of the last row dptable[n-1]

int min_cost_paint_houses(int n,vector<vector<int>> cost)
{
    int k=cost.size();
    vector<vector<int>> dptable(n,vector<int>(k,0));

    // special case
    if(n==0){
        return 0;
    }
    //base case
    // cost of painting 1 house with different colors
    // will be for all color ck dprable[0][ck]=cost[0][ck]

    for(int i=0;i<k;i++){
        dptable[0][i] = cost[0][i];
    } 

    for(int i=1;i<n;i++){
        int min_cost = INT_MAX;
        for(int col=0;col<k;col++){
            for(int prev_col=0;prev_col<k;prev_col++){
                if(col == prev_col){
                    continue;
                }
                min_cost = min(min_cost,dptable[i][prev_col]);
            }
            dptable[i][col] = min_cost;
        }
    }

    return *min_element(dptable[n-1].begin(),dptable[n-1].end());

}
int main()
{
}

