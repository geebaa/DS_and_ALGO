#include <bits/stdc++.h>

using namespace std;

long long int countWaysToClimb(vector<int> steps, int n) {

    // start from 0 to n
    // dptable[i] = number of ways to climb to ith stair
    vector<long long int> dptable(n+1);

    //base case  ways of climbing from 0 to 0
    dptable[0] = 1;

    long long int ways_to_climb_ith_step;

    // compute the values for every entry
    for(int i=1;i<=n;i++){
        ways_to_climb_ith_step=0;
        for(auto step:steps){
            if(i-step>=0){
                ways_to_climb_ith_step += dptable[i-step];
            }
        }
        dptable[i]=ways_to_climb_ith_step;
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


