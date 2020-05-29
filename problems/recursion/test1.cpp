#include <bits/stdc++.h>

using namespace std;



bool helper(vector <long long int> arr, long long int k, long long int sum,int &count )
{
    if(count > 0)
    {
        return true;
    }
    if(sum == k)
    {
        count++;
        return true;
    }

    if(0 == arr.size())
    {
        return false;
    }
    if(sum > k)
    {
        return false;
    }

    long long int val_removed;
    //cout << "arr.size : " << arr.size() << endl;
    for(int i=0;i<arr.size();i++)
    {
        //cout << "i : " << i << endl;
        //new_arr = arr;
        val_removed = arr.at(i);
        sum += arr.at(i);
        arr.erase(arr.begin() + i);
        if( helper(arr,k,sum,count) ) { return true;}
        arr.insert(arr.begin() + i,val_removed);
        sum -= arr.at(i);
        
    }

    return false;    

}

/*
 * Complete the function below.
 */
bool check_if_sum_possible(vector <long long int> arr, long long int k) {

    int count=0;
    helper(arr,k,0,count);
    cout << "Count : " << count << endl;
    return (count > 0);
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


