#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the isPresent function below.
 */
string isPresent(vector<vector<int>> arr, int x) {
    /*
     * Write your code here.
     */
    string result="not present";
    int nrows=arr.size();
    int ncols=nrows?arr[0].size():0;
    int curr_row_num=0;

    if((x < arr[0][0]) || ( x > arr[nrows-1][ncols-1])){
        return result;
    }
    int start_col=0;
    for(int i = nrows-1;i>=0;i--){
        if((x >= arr[i][start_col]) && (x <= arr[i][ncols-1])){
            if(binary_search(arr[i].begin()+start_col, arr[i].end(), x)){
                result = "present";
                break;
            }else{
                start_col =  (lower_bound(arr[i].begin(), arr[i].end(), x) - arr[i].begin()) - 1; 
                //start_col = (start_col>(ncols-1))?(ncols-1):start_col;
            }
        }
    }
    
    return result;


}
int main()
{
    ostream &fout = cout;

    int arr_rows;
    cin >> arr_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int arr_columns;
    cin >> arr_columns;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(arr_rows);
    for (int arr_row_itr = 0; arr_row_itr < arr_rows; arr_row_itr++) {
        arr[arr_row_itr].resize(arr_columns);

        for (int arr_column_itr = 0; arr_column_itr < arr_columns; arr_column_itr++) {
            cin >> arr[arr_row_itr][arr_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < q; ++i){
        int x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string res = isPresent(arr, x);

        fout << res << "\n";
    }

    

    return 0;
}

