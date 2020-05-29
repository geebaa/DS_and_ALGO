#include <bits/stdc++.h>

using namespace std;

vector<int> find_rows_to_search(map<int,int> &min_map,map<int,int> &max_map,int x){
    vector<int> result;
    int n=min_map.size();
    int min_index_lt_x,max_index_gt_x;
    int min_index_start,min_index_end,max_index_start,max_index_end;
    int search_row_start,search_row_end;
    map<int,int> :: iterator itr;
    //cout << endl;
    //for(auto i:min_map){
    //    cout << " first : " << i.first << " second : " << i.second << endl;
    //}
    //cout << endl;
    //for(auto i:max_map){
    //    cout << " first : " << i.first << " second : " << i.second << endl;
    //}
    //cout << endl;

    // find the bounds for the elements
    min_index_start=0;
    itr = min_map.upper_bound(x);
    if(itr == min_map.end()){
        //cout << "END of MIN MAP" << endl;
        min_index_end=n-1;
    } else {
        min_index_end = itr->second;
    }
    //cout << "  itr->second : " << itr->second << " min_index_start : " << min_index_start << " min_index_end : " << min_index_end << endl;

    itr = max_map.lower_bound(x);
    if(itr == max_map.end()){
        //cout << "END of MAX MAP" << endl;
        max_index_end=n-1;
    }else{
        max_index_start = itr->second;
    }
    max_index_end=n-1;
    //cout << " max_index_start : " << max_index_start << " max_index_end : " << max_index_end << endl;
    // find the intersection of the range and those are the rows to search
    search_row_start = max(min_index_start,max_index_start); 
    search_row_end = min(min_index_end,max_index_end);
    //cout << " search_row_start : " << search_row_start << " search_row_end : " << search_row_end << endl;
    if(search_row_start <= search_row_end){
        result.push_back(search_row_start);
        result.push_back(search_row_end);
    }
    return result;
}
/*
 * Complete the isPresent function below.
 */
static int ctr=0;
string isPresent(vector<vector<int>> arr, int x) {
    /*
     * Write your code here.
     */
    string result="not present";
    int nrows=arr.size();
    int ncols=nrows?arr[0].size():0;
    int curr_row_num=0;
    //vector<int> min_arr,max_arr;
    map<int,int> min_map,max_map;
    vector<int> rows_to_search;
    for(auto curr_row:arr){
        int min=curr_row[0];
        int max=curr_row[ncols-1];
        if(min_map.find(min)==min_map.end()){
            min_map[min]=curr_row_num;
        }
        max_map[max]=curr_row_num;
        curr_row_num++;
    }
    rows_to_search=find_rows_to_search(min_map,max_map,x);
    
    if(!rows_to_search.empty()){
        for(int i = rows_to_search[0];i<=rows_to_search[1];i++){
            if(binary_search(arr[i].begin(), arr[i].end(), x)){
                result = "present";
                break;
            }
        }
    }
    cout << "ctr : " << ctr++ << endl;
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
