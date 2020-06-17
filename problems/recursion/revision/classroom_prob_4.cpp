#include<bits/stdc++.h>
using namespace std;

int numsubsets;

void subset_sum(vector<int> &numset,int sum_remaining,int i)
{
    //backtracking case
    if(sum_remaining < 0){
        // since no negative numbers , we can backtrack
        return;
    }
    
    //base case
    if(sum_remaining == 0){
        numsubsets++;
        return;
    }
    if(i == numset.size()){
        return;
    }
    
    //recursive case
    // include curr i in the sum 
    subset_sum(numset,sum_remaining- numset[i],i+1); 
    //exclude curr i in the sum
    subset_sum(numset,sum_remaining,i+1); 
}

int main()
{
    vector<int> numset;
    numset = {1,2,3};
    int required_sum=10;
    numsubsets=0;
    subset_sum(numset,required_sum,0);
    cout << " Num subset : " << numsubsets<<endl;

}

