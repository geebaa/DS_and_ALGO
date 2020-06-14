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
        basic idea is to use left and right pointer to arrive at a substring that
        contains all chracters of "t" . Then shrink the right pointer and use
        sliding window technique to find out the minimum window. Keep the min window
        globally updated.
        pls note that the missing is the size of char_set and not t .
        This is because of duplicates in t
        and also there is a req_char_count that is populated with number of ocurances
        of each unique character in t
    */

    int l=0,r=-1;
    int n=s.size();
    unordered_set<char> char_set(t.begin(),t.end());
    pair<int,int> min_window(0,n-1);//set to max
    unordered_map<char,int> char_count;
    // since t can have duplicate characters we need to make sure we have a req_char_count per unique character
    unordered_map<char,int> req_char_count;
    bool window_found=false;
    int missing = char_set.size();

    for(auto letter:char_set){
        char_count[letter]=0;
        req_char_count[letter]=0;
    }

    for(auto letter:t){
        req_char_count[letter]++;
    }

    for(auto c_count:req_char_count){
        cout << c_count.first << " " << c_count.second<<endl;
    }

    while(r<n){
        if(missing > 0){
            //expand the window
            r++;
            if(char_set.find(s[r]) != char_set.end()){
                //found a interested character
                char_count[s[r]] = char_count[s[r]] + 1;
                if(char_count[s[r]] == req_char_count[s[r]]){
                    //got the required number of characters of s[r]
                    missing--;
                    if(missing == 0){
                        //new window with all characters
                        store_result(min_window,l,r);
                        window_found=true;
                    }
                }
            }
        }else{
            // shrink the window
            l++;
            // check if the character lost is interesting
            if(char_set.find(s[l-1]) != char_set.end()){
                char_count[s[l-1]] = char_count[s[l-1]]-1;
                if(char_count[s[l-1]] == req_char_count[s[l-1]] - 1){
                    //lost a character from the window
                    missing++;
                }else{
                    //new window with all characters
                    store_result(min_window,l,r);
                }
            }else{
                //new window with all characters
                store_result(min_window,l,r);
            }
        }
    }

    cout << " window : " << min_window.first << " " << min_window.second<<endl;
    if(window_found){
        return s.substr(min_window.first,min_window.second-min_window.first+1);
    }else{
        return "-1";
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
