#include <bits/stdc++.h>

using namespace std;

// Complete the maxStolenValue function below.
int maxStolenValue(vector<int> values) {
    int result;
    vector< int > dp_table(values);
    int size = values.size();

    // 2 dummy pushes are required since the reccurance 
    // will try to exceed the array and call these values
    // these are the base conditions

    dp_table.push_back(0);
    dp_table.push_back(0);
    for(int i = size-1;i>=0;i--){
        dp_table[i] = max(values[i] + dp_table[i+2],dp_table[i+1]);
    }
    result=dp_table[0];

    return result;

}

int main()
{
    ostream &fout = cout;

    int values_count;
    cin >> values_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> values(values_count);

    for (int i = 0; i < values_count; i++) {
        int values_item;
        cin >> values_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        values[i] = values_item;
    }

    int res = maxStolenValue(values);

    fout << res << "\n";

    

    return 0;
}

