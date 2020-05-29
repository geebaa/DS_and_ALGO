#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool happy_helper(int n, unordered_set<int> &memo){
        if(n==1){
            memo.insert(1);
            return true;
        }
        unordered_set<int> :: iterator itr;
        itr=memo.find(n);
        if(itr == memo.end()){
            cout << "First time : " << n << endl;
            memo.insert(n); 
        }else{
            cout << "Second time : " << n << endl;
            return false;
        }

        int sum=0;
        int curr_digit_sqr=0;
        int curr_digit;
        while(n){
            curr_digit = n%10;
            curr_digit_sqr = curr_digit*curr_digit;
            sum=sum + curr_digit_sqr;
            n=n/10;
            //cout << "n : " << n << " sum : "<< sum << " curr_digit : " << curr_digit << " curr_digit_sqr : " << curr_digit_sqr << endl;
        }
        //cout << "sum : " << sum << endl;
        return happy_helper(sum,memo);
    };

    bool isHappy(int n) {
        unordered_set<int> memo;
        return happy_helper(n,memo);
    };
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        bool ret = Solution().isHappy(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
