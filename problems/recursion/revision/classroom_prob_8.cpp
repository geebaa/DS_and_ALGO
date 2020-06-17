#include<bits/stdc++.h>
using namespace std;

vector<string> all_paranthesis;

void print_all(vector<string> &all_paranthesis)
{
    cout <<endl;
    for(auto elem:all_paranthesis){
        cout << elem<<endl;
    }
}

void compute_all_valid_paranthesis(int &n,int o,int c,string &curr_paranthesis)
{
    /*
        general idea is to start building paranthesis by choosing '(' or ')'
        to be appended to the current string
    */
    //base case
    if(o == n){
        // we have used all open paranthesis 
        // append all remaining closed paranthesis
        int c_added=0;
        while(c<n){
            curr_paranthesis.push_back(')');
            c++;
            c_added++;
        }
        all_paranthesis.push_back(curr_paranthesis);
        // remove all the pushedback paranthesis
        while(c_added>0){
            curr_paranthesis.pop_back();
            c_added--;
        }
        return;
    }

    //recursive case
    if(c<o){
        // if number of closed paranthesis consumed so far is less than 
        // number of open paranthesis consumed , we have two choice 
        // append ')' or '('
        curr_paranthesis.push_back(')');
        compute_all_valid_paranthesis(n,o,c+1,curr_paranthesis);
        curr_paranthesis.pop_back();
        curr_paranthesis.push_back('(');
        compute_all_valid_paranthesis(n,o+1,c,curr_paranthesis);
        curr_paranthesis.pop_back();
    }else{
        // c can only be equal to o .
        // in this case we have only choice 
        // append '('
        curr_paranthesis.push_back('(');
        compute_all_valid_paranthesis(n,o+1,c,curr_paranthesis);
        curr_paranthesis.pop_back();
    }
    return; 
}

int main()
{
    int n;
    string curr_paranthesis;
    cout << " enter num paranthesis : ";
    cin >> n;
    compute_all_valid_paranthesis(n,0,0,curr_paranthesis);
    print_all(all_paranthesis);
}

