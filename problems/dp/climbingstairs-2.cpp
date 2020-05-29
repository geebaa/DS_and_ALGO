#include <bits/stdc++.h>

using namespace std;

// Complete the countWaysToClimb function below.
long long int countWaysToClimb(vector<int> steps, int n) {

    long long int result;
    vector<long long int> dptable(n+1,-1);

    //base case
    dptable[0] = 1;
    
    for(int i=1;i<=n;i++){
        long long int numways=0;
        for(auto j:steps){
            if( (i-j) >= 0){
                numways += dptable[i-j];
            }
        }
        dptable[i] = numways;
    }

    return dptable[n];
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


