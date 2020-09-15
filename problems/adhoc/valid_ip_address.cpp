#include<bits/stdc++.h>
using namespace std;

/*
 *    returns true if num[s:e] is less than equal to 255
 *    else false
 *
 */
bool is_valid_octet(string &num,int s,int e){
    //cout << "octet : "<<num.substr(s,e-s+1);
    if(atoi(num.substr(s,e-s+1).c_str()) <=255){
        //cout <<"returning true"<<endl;
        return true;
    }
    cout <<"returning false"<<endl;
    return false;
}
/*
 *     num         -- string of decimal numbers
 *     s           -- start index of the current octet
 *     e           -- end index of the current octet
 *     num_rem     -- num of octects remaining to form an ip address
 */
bool is_ip(string &num,int s,int e,int num_rem)
{
    //base case
    if( (num_rem == 0) && s == num.size() ){
            return true;
    }
    // corner cases

    if(num_rem==0){
        // found all octets of the ip address but still
        // pending elements in the string 'num'
        return false;
    }
    if(e>= num.size()){
        // still octets are to be found
        // but exceeded the index in 'num'
        return false;
    }

    //recursive case
    if(is_valid_octet(num,s,e)){
        if(is_ip(num,e+1,e+1,num_rem-1)){
            return true;
        }else{
            if(is_ip(num,s,e+1,num_rem)){
                return true;
            }
        }
    }

    // tried to find and failed
    return false;
}
int main()
{
    string num="99999999";
    bool result;
    // start to find 4 octets of a ip address
    // start index = 0 , end index = 0
    // for the current octet

    result = is_ip(num,0,0,4);

    cout << " result : " << result<<endl;
}

