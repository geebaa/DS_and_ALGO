#include<bits/stdc++.h>
using namespace std;

int max_sum=0;
int max_sum_s;
int max_sum_e;
void subarray_maxsum_sizek( vector<int> &arr,int &k)
{
    int s=0,e=k-1;
    max_sum=accumulate(arr.begin()+s,arr.begin()+e+1,0);
    max_sum_s = s;
    max_sum_e = e;
    int curr_sum=max_sum; 
    while(e<arr.size()){
        // slide window 
        s++;
        e++;
        if( e < arr.size()){
            //calculate curr_sum from the previous curr_sum by adding arr[e]
            // and removing arr[s-1]
            curr_sum -= arr[s-1];
            curr_sum += arr[e];
            if(max_sum < curr_sum){
                max_sum = curr_sum;
                max_sum_s = s;
                max_sum_e = e;
            } 
        }

    }
}
int main()
{
    vector<int> arr={10,2,3,4,0,5,6,7,8,9,11,3,6};
    int k=2;
    if(k<=arr.size()){
        subarray_maxsum_sizek(arr,k);
        cout << "max sum : " << max_sum << " s : " << max_sum_s << " e : " << max_sum_e << endl;
    }
}


