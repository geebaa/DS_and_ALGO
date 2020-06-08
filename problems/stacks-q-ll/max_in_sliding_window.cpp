#include <bits/stdc++.h>

using namespace std;

int find_max(vector <int> &arr,int s,int e)
{
    // linear search for max instead of priority_queue
    // to check performance
    int max_val=INT_MIN;
    for(int i=s;i<=e;i++){
        max_val=max(max_val,arr[i]);
    }
    return max_val;
}

vector <int> max_in_sliding_window(vector <int> arr, int w) 
{

    // brute force solution is to find max on each subarray    
    vector<int> result;
    int n=arr.size();
    int num_itr = n - w +1;
    for(int i=0;i<num_itr;i++){
        int s=i,e=i+w-1;
        cout << " s : " << s << " e : " << e<< endl;
        
        //int max = *max_element(arr.begin()+s,arr.begin()+e+1);
        int max = find_max(arr,s,e);
        result.push_back(max);
    }

    return result;

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

    int w;
    cin >> w;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = max_in_sliding_window(arr, w);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}


