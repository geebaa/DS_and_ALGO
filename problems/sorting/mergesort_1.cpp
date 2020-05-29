#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<int> merge(vector<int> &l , vector<int> &r){
    vector <int> result;
    int i=0;
    int j=0;
    int k=0;
    int lsize=l.size();
    int rsize=r.size();
    while( (i<lsize) && (j<rsize) ){
        if(l[i] <= r[j]){
            result.push_back(l[i]);
            i++;
        } else {
            result.push_back(r[j]);
            j++;
        }
    }

    while(i<lsize){
        result.push_back(l[i]);
        i++;
    }
    while(j<rsize){
        result.push_back(r[j]);
        j++;
    }
    return result;
}

vector<int> helper(vector<int> &arr , int start , int end)
{
    vector<int> l;
    vector<int> r;
    vector<int> result;
    if(end <= start) {
        result.push_back(arr[start]);
        return result;
    }

    int mid = start + ((end - start)/2);
    l=helper(arr,start,mid);
    r=helper(arr,mid+1,end);
    result=merge(l,r);
    return result;

}

/*
 * Complete the 'merge_sort' function below.
 *
 * The function accepts an integer array as parameter.
 */
 
vector<int> merge_sort(vector<int> &arr) {

    vector<int> result;
    result = helper(arr,0,arr.size()-1);

    return result;
}

int main()
{
    ostream &fout = cout;

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    vector<int> result = merge_sort(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";


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


