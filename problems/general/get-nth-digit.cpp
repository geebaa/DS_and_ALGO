#include <bits/stdc++.h>

using namespace std;

int nth_digit(int num,int base,int digit)
{
    int nthdigit;
    int divisor,reduced_num;    
    divisor = pow(base,digit);
    cout << "divisor : " << divisor << endl;
    reduced_num = (num / divisor);
    cout << "reduced num : " << reduced_num << endl;
    nthdigit = reduced_num % 10;
    return nthdigit;
}

int main()
{
    int num,base,digit;
    int digitn;
    cout << "Input number,base,digit : " <<endl; 
    cin >> num >> base >> digit;

    cout << "number : " << num << "base : " << base << " digit : " << digit << endl;
    digitn=nth_digit(num,base,digit);
    cout << "required digit : " << digitn << endl;
}


