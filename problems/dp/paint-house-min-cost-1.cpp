#include<bits/stdc++.h>
using namespace std;

// n houses - can be painted in 3 colors red,blue,green
// cost of painting each house with each color is cost[i][0] .. cost[i][2]
// no 2 adj house can have same color
// minimize the cost of painting n houses

// a general choice for painting the nth house is to paint it r,b,g
// cost of painting i houses with ith being r is r(i) 
// similarly for g is g(i) and b is b(i)
// r(i) = cost[i][0] + min( b(i-1),g(i-1) )
// in simple terms cost of r(i) will be cost of painting ith house in r
// and the min of cost of painting (i-1)th house in b and g
// similar equation follows for g(i) and b(i)
// our answer is min(r(i),b(i),g(i)) 

int min_cost_paint_houses(int n,vector<vector<int>> cost)
{
    vector<int> g(n,0),r(n,0),b(n,0);
    // special case
    if(n==0){
        return 0;
    }
    //base case
    r[0] = cost[0][0]; // cost of painting 1st house in red   
    g[0] = cost[0][1]; // cost of painting 1st house in green
    b[0] = cost[0][2]; // cost of painting 1st house in blue

    for(int i=1;i<n;i++){
        r[i]=cost[i][0]+min(g[i-1],b[i-1]);
        g[i]=cost[i][1]+min(r[i-1],b[i-1]);
        b[i]=cost[i][2]+min(g[i-1],r[i-1]);

    }

    return min(min(r[n-1],g[n-1]),b[n-1]);

}
int main()
{
}

