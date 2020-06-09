#include <bits/stdc++.h>
using namespace std;

void store_result(pair<int,int> &indices,int l, int r)
{
    if((indices.second - indices.first) > (r-l)){
        // new shorter substring indices to store
        indices.first=l;
        indices.second=r;
        //cout << "scs : " << " " << l << " " << r << endl;
    }
    
}

string shortest_controlling_substr(string &s,vector<char> &dict)
{
    /*
        general idea is to start expanding out the substring from right until
        all dictionary letters are consumed and then start shrinking the substring
        from left until one of the dictionary letters miss. At this point we know one 
        of the sort string and store it if applicable in a global location. cotinue this
        process until further expansion of right is not possible
        start out with both l and r pointing to 0th locaiton in s
    */

    unordered_map<char,int> dict_counter;
    unordered_set<char> dict_set(dict.begin(),dict.end());
    int missing_characters=dict.size();
    int l=0,r=0;
    int n=s.size();
    bool found_controlling_substr=false;
    // initialize with the entire string length
    pair<int,int> controlling_substr = make_pair(0,n-1);    

    // initialize all counters for the letters in dictionary to 0
    for(auto letter:dict_set){
        dict_counter[letter]=0;
    }

    while(r<n){
        //cout << " l : " << l << " r : " << r << " miss : " << missing_characters << endl; 
        while( (missing_characters > 0 ) && r<n){
            //expand r
            r++;
            if(!(r<n)){
                break;
            }
            if(dict_set.find(s[r]) != dict_set.end()){
                //found the character in dict , it could be a new find
                if(dict_counter[s[r]] == 0){
                    // new find
                    missing_characters--;
                    dict_counter[s[r]]=1;
                    if(missing_characters == 0){ // transitioned from 1 to 0
                        // l to r is a new controlling substring
                        store_result(controlling_substr,l,r);
                        found_controlling_substr=true;
                    }
                }else{
                    // increment counter
                    dict_counter[s[r]]++;
                }
            }
        }
        //cout << " l : " << l << " r : " << r << " miss : " << missing_characters << endl; 
        while( (missing_characters == 0) && r<n){
            //expand l -- effectively shrink the window l<-->r
            l++;
            // note that l-1 --- > this is because the character excluded by doing a l++
            // is at index l-1
            if(dict_set.find(s[l-1]) != dict_set.end()){
                dict_counter[s[l-1]]--;
                //found the character in dict , it could be a new loss from substring
                if(dict_counter[s[l-1]] == 0){
                    // new loss 
                    missing_characters++;
                    if(missing_characters == 1){ // transitioned from 0 to 1
                        // note l-1 because the addition of l++ caused controlling
                        // substring to lose control
                        store_result(controlling_substr,l-1,r); 
                    }
                }
            }
        }
    }
    if(found_controlling_substr){
        return s.substr(controlling_substr.first,(controlling_substr.second - controlling_substr.first + 1));
    }else{
        return "";
    }

}

int main()
{
    // input string
    string s="hello world";
    // controlling characters
    vector<char> dict={'l','r','w'};

    // need to find the shortest substring of s
    // that has all characters from dict present
    // it is called a "shortest controlling substring"

    cout << " Shortest controlling substring : " << shortest_controlling_substr(s,dict)<<endl;
    return 0;

}
