#include <bits/stdc++.h>

using namespace std;

// LC 746
// Complete the countWaysToClimb function below.
long long int minCostClimb(vector<int> &cost) {
    int n=cost.size();
    // min cost way to reach the ith stair
    // steps 1 or 2 allowed
    // dptable goes from 0 all the way to n+1 ...hence size n+2
    vector<long long int> dptable(n+2,0);

    // append a 0 cost to be at stair n+1
    cost.push_back(0);
    // base case . min cost to be at the 0th step is 0
    dptable[0]=0;
    dptable[1]=cost[0]; // min cost to reach 1st step
    // reccurance relation let f(i) = min cost to reach ith step
    // then f(i) = min( f(i-2), f(i-1) ) + cost[i-1]
    // cost is a 0 based array and hence the i-1

    for(int step=2; step<=n+1;step++){
        // note that we never reference outside of 0 to n in dptable
        // and 0 to n-1 in cost
        dptable[step]=min(dptable[step-2],dptable[step-1]) + cost[step-1];
    }
    return dptable[n+1];
}
int main()
{
    ostream &fout = cout;

    int steps_count;
    cin >> steps_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> cost(steps_count);

    for (int i = 0; i < steps_count; i++) {
        int steps_item;
        cin >> steps_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cost[i] = steps_item;
    }

    long long int res = minCostClimb(cost);

    fout << res << "\n";

    

    return 0;
}

