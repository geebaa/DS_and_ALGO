#include <iostream>    
#include <algorithm> 
#include <vector>
using namespace std;

int main ()
{
    int input[] = {1,3,5,7,10,45};
    vector<int> v(input, input+6);
    
    vector<int>::iterator it1 , it2,it3,it4;
    
    it1 = upper_bound(v.begin(), v.end(), 3); 
    it2 = upper_bound(v.begin(), v.end(), 4);

    cout << "it1 : " << *it1 << " it2 : " << *it2 << endl;

    it3 = lower_bound(v.begin(), v.end(), 3); 
    it4 = lower_bound(v.begin(), v.end(), 4);
    cout << "it3 : " << *it3 << " it4 : " << *it4 << endl;
}
