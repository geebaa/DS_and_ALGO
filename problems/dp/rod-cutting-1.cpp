#include<bits/stdc++.h>
using namespace std;

int max_cost_rod_cut(int n,vector<int> price)
{
    int result;
    // given a rod of length n and prices for pieces of length 1 to n
    // cut the rod into pieces maximising the profit

    // lets get the define the objective function
    // f(i) = max profit for a rod of length 'i'
    // now what are the options for cutting this rod ?
    // it could be cut as (i-1,1) or (i-2,2)... (0,i)
    // max of the above values will be the answer for f(i)
    // therefore f(i) = cut varies from 1 to i [ max(f(i-cut) + price[cut] )]


    vector<int> dptable(n+1,0);
    //special case
    if(n==0){
        return 0;
    }

    //base case
    dptable[0]=0;
    dptable[1]=price[0]; // price of cut size of 1

    // general case
    int max_profit;
    for(int size=2;size<=n;size++){
        max_profit=INT_MIN;//start lowest and improve
        for(int cut=1;cut<=size;cut++){
            max_profit=max(max_profit,dptable[size-cut]+price[cut-1]);
        }
        dptable[size] = max_profit;
    }
    //dptable[n] will have the max_profit for a rod of length n
    return dptable[n];

}

int main()
{
    return 0;
}

