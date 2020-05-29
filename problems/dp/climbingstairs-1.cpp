#include <bits/stdc++.h>

using namespace std;
long long int helper(vector<int> &steps, int n,vector<long long int> &memo){


    if(n == 0){
        memo[0]=1;
        return memo[0];
    }

    if(memo[n] != -1){
        return memo[n];
    }

    long long int sum=0;
    for(auto i:steps){
        if(n-i >= 0){
            sum += helper(steps,n-i,memo);
        }
    }
    memo[n] = sum;
    return memo[n];
}


// Complete the countWaysToClimb function below.
long long int countWaysToClimb(vector<int> steps, int n) {

    long long int result;
    vector<long long int> memo(n+1,-1);
    result = helper(steps,n,memo);
    return result;
}

int main()
{
    ostream &fout = cout;

    int steps_count;
    cin >> steps_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> steps(steps_count);

    for (int i = 0; i < steps_count; i++) {
        int steps_item;
        cin >> steps_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        steps[i] = steps_item;
    }

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long long int res = countWaysToClimb(steps, n);

    fout << res << "\n";

    

    return 0;
}


