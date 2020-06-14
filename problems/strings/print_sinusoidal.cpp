#include <bits/stdc++.h>

using namespace std;


void printStringSinusoidally(string s){
    int n=s.size();
    vector<string>sinusoidal(3);
    vector<int> array_index={2,1,0,1};
    
    for(int i=0;i<n;i++){
        int arr_idx=array_index[i%4];
        for(int j=0;j<3;j++){
            if(j==arr_idx){
                if(s[i] == ' '){
                    sinusoidal[j].push_back('~');
                }else{
                    sinusoidal[j].push_back(s[i]);
                }
            }else{
                sinusoidal[j].push_back(' ');
            }
        }
    }
    //cout <<endl;
    //for(auto str:sinusoidal){
    //    cout<<str<<endl;
    //}
}


int main(){
    string s;
    getline(cin,s);
    printStringSinusoidally(s);
    return 0;
}


