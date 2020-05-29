#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> elem1, vector<int> elem2) 
{ 
    return (elem1[0] < elem2[0]); 
}
/*
 * Complete the getMergedIntervals function below.
 */
vector<vector<int>> getMergedIntervals(vector<vector<int>> inputArray) {
    /*
     * Write your code here.
     */

    vector<vector<int>> result;

    sort(inputArray.begin(),inputArray.end(),compare);
    vector<int> curr;
    curr=inputArray[0];
    for(auto i:inputArray){
        //cout << " elem : (" << i[0] << " , " << i[1] << " )" << endl;
        if(curr[1] >= i[0]){
            curr[1] = max(curr[1],i[1]);
        }else{
            result.push_back(curr);
            curr=i;
        }
    }
    result.push_back(curr);

    return result;
}

int main()
{
    ostream &fout = cout;

    int inputArray_rows;
    cin >> inputArray_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int inputArray_columns;
    cin >> inputArray_columns;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> inputArray(inputArray_rows);
    for (int inputArray_row_itr = 0; inputArray_row_itr < inputArray_rows; inputArray_row_itr++) {
        inputArray[inputArray_row_itr].resize(inputArray_columns);

        for (int inputArray_column_itr = 0; inputArray_column_itr < inputArray_columns; inputArray_column_itr++) {
            cin >> inputArray[inputArray_row_itr][inputArray_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<vector<int>> res = getMergedIntervals(inputArray);

    for (int res_row_itr = 0; res_row_itr < res.size(); res_row_itr++) {
        for (int res_column_itr = 0; res_column_itr < res[res_row_itr].size(); res_column_itr++) {
            fout << res[res_row_itr][res_column_itr];

            if (res_column_itr != res[res_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (res_row_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    

    return 0;
}

