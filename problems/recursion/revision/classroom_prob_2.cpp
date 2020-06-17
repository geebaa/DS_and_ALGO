#include<bits/stdc++.h>
using namespace std;

vector<string> num_to_alpha_list;

vector<string> keypad;
void print_list(vector<string> &num_to_alpha_list)
{
    for(auto elem:num_to_alpha_list){
        cout << elem << endl;
    }
}
void num_to_alpha_helper(string &phone_number,int i,string &result)
{
    //base case 
    if(i == phone_number.size()){
        num_to_alpha_list.push_back(result);
        return;
    }

    // recursive case
    int index=stoi(phone_number.substr(i,1));
    string s=keypad[index];
    for(auto letter:s){
        result.push_back(letter);
        num_to_alpha_helper(phone_number,i+1,result);
        result.pop_back();
    }
}

void num_to_alpha(string &phone_number)
{
    string result;
    num_to_alpha_helper(phone_number,0,result);
}

int main()
{
    keypad={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string phone_number;
    cout << " enter phone number : " ;
    cin >> phone_number;
    num_to_alpha(phone_number);
    print_list(num_to_alpha_list);
}

