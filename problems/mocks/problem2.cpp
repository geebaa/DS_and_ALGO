#include <bits/stdc++.h>
using namespace std;

/*
    below code this is used for testing the binary search 
    algo
*/
int loweset_index(vector<int> arr,int i){
    // naive approach is to scan array from left to right
    // O(T) = n
    int index=0;
    for(auto num:arr){
        if(num==i){
            return index;
        }
        index++;
    }
    return -1;
}

int loweset_index_binary_scan(vector<int> arr,int i){
    // another approach is to scan the array  
    // using binary search since it is sorted
    // o(T) = log(n)
    int n=arr.size();
    int s=0,e=n-1;
    int m=s + (e-s)/2;
    while(s<=e){
        m=s + (e-s)/2;
        //cout<< "s : " <<s<<" e: "<< e <<" m : " << m<<endl;
        if(arr[m] > i){
            //search in s to m-1
            e=m-1;
        }else if(arr[m] < i){
            //search in m+1 , e
            s=m+1;
        }else{
            // continue searching left most if arr[m-1] = i
            
            if(m-1 >= 0){
                if(arr[m-1] == i){
                    e=m-1;
                }else{
                    // m is at the left most index in arr for value i
                    break;
                }
            }else{
                break;
            }
        }
    }
    if(arr[m] == i){
        return m;
    }
    return -1;
}


int main(){
    vector<int> arr={0,1,1,1,4,4,6,7};
    int val=7;
    int index1=loweset_index(arr,val);
    int index2=loweset_index_binary_scan(arr,val);
    if(index1 != index2){
        cout << "index returned : "<<index2<<" should be : " <<index1<<endl;
    }else{
        cout << "index : " << index2<<endl;
    }
    return 0;
}


