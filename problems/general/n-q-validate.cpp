#include <bits/stdc++.h>

using namespace std;

/*
   The idea of this function is to take a chessboard with "n"-queens placed 
   on them in the form of a vector of size "n" . Index in  the vector 
   represents the row and value at the index represents the column.
   suppose a integer vector of {2,0,3,1} is the input , here note the values 
   range from 0 to 3. This represents a 4x4 chess board with Queen's placed 
   at the following locations 
      (0,2) , (1,0) , (2,3) , (3,1)  
      (0,a[0]) , (1,a[1]) , (2,a[2]) , (3,a[3])
   Since no duplicates are allowed ,by definition 
   there cannot be 2 queens in the same row or column.
   The function's job now reduces to checking for diagonals.

   How to do that in a single pass ?
   here comes the linear algebra to our help. Any line is of the 
   form y = m*x + c where 'm' is the slope and 'c' a constant.
   now since these are queen's , the diagonals have a slope of 1 and -1.
   that means if a coordinate (j,a[j]) has to be cut by 
   a queen placed at (i,a[i]) one of the following conditions must hold.
   
   ( (a[j] - a[i] ) / (j - i) ) == 1 or -1
   
   which is 
   (a[j] - j ) = (a[i] - i) or (a[j] + j) = (a[i] + i)  

   to do this in a single pass , as and when we encounter a coordinate 
   , we check if it cuts any of the previous lines by looking up the
   sets diag1 and diag2. If so , return false else add the current difference 
   and sum to diag1 and diag2 respectively.  
   
*/

bool is_nq( vector<int> &a )
{
    set<int> diag1,diag2;
    int val1,val2;
    for(int i=0;i<a.size();i++)
    {
        // (a,a[i]) is a coordinate.
        // a) see if (a[i] - i ) is added in set 
        //    if not add else bail out returning false 
        // b) see if (a[i] + i) is added in set 
        //    if not add else bail out returning false 
        val1=a[i]-i;
        val2=a[i]+i;
        if(diag1.find(val1) != diag1.end()) {
            //bail out
            return false;
        }
        if(diag2.find(val2) != diag2.end()) {
            //bail out
            return false;
        }
        diag1.insert(val1);
        diag2.insert(val2);

    }

    return true;
}

int main()
{
    vector<int> a={2,1,3,0};
    cout << "is_nq : " << is_nq(a) << endl;

    vector<int> b={2,0,3,1};
    cout << "is_nq : " << is_nq(b) << endl;

    vector<int> c={1,4,6,3,0,7,5,2};
    cout << "is_nq : " << is_nq(c) << endl;

    vector<int> d={1,2,6,3,0,7,5,4};
    cout << "is_nq : " << is_nq(d) << endl;

    return 0;
}


