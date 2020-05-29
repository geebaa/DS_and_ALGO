#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector<int> getProductArray(vector<int> nums) {
    // Write your code here.
    const unsigned int M = 1000000007;
    vector<int> result(nums.size());
    int prod_so_far=1;
    long long tmp;
    for(int i=0;i<nums.size();i++){
        result[i]=prod_so_far;
        nums[i] = nums[i]>0?nums[i]:(M+nums[i])%M;
        tmp = (prod_so_far*1ll*nums[i]);
        prod_so_far = (int)(tmp%M);
    }
    prod_so_far=1;
    for(int i=nums.size()-1;i>=0;i--){
        result[i]=(result[i]*prod_so_far) % M;
        tmp = (prod_so_far*1ll*nums[i]);
        prod_so_far = (int)(tmp%M);
        
    }
    return result;

}

int main()
{
    ostream &fout = cout;

    int nums_size;
    cin >> nums_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> nums(nums_size);
    for (int nums_i = 0; nums_i < nums_size; nums_i++) {
        int nums_item;
        cin >> nums_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        nums[nums_i] = nums_item;
    }

    vector<int> res = getProductArray(nums);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    

    return 0;
}

