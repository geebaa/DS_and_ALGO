#include <bits/stdc++.h>
using namespace std;

/*Test cases*/

//case-1
int a[]={2,5,7,9,12,15};
int b[]={-1,-1,2,3,4,5,-1,6,7,-1,-1,8,9,-1};

//case-2
//int a[]={};
//int b[]={};

//case-3
//int a[]={2,3,4,5};
//int b[]={-1,-1,-1,-1};

//case-4
//int a[]={};
//int b[]={2,3,4,5};

void swap(int i,int j,int *arr){
        int tmp = arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;

}

void print_array(int *arr,int len){
        for(int j=0;j<len;j++){
                cout << arr[j] << " ";
        }
        cout << "\n";
}

int main(){

        // get the blanks in array to the right
        //
        int asize=sizeof(a)/sizeof(*a);
        int bsize=sizeof(b)/sizeof(*b);

        int i=0;
        for(int j=0;j<bsize;j++){
                swap(i,j,b);
                if(b[i] != -1){
                        i++;
                }
        }
        print_array(a,asize);
        cout << "\n";
        print_array(b,bsize);
        cout << "\n";
        //cout << i << "\n";
        // merge sort from the reverse
        // 'i' will point to the first blank if available
        // decrement i to get the index of max number in "b"
        //
        int a_i = asize -1; // index of last element in a
        int b_i = i-1;  // index of last non-blank element in b
        int j = bsize-1;  // index of last element in b

        while(a_i >=0 && b_i >= 0){
                if(a[a_i] > b[b_i]){
                        b[j] = a[a_i];
                        a_i--;
                }else{
                        b[j] = b[b_i];
                        b_i--;
                }
                j--;
        }

        // if there are still pending elements in
        // array 'a' just copy them
        while(a_i >= 0){
            b[j] = a[a_i];
            a_i--;
            j--;
        }
        print_array(b,bsize);

}
