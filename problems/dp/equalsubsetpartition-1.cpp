#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

bool helper(vector<int>&s1,vector<int> &s,int i,int remainingsum,vector<int> &result_index){

        // base case if at leaf and sum collected in set s1 == halfsum ,
        // we have a solution    
        if(i == s.size()) {
            if(remainingsum==0){
                //cout << "s1 : " ;
                //for (auto const& i: s1) {
		//    cout << i << " ";
	        //}
                //cout << endl;

                //cout << "result_index : " ;
                //for (auto const& i: result_index) {
		//    cout << i << " ";
	        //}
                //cout << endl;
                if( (s1.size() != 0) && (s1.size() != s.size() ) ){
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        bool incl_path,excl_path;

        // exclude ith element from s1
        excl_path=helper(s1,s,i+1,remainingsum,result_index);  
        if(excl_path == true) {
            // we stop exploring further tree's 
            // if we have one successful path
            return true;
        } 
        // include ith element in s1
        s1.push_back(s[i]);
        result_index.push_back(i);
        incl_path=helper(s1,s,i+1,remainingsum-s[i],result_index);
        if(incl_path == false){
            // pop only if the path did not yield a true 
            result_index.pop_back();
            s1.pop_back();
        }

        return (incl_path || excl_path);
}
/*
 * Complete the equalSubSetSumPartition function below.
 *
 * @param s : input array as parameter.
 */

vector<bool> equalSubSetSumPartition(vector<int> &s)
{
    vector<bool> result(s.size(),false);
    vector<int> result_index;
    vector<int> s1;
    bool isPartitionPossible;
    int fullsum=0;
    int halfsum=0;
    fullsum=accumulate(s.begin(), s.end(), 0);
    // if sum is odd , equal partition is not possible
    if(( fullsum %2) == 1){
        return {};
    }
    halfsum=fullsum/2;

    isPartitionPossible = helper(s1,s,0,halfsum,result_index);
    cout << "isPartitionPossible : " << isPartitionPossible << endl;
    if(!isPartitionPossible){
        cout << "partition not possible" << endl;
        return {};
    }
    cout << "result_index : " ;
    for(auto const& i : result_index) {
        cout << i << " " ;
        result[i]=true;
    }        
    cout << endl;        
    cout << "result : " ;
    for(auto const& i : result) {
        cout << i << " " ;
    }
    cout << endl;        
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

