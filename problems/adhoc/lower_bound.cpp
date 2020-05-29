#include <iostream>     
#include <algorithm>   
#include <vector>
using namespace std;

int main ()
{
    int input[] = {1,2,2,3,4,4,5,6,7,8,10,45};
    vector<int> v(input,input+12);
    
    vector<int>::iterator it1 , it2;
    
    it1 = lower_bound(v.begin(), v.end(), 4); 
    /* points to fifth element in v */ 
    
    it2 = lower_bound (v.begin(), v.end(), 10);
    /* points to second last element in v */
}
