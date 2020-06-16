#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pattern_matcher' function below.
 *
 * The function accepts STRING text and pattern as parameter and returns BOOLEAN.
 */

// utility for computing hash of a pair for memoization
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

// note hash_pair implements the hash for a pair
unordered_map<pair<int, int>, bool, hash_pair> memo;

bool pattern_matcher_helper(string &text,int ts,string &pattern,int ps)
{
    //base case - if both pattern and text has completed
    if( (ts == text.size()) && (ps == pattern.size()) ){
        return true;
    }
    if(ps == pattern.size()){
        // pattern is over but text is still unfinished
        return false;
    }
    if(ts == text.size()){
        // text is over but pattern still exists
        // check if this pattern ends like "a*b*.*.*"
        while(ps+1 <  pattern.size()){
            if(pattern[ps+1] != '*'){
                return false;
            }
            ps = ps+2;
        }
        if(ps < pattern.size()){
            //if still characters pending in pattern
            // test case : text is NULL and pattern is "."
            return false;
        }
        return true;
    }

    // recursive case
    // check if result is available

    pair<int,int> elem=make_pair(ts,ps);
    if(memo.find(elem)!= memo.end()){
        return memo[elem];
    }
    //at the toplevel our decision at ps and ts has a branch if the (ps+1)th
    // character is a "*" . This means we can match 0 or more occurances of
    // ps-th character. 
    // to match 0 occurance of ps-th character , we recursively call with ts and ps+2
    // ps+2 is to skip the pattern till '*' inclusive
    // to match 1 occurance of ps-th character , we recursively call with ts+1 and ps
    // here we have a case where ps can be a "."  and that needs a conditional call
    // if '.' simply call without care for the condition (text[ts] == pattern[ps]) else
    // this condition has to hold. 
    bool result;
    if(ps+1<pattern.size()){
        if(pattern[ps+1] == '*'){
            if(pattern[ps] == '.'){
                result = pattern_matcher_helper(text,ts,pattern,ps+2);
                result = result || pattern_matcher_helper(text,ts+1,pattern,ps);
            }else{
                result = pattern_matcher_helper(text,ts,pattern,ps+2);
                result = result || ((text[ts] == pattern[ps]) && 
                                   pattern_matcher_helper(text,ts+1,pattern,ps));
            }
        }else{
            if(pattern[ps] == '.'){
                result = pattern_matcher_helper(text,ts+1,pattern,ps+1);
            }else{
                result = (text[ts] == pattern[ps]) && 
                         pattern_matcher_helper(text,ts+1,pattern,ps+1);
            }
        }
    }else{
            if(pattern[ps] == '.'){
                result = pattern_matcher_helper(text,ts+1,pattern,ps+1);
            }else{
                result = (text[ts] == pattern[ps]) && 
                         pattern_matcher_helper(text,ts+1,pattern,ps+1);
            }
    }
    // save the result in memo
    memo[elem]=result;
    return result;

}

bool pattern_matcher(string text, string pattern) {
    bool result;
    int n = text.size();
    int m = pattern.size();
    result = pattern_matcher_helper(text,0,pattern,0);

    return result;
}


int main() {
	ostream &fout = cout;
	
	string text, pattern;
	getline(cin, text);
	getline(cin, pattern);

	bool result = pattern_matcher(text, pattern);
	
	fout << result << "\n";

	return 0;
}

