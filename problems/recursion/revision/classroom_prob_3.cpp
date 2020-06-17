#include<bits/stdc++.h>
using namespace std;


vector<string> subsets;

void print_all_subsets(vector<string> &subsets)
{
    for(auto elem:subsets){
        cout << elem<<endl;
    }
    cout << "num elem : " << subsets.size()<<endl;
}

void generate_all_subsets_helper(string &str,string &result,int i)
{
    //base case 
    if(i==str.length()){
        subsets.push_back(result);
        return;
    }

    //recursive case
    // exclude path
    generate_all_subsets_helper(str,result,i+1);
    // include path
    result.push_back(str[i]);
    generate_all_subsets_helper(str,result,i+1);
    result.pop_back();
}    

void generate_all_subsets(string &str)
{
    string result;
    generate_all_subsets_helper(str,result,0);    
}

int main()
{
    string str;
    cout << " enter string : "; 
    cin >> str;
    
    generate_all_subsets(str);

    print_all_subsets(subsets);
}

