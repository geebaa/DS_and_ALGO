#include "bits/stdc++.h"
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the calculate_power function below.
 * @param a : base
 * @param b : exponent
 */
const int M=1000000007;
int helper(long long a, long long b)
{
    // base case
    if(b==0){
        return 1;
    }

    // recursive case
    return (a*(helper(a,b-1)%M))%M;
     
}
int calculate_power(long long a, long long b)
{
    // code goes here
    int result=1;
    result = helper(a,b);
    return result;
}


int main()
{
    long long a;
    long long b;
    cin >> a >> b;
    ostream & fout = cout;
    int result = calculate_power(a, b);
    fout << result << endl;
    return 0;
}

string ltrim(const string & str) {
    string s(str);

    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string & str) {
    string s(str);

    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());

    return s;
}

