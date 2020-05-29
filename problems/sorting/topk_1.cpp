#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector <int> topK(vector <int> arr, int k) {

}

int main()
{
    ostream &fout = cout;

    vector <int> res;
    int arr_size = 0;
    cin >> arr_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> arr;
    for(int i = 0; i < arr_size; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        arr.push_back(arr_item);
    }

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = topK(arr, k);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}

