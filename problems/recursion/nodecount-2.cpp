#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
unsigned long long int helper(int n) {

    if(n == 0){
        return 1;
    }

    // For any n > 0 , the number of unique binary trees 
    // will be the following
    //  for all i in 0 - number_of_nodes
    //   count = (number of unique btrees in left subtree with node count i )* 
    //   (number of unique btrees in right sub tree with node count n - 1 - i)
    //  
    unsigned long long int bstcount=0ULL;
    for(int i=0;i<n;i++)
    {
         bstcount += helper(i) * helper(n-1-i);
    }    
    return bstcount;
}

int main()
{
    unsigned long long int sum=0ULL;
    int nc;   
    cin >>  nc;
    sum = helper(nc);
    cout <<    helper(nc) << endl;
    return 0;
}


