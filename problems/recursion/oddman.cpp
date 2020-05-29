#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> &a , int i , int j)
{
    return accumulate(a.begin()+i,a.begin()+j+1,0);
}

/*
     below function takes a vector of int and find's out the position
     of a single odd element. It works if-and-only-if (iff) the array has one
     odd element. by definition minium array size has to be 3
     Running time is bound by "log n base 3"
     in the below algorithm we traverse only the path that will yield result.
*/
void find_oddman( vector<int> &a , int i , int j , int &oddman)
{
    if(i == j)
    {
        oddman=i;
        return;
    }

    // split the array into 3  
    // if the number of elements is not divisible by 3 , the last partition will
    // have elements between 1 and n modulo 3 
    
    int n = j-i+1;  // Total number of elements in the array
    int partitions = 3; // number of partitions
    int psize = n/3; // size of partition 1 and 2.
    int p3size; // This is variable
    if(n%3 <= 1)
    {
        int p3size = psize + (n%3);   // size of partition #3 . 
    } else {
        // we are here because n%3 = 2.
        // distribute the 2 additional elements to p1 and p2
        // by incrementing psize
        p3size = n/3;
        psize++;
      
    }

    int p1s,p1e,p2s,p2e,p3s,p3e; // start and end index of each of the 3 partitions

    p1s=i;
    p1e=i+(psize-1);
    p2s=p1e+1;
    p2e=p2s+(psize-1);
    p3s=p2e+1;
    p3e=p3s+(p3size-1);

    if(psize == 0)
    {
        // it has to be 2 elements and elements cannot be equal.
        // follows from the fact that we are always looking at 
        // an array that has result 
        if(a[i] < a[j]) {
            find_oddman(a,i,i,oddman);
            return;
        } else {
            find_oddman(a,j,j,oddman);
            return;
        }

    }
    if( sum(a,p1s,p1e) <  sum(a,p2s ,p2e))
    {
        find_oddman(a,p1s,p1e,oddman); // our oddman is in partition p1
        return;
    } else if( sum(a,p1s,p1e) > sum(a,p2s ,p2e) )
    {
        find_oddman(a,p2s, p2e,oddman); // our oddman is in partition p2
        return;
    } else {
        find_oddman(a,p3s , p3e,oddman); // our oddman is in partition p3
        return;
    }
    return;
}

int main()
{
    int oddman=10;

    vector<int> a = { 2,2,2,2,1,2,2,2 };
    find_oddman(a,0,7,oddman);
    cout << oddman<<endl; 

    vector<int> b = { 2,2,2,2,2,2,2,1 };
    find_oddman(b,0,7,oddman);
    cout << oddman<<endl; 

    vector<int> c = { 1,2,2,2,2,2,2,2 };
    find_oddman(c,0,7,oddman);
    cout << oddman<<endl; 

    vector<int> d = { 2,2,2,2,2,2,1,2 };
    find_oddman(d,0,7,oddman);
    cout << oddman<<endl; 
    return 0;
}


