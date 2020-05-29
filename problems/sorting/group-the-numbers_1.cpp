#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector <int> solve(vector <int> arr) {

    int odd_index,even_index;

    even_index=0;
    odd_index=arr.size() - 1;

    while (odd_index >= even_index)
    {
        /*reach the first even number from back*/
        while( (arr[odd_index]%2 == 1) && (odd_index >= even_index )){odd_index--;}
        /*reach the first odd number from the front*/
        while((arr[even_index]%2 == 0 ) && (odd_index >= even_index) ){even_index++;}
        cout << "odd_index : " << odd_index << "even_index : " << even_index << endl;         
        /* swap elements*/
        if(odd_index > even_index){
            int tmp = arr[odd_index];
            arr[odd_index] = arr[even_index];
            arr[even_index] = tmp;
        } 
    }
    return arr;
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

    res = solve(arr);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}


