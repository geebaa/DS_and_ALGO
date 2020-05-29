#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector<string> findZeroSum(vector<int> arr) {
    // Write your code here.
    vector<string> result;
    string triplet;
    int a,b,c;
    int i,j,k;
    int arrsize=arr.size();
    int required_sum=0;
    int curr_sum;
    if(arrsize<3){
        return result;
    }
    // important step is SORTING
    sort(arr.begin(), arr.end());

    for(i=0;i<arrsize;i++){
        curr_sum=arr[i];
        required_sum=0-curr_sum;
        j=i+1;
        k=arrsize-1;
        while(j<k){
            if(required_sum == (arr[j] + arr[k])) {
                //one triplet found
                ostringstream os;
                os << arr[i] << ',' << arr[j] << ',' << arr[k] ;
                result.push_back(os.str());
                //next unique jth element
                while( (j<k) && (arr[j] == arr[j+1]) ){
                    j++;
                }
                j++;
                //next unique kth element
                while( (j<k ) && (arr[k] == arr[k-1]) ){
                    k--;
                }
                k--;
                continue; // continue finding other triplets for the same i
            } else if(required_sum >  (arr[j] + arr[k]) ) {
                //next unique jth element
                while( (j<k) && (arr[j] == arr[j+1]) ){
                    j++;
                }
                j++;
            } else {
                //next unique kth element
                while( (j<k ) && (arr[k] == arr[k-1]) ){
                    k--;
                }
                k--;
            }
        }
        //next unique ith element
        while( ((i+1 ) < arrsize) && (arr[i] == arr[i+1])  ){
            i++;
        }

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


