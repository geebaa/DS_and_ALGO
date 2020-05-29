#include <bits/stdc++.h>

using namespace std;


void helper(string &s, long long int &target,int i,long long int &sum,vector<string> &result_vector, string &result_str)
{
    if( (target == sum) && (s.length() == i) )
    {
        //  completed traversing array and achieved target
        // remove trailing '+' '*'
        string new_result_str = result_str.substr(0,result_str.length()-1);
        cout << "Expr : " << new_result_str << endl;
        result_vector.push_back(new_result_str);
        //result_str.erase();
        return;
    }
    if(sum > target)
    {
        //  failed to achieve exact target
        return;
    }

    for(int j = i;j<s.length();j++)
    {
        cout << "String : " << s.substr(i,(j-i) + 1) << endl;
        long long int num = stoull(s.substr(j,(j-i) + 1));
        long long int new_sum;
        int before_append_len = result_str.length();
        result_str.append(s.substr(j,(j-i) + 1));
        int append_len = result_str.length() - before_append_len;

        result_str.push_back('+');
        new_sum=sum + num;
        helper(s,target,i+1,new_sum,result_vector,result_str);
        result_str.pop_back();

        result_str.push_back('*');
        new_sum=sum * num;
        helper(s,target,i+1,new_sum,result_vector,result_str);
        result_str.pop_back();

        for(int k=0;k<append_len;k++)
        {
            result_str.pop_back();
        }

    }
}
 
/*
 * Complete the function below.
 */
vector <string> generate_all_expressions(string s, long long int target) {
    vector <string> result_vector;
    string result_str;
    long long int sum=0;
    helper(s, target,0,sum,result_vector,result_str);
    return result_vector;
}

int main()
{
    ostream &fout = cout;

    vector <string> res;
    string s;
    getline(cin, s);

    long long int target;
    cin >> target;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = generate_all_expressions(s, target);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}


