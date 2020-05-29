#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the merger_first_into_second function below.
 */
void merger_first_into_second(vector<int>& arr1, vector<int>& arr2) {
    /*
     * Write your code here.
     */
    int n=arr1.size();

    int a1_max=n-1;
    int a2_max=n-1;
    int curr=2*n - 1;


    while( (a1_max >= 0) && (a2_max >= 0) ){
        arr2[curr--] = (arr1[a1_max] > arr2[a2_max] ) ? arr1[a1_max--]:arr2[a2_max--];

    }
    while(a1_max >= 0){
        arr2[curr--]= arr1[a1_max--];
    }
    while(a2_max >= 0){
        arr2[curr--]= arr2[a2_max--];
    }

}


int main()
{
    ostream &fout = cout;

    int arr1_count;
    cin >> arr1_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr1(arr1_count);

    for (int arr1_itr = 0; arr1_itr < arr1_count; arr1_itr++) {
        int arr1_item;
        cin >> arr1_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr1[arr1_itr] = arr1_item;
    }

    int arr2_count;
    cin >> arr2_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr2(arr2_count);

    for (int arr2_itr = 0; arr2_itr < arr2_count; arr2_itr++) {
        int arr2_item;
        cin >> arr2_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr2[arr2_itr] = arr2_item;
    }

    merger_first_into_second(arr1, arr2);

    arr2_count = arr2.size();

    for (int arr2_itr = 0; arr2_itr < arr2_count; arr2_itr++) {
        fout << arr2[arr2_itr];

        if (arr2_itr != arr2_count - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    

    return 0;
}


