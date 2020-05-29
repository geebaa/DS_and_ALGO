#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int n){
    stack <int> digit_stack;
    queue < int> digit_queue;
    int orig_n=n;
    while(n){
        int digit;
        digit=n%10;
        digit_stack.push(digit);
        digit_queue.push(digit);
        n=n/10;
    }
    while(!digit_stack.empty()){
        int top_digit,first_digit;
        top_digit=digit_stack.top();
        first_digit=digit_queue.front();
        digit_stack.pop();
        digit_queue.pop();
        if(top_digit != first_digit){
            return false;
        }
    }
    //cout << orig_n << " is a palindrome" << endl;
    return true;

}
/*
 * Complete the function below.
 */
long long int next_palindrome(int n) {
    long long int result;
    string n_str,l_str,r_str;
    int num_len;

    if(isPalindrome(n)){
        //single digit number , 9
        if(n<9){
            result = n+1;
            return result;
        }
        // find the next palindrome of n++
        n++;
    }
    n_str = to_string(n);
    //cout << "n_str : " << n_str << endl;
    num_len=n_str.length();
    int mid=num_len/2;
    int r_str_start = mid;
    if(num_len&1){
        r_str_start++;
    }
    
    int half_len=num_len/2;
    l_str=n_str.substr(0,half_len);
    r_str=n_str.substr(r_str_start,half_len);

    //cout << "l_str : " << l_str << endl;
    //cout << "r_str : " << r_str << endl;

    string rev_l_str=l_str;
    string rev_r_str=r_str;
    string result_n_str;
    reverse(rev_l_str.begin(),rev_l_str.end());
    reverse(rev_r_str.begin(),rev_r_str.end());

    //cout << "rev_l_str : " << rev_l_str << endl;
    //cout << "rev_r_str : " << rev_r_str << endl;
    if(l_str < r_str){
        //cout << "l_str < r_str" << endl;
        l_str = to_string(stol(l_str)+1);
        string rev_l_str=l_str;
        reverse(rev_l_str.begin(),rev_l_str.end());

        result_n_str += l_str;
        if(num_len&1){
            result_n_str += n_str[mid];
        }
        result_n_str += rev_l_str;
    }else if(l_str > r_str){
        //cout << "l_str > r_str" << endl;
        //l_str = to_string(stol(l_str)+1);
        string rev_l_str=l_str;
        reverse(rev_l_str.begin(),rev_l_str.end());

        result_n_str += l_str;
        if(num_len&1){
            result_n_str += n_str[mid];
        }
        result_n_str += rev_l_str;

    }else {
        // if not of even length
        if(num_len&1){
            // just change the mid but 
            // what if mid == 9 ?
            if(n_str[mid] != '9'){
                result_n_str += l_str;
                result_n_str += to_string((n_str[mid]-'0')+1);;
                result_n_str += r_str;
            }else{
                l_str = to_string(stol(l_str)+1);
                string rev_l_str=l_str;
                reverse(rev_l_str.begin(),rev_l_str.end());

                result_n_str += l_str;
                result_n_str += to_string(0);
                result_n_str += rev_l_str;
            }
        }else{
            string rev_l_str=l_str;
            reverse(rev_l_str.begin(),rev_l_str.end());

            result_n_str += l_str;
            result_n_str += rev_l_str;
        }

    }

    //cout << " next palindromic str : " << result_n_str << endl;
    result = stol(result_n_str);
    return result;
}


int main()
{
    ostream &fout = cout;

    long long int res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = next_palindrome(n);
    fout << res;

    
    return 0;
}

