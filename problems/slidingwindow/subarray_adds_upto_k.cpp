#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int>curr;

void subarray_sum(vector<int> &arr,int &k)
{
    // find all subarrays of arr that adds up to k
    int s=0,e=0;
    int window_sum=arr[s];
    while(e<arr.size()){
        if(window_sum < k){
            //expand the window till the size of arr
            e++;
            if(e < arr.size()){
                window_sum += arr[e];
            }
        }else if(window_sum>k){
            // shrink the window and adjust when s moves past e
            s++;
            if( s>e ){
                e=s;
                if(s<arr.size()){
                    window_sum=arr[s];
                }
            }else{
                window_sum -= arr[s-1];
            }
        }else{
            // found target sum between s and e
            // expand the window after storing the result
            // expansion is required since there may be '0' that
            // could give another subarray.
            vector<int> subarray(arr.begin()+s,arr.begin()+e+1);
            result.push_back(subarray);
            for(auto elem:subarray){
                cout << " " << elem;
            }
            cout <<endl;
            //expand
            e++;
            if(e < arr.size()){
                window_sum += arr[e];
            }
        }
    }
}

int main()
{
    vector<int> arr={10,2,3,4,0,5,6,7,8,9,11,3,6};
    int k=9;

    subarray_sum(arr,k);
}

