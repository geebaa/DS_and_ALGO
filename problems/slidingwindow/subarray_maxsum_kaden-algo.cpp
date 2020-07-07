#include<bits/stdc++.h>

using namespace std;

int curr_s,curr_e;
int max_s,max_e;
int max_global;

// this algo tracks the max sum subarray and also tracks the indices  

void kaden_max_sum(vector<int> &arr)
{
    // max_curr is max value at index "i"
    int max_curr;
    max_curr=arr[0];
    curr_s=0;
    curr_e=0;
    max_global=max_curr;
    max_s=curr_s;
    max_e=curr_e;
    for(int i=1;i<arr.size();i++){
        if(max_curr + arr[i] < arr[i]){
            max_curr = arr[i];
            curr_s=i;
            curr_e=i;
        }else{
            max_curr += arr[i];
            curr_e=i;
        }
        if(max_curr > max_global){
            max_global = max_curr;
            max_s=curr_s;
            max_e=curr_e;
        }
    }
}


void kaden_max_sum_no_index_tracking(vector<int> &arr)
{
    // max_curr is max value at index "i"
    int max_curr;
    max_curr=arr[0];
    max_global=max_curr;
    for(int i=0;i<arr.size();i++){
        max_curr=max(max_curr+arr[i],arr[i]);
        max_global=max(max_global,max_curr);
    }
}

int main()
{
    vector<int> arr={-2,2,5,11,6,-5,-2,2,-4,25};

    kaden_max_sum(arr);
    cout << "max sum : " << max_global<< " s : " << max_s << " e : " << max_e << endl;
    kaden_max_sum_no_index_tracking(arr);
    cout << "max sum no index tracking : " << max_global<< endl;
}

