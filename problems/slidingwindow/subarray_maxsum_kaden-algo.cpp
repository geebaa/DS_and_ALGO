#include<bits/stdc++.h>

using namespace std;

int s,e;
int max_global;

void kaden_max_sum(vector<int> &arr)
{
    // max_curr is max value at index "i"
    int max_curr;
    max_curr=arr[0];
    max_global=max_curr;

    for(int i=1;i<arr.size();i++){
        max_curr = max(max_curr + arr[i],arr[i]);
        max_global=max(max_global,max_curr);
    }
}

int main()
{
    vector<int> arr={-2,1,-5,2,-5,3,-1};

    kaden_max_sum(arr);
    cout << "max sum : " << max_global<< " s : " << s << " e : " << e << endl;
}

