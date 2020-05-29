#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the equalSubSetSumPartition function below.
 *
 * @param s : input array as parameter.
 */

vector<bool> equalSubSetSumPartition(vector<int> &s)
{

    int n=s.size();
    vector<bool> result(n,false);
    unordered_map<int,bool> dptable[n];
    int min_sum , max_sum;
    min_sum=0;
    max_sum=0;
    int full_sum = accumulate(s.begin(),s.end(),0);
    if(full_sum % 2) {
        cout << "fullsum is odd" << endl;
        return {};
    }
    int half_sum = full_sum / 2;
    /*These form the columns in the dptable*/
    for(auto val : s){
        if(val < 0){ 
            min_sum+=val;
        } else {
            max_sum+=val;
        }
    }

    cout << " min sum : " << min_sum << "max sum : " << max_sum << endl;
    cout << " s[0] : " << s[0] << endl;
    dptable[0][s[0]]=true;
   
    cout << "rows : " << n << "min_sum : " << min_sum << "max_sum : " << max_sum << endl;
    // direction of population is increasing rows in dptable 
    for(int i=1;i<n;i++) {
        cout << endl;
        cout << i << " : ";
        for(int val=min_sum;val<=max_sum;val++){
            dptable[i][val] = dptable[i-1][val]; 
            if(val == s[i]) {
                dptable[i][val] = true;// like base case ith element can satisfy 'val' just by adding itself   
            } else if(val-s[i] >= min_sum ){
                dptable[i][val] |= dptable[i-1][val-s[i]]; // " val-s[i] " should be between min_val to max_val
            }
            cout << dptable[i][val] << " " ;
        }
    }

    if(dptable[n-1][half_sum]){
//        cout << "partition is possible " << endl;
    } else {
//        cout << "partition is not possible " << endl;
        return {};
    }

    
    //backtracking
    int required_sum = half_sum;
    int cnt=0; // track num elements included in a set
    for(int i=n-1;i>=0;i--){
        if(i==0){
            // root element always included
            result[i] = 1;
            cnt++;
        } else {
            // include path only if [i-1][required]  is false 
            if( (dptable[i-1][required_sum]==false) && (dptable[i][required_sum] == true)){
                result[i]=true;
                required_sum -= s[i];
                cnt++;
                if(required_sum == 0) {
                    break;
                }
            } 
        }
    }
    if(cnt == n){
        result.clear();
    }
    return result;
}


int main()
{
    int n;
    cin >> n;

    vector<int> s(n);

    for (int i = 0; i < n; i++)
    {
        int S_item;
        cin >> S_item;
        s[i] = S_item;
    }

    ostream &fout = cout;

    vector<bool> result = equalSubSetSumPartition(s);

    if (result.size() == 0)
    {
        fout << -1 << endl;
        return 0;
    }

    int s1 = 0, s2 = 0;

    for (int i = 0; i < result.size(); i++)
    {
        if (result[i]) {
            s1++;
        }
        else {
            s2++;
        }
    }

    fout << s1 << endl;
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i]) {
            fout << s[i] << endl;
        }
    }

    fout << s2 << endl;
    for (int i = 0; i < result.size(); i++)
    {
        if (!result[i]) {
            fout << s[i] << endl;
        }
    }

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

