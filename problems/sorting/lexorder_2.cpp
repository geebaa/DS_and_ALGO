#include <bits/stdc++.h>

using namespace std;

vector<string> solve(vector<string> arr) {
    vector<string> result;
    unordered_map <string,int> key_count;
    unordered_map <string,string> key_highest_val;

    for(auto i:arr){
        string key,value;
        int space_index=0;
        int n = i.size();
        space_index = i.find(" ");
        key   = i.substr(0,space_index);
        value = i.substr(space_index+1,(n-1) - (space_index+1) + 1); 
        if( key_count.find(key)  == key_count.end() ){
            key_count[key] = 1;
            key_highest_val[key] = value;
        }else{
            key_count[key] += 1;
            if(key_highest_val[key] < value){
                key_highest_val[key] = value;
            }
        }
    }
    for(auto i:key_count){
        string elem;
        elem = i.first + ':' + to_string(i.second) + ',' + key_highest_val[i.first];
        result.push_back(elem);
    } 
    return result;

}


int main()
{
    ostream &fout = cout;

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        string arr_item;
        getline(cin, arr_item);

        arr[arr_itr] = arr_item;
    }

    vector<string> res = solve(arr);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    

    return 0;
}


