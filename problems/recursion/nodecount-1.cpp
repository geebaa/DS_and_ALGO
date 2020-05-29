#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
void helper(int &sum,int n) {

    if(n == 1){
        sum++;
        return;
    }


    helper(sum , n-1);
    helper(sum , n-1);

    if(n > 2) {
        helper(sum,n-2);
    }

}

int main()
{
    int sum=0;
    helper(sum,4);
    cout << " Number of trees : " << sum << endl;
    return 0;
}


