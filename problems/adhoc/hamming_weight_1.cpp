#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the calculateHammingWeight function below.
 *
 * Complete the calculateHammingWeight function below.
 * @param s : input array as parameter.
 */

int calculateHammingWeight(vector<long long> &s)
{
    int result=0;
    for(auto i:s){
        while(i>0){
            result += i&1;
            i=i>>1;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<long long> s(n);

    for (int i = 0; i < n; i++)
    {
        long long int s_item;
        cin >> s_item;
        s[i] = s_item;
    }

    ostream &fout = cout;

    int result = calculateHammingWeight(s);

    fout << result << endl;

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}


