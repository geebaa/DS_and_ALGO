#include <bits/stdc++.h>


using namespace std;


string ltrim(const string &);
string rtrim(const string &);

long find_integer(vector<long> &arr) {
    long result;
    
    // sort the array first to device an algo to return the non present number
    sort(arr.begin(),arr.end());

    //find the first space where there is a gap
    int n=arr.size();
    int s=0,e=n-1;
    int m;
    result=n; // return value if arr[0] to arr[n-1] contain values 0 to n-1
    while(s<e){
        m=s + (e-s)/2;
        if(m == arr[m]){
            // no gap in the left half
            // lets check m - 1 the element
            if(m+1<n){
                if(arr[m+1] - arr[m] > 1){
                    result = arr[m] + 1; 
                    break;
                }
            }
            //search the left 
            s=m+1;
            continue;
        }else{
            // gap is in left half
            // may be in the second half too but cant be sure
            // lets check m - 1 the element
            if(m-1>=0){
                if(arr[m] - arr[m-1] > 1){
                    result = arr[m-1] + 1; 
                    break;
                }
            }
            //search the left 
            e=m-1;
            continue;
        }
    }    

    return result;
}


int main()
{
    ostream &fout = cout;

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        long arr_item = stol(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = find_integer(arr);

    fout << result << "\n";

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

