#include <bits/stdc++.h>

using namespace std;

// Complete the sumZero function below.
vector<int> sumZero(vector<int> arr) {
    unordered_map<int,int> accumulated_sum_map;
    vector<int> result;
    unordered_map<int,int>::iterator sum_previously_seen_at;
    int curr_sum=0;
    int index=0;
    accumulated_sum_map[0]=0;
    for(auto i:arr){
        curr_sum+=i;
        sum_previously_seen_at = accumulated_sum_map.find(curr_sum);
        if(curr_sum == 0){
                result.push_back(sum_previously_seen_at->second);
                result.push_back(index);
                return result; 
        }
        if(sum_previously_seen_at == accumulated_sum_map.end()){
            accumulated_sum_map[curr_sum]=index;
        }else{
            //a zerosum subsequence exists between current index and the one stored in map
            result.push_back(sum_previously_seen_at->second +1);
            result.push_back(index);
            return result; 
        }
        index++;
    } 
    result.push_back(-1);
    return result;
}

int main()
{
    ostream &fout = cout;

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    vector<int> res = sumZero(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    

    return 0;
}


