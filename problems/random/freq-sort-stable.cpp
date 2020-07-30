#include<bits/stdc++.h>
using namespace std;
/*
    problem statement - given an array of positive integers
    sort them in descending order of the elements in frequencies
    and output the array. Each unique element appears only
    once in the output array. If some elements have same frequency
    they appear in the output array in the order they appear in input array
*/

vector<int> result;

void freq_sort_stable(vector<int> &nums)
{
    unordered_map<int,int> num_freq;
    unordered_map<int,vector<int>> freq_nums;
    int maxfrequency=INT_MIN;
    
    for(auto num:nums){
        num_freq[num]++;
        maxfrequency=max(maxfrequency,num_freq[num]);
    }
    
    for(auto num:nums){
        if(num_freq[num]){
            freq_nums[num_freq[num]].push_back(num);
            num_freq.erase(num);
        }
    }
    
    for(int i=maxfrequency;i>=1;i--){
        for(auto num:freq_nums[i]){
            result.push_back(num);
        }
    }
    
}


int main()
{
    vector<int> nums;
    nums={5,3,4,5,5,5,4,3,3,3,3};
    freq_sort_stable(nums);
    
    for(auto num : result){
        cout << " "<<num;
    }
    cout <<endl;

}

