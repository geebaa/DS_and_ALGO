#include <bits/stdc++.h>

using namespace std;


void find_next_unique_index(vector<int> &arr,int &index,int bound_index, bool ascending){
    if(ascending){
        while(index < bound_index){
            if(arr[index] == arr[index+1]){
                index++;
            }else{
                return;
            }
        }
    }else{
        while(index > bound_index){
            if(arr[index] == arr[index-1]){
                index--;
            }else{
                return;
            }
        }
    }
}

/*
 * Complete the function below.
 */
vector<string> findZeroSum(vector<int> arr) {
    vector<string> result;
    
    sort(arr.begin(),arr.end());
    int n=arr.size();

    for(int i=0;i<n;i++){
        // for every i , we need a sum as below from j and k index
        int needed_sum = 0 - arr[i];
        // for every i , k is last element and j is the next element after i
        int j=i+1,k=n-1; 

        while (j<k){
            if(needed_sum == arr[j] + arr[k]){
                // one solution
                string s = to_string(arr[i])+','+to_string(arr[j])+','+to_string(arr[k]);
                result.push_back(s);
                // find the next unique j < k
                find_next_unique_index(arr,j,k,true);
                j++;
                // find the next unique k > j
                find_next_unique_index(arr,k,j,false);
                k--;
            } else if (needed_sum > arr[j] + arr[k]){
                // find the next unique j < k
                find_next_unique_index(arr,j,k,true);
                j++;
            } else {
                // find the next unique k > j
                find_next_unique_index(arr,k,j,false);
                k--;
            }
        }
        // find the next unique k > j
        find_next_unique_index(arr,i,n,true);

    }

    return result;
}

int main()
{
    ostream &fout = cout;

    int arr_size;
    cin >> arr_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(arr_size);
    for (int arr_i = 0; arr_i < arr_size; arr_i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[arr_i] = arr_item;
    }

    vector<string> res = findZeroSum(arr);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    

    return 0;
}

