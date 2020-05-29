#include <bits/stdc++.h>

using namespace std;

void helper(vector <long long int> &arr,int i,long long &k,bool &result,vector <long long int> &bag)
{
    //backtracking case
    if(k == 0){
        if(bag.size() !=0 ){
            // non-empty
            result = true;
            return;
        }
    }
    // base case
    if(i == arr.size()){
        return;
    }

    // recursive case
    //include path
    k-=arr[i];
    bag.push_back(arr[i]);
    helper(arr,i+1,k,result,bag);
    bag.pop_back();
    k+=arr[i];
    if(result == true){
        // solution found
        return;
    }
    // exclude path
    helper(arr,i+1,k,result,bag);


}

/*
 * Complete the function below.
 */
bool check_if_sum_possible(vector <long long int> arr, long long int k) {
    bool result=false;
    vector <long long int> bag;
    helper(arr,0,k,result,bag);
    return result;
}


int main()
{
    ostream &fout = cout;

    bool res;
    int arr_size = 0;
    cin >> arr_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<long long int> arr;
    for(int i = 0; i < arr_size; i++) {
        long long int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        arr.push_back(arr_item);
    }

    long long int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = check_if_sum_possible(arr, k);
    fout << res << endl;

    
    return 0;
}


