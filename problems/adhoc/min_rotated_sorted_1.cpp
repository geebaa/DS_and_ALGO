#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int find_minimum(vector<int> arr) 
{
    // Write your code here
    int n=arr.size();
    int start=0,end=n-1;
    int mid;
    while(start <= end){
        if(arr[start] <= arr[end]){
            return arr[start];
        }else{
            mid=(start+end)/2;
            if(arr[mid] >= arr[start]){
                start=mid+1;
                continue;
            }else{
                end=mid;
                continue;
            }

        }
    }
    return 0; 
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string num_temp;
        getline(cin, num_temp);

        int num = stoi(ltrim(rtrim(num_temp)));

        arr[i] = num;
    }
    ostream &fout = cout;

    int result = find_minimum(arr);
    fout<<result<<endl;
    
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


