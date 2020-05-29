#include<bits/stdc++.h>
using namespace std;


int paint_fence(int n,int k)
{

    // lets define the objective function as below
    // total #way to paint 1 to ith post 
    // this follows from the problem statement that
    // total(i) = same(i) + diff(i)
    // same(i) = #of ways to paint 1 to ith post 
    // with (i-1)th post and ith post having same color
    // diff(i) = # of ways to paint 1 to ith post
    // with (i-1)th post and ith post having diff color
    // 
    // lets get a reccurance for diff(i)
    // this can be of any color that was not the color of (i-1)th fence
    // i.e  (k-1)*total(i-1) --->  (k-1) is to discard the color of (i-1)th fence 
    // 
    // lets get the reccurance for same(i)
    // this can be obtained by choosing the same color as the (i-1)th post
    // given that (i-2)th post is different from (i-1)th post
    // which is nothing but diff(i-1)
    // same(i) = diff(i-1)
    // our result will be in total(i)

    // note that we ignore 0th index
    vector<int> same(n+1,0),diff(n+1,0),total(n+1,0);

    // special case

    if(n==1){
        return k;
    }

    //base cases
    // if there is only one fence same and diff has no meaning
    // total is k
    total[1]=k;
    // if there are 2 fences
    // total ways of painting 2 fences with same color is k
    same[2]=k;
    // total ways of painting 2 fences with diff color is k*(k-1)
    diff[2]=k*(k-1);
    // total ways of painting 2 fences = same[2] + diff[2]
    total[2] = same[2]+diff[2];


    // for a general i
    for(int i=3;i<=n;i++){
        same[i] = diff[i-1];
        diff[i] = (k-1)*total[i-1];
        total[i] = same[i]+diff[i];
    }

    return total[n];

}

int main()
{
    int n,k;
    cin >> n;
    cin >> k;
    cout << paint_fence(n,k);
    return 1;
 
}
