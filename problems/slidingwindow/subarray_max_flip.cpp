#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> all_result;
vector<int> result;
int max_length;
int max_length_s;
int max_length_e;
void subarray_max_flips(vector<int> &arr,int &flips)
{
    int s=0,e=0;
    int flips_consumed=(arr[s]==0)?1:0;
    max_length=1;
    max_length_s=s;
    max_length_e=e;

    while(e < arr.size()){
        // keep expanding till flips_consumed crosses flips
        if(flips_consumed <= flips){
            e++;
            flips_consumed += (arr[e] == 0)?1:0;
            if(flips_consumed <= flips){
                // update max_length
                max_length++;
                max_length_s=s;
                max_length_e=e;
            }
        }else{
            //shrink
            s++;
            flips_consumed -= (arr[s-1] == 0)?1:0;
        }
    }
}

int main()
{
    vector<int> arr = {0,1,0,1,0,0,1,1};
    int flips=2;
    subarray_max_flips(arr,flips); 

    cout << " max length : " << max_length << " max_length_s : " << max_length_s << " max_length_e : " << max_length_e << endl;   
}

