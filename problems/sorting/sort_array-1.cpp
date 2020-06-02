#include <bits/stdc++.h>


using namespace std;


string ltrim(const string &);
string rtrim(const string &);

void swap(vector<char> &arr,int i,int j)
{
    char tmp=arr[j];
    arr[j]=arr[i];
    arr[i]=tmp;
    
}
void select_sort(vector<char> &arr)
{
    int n=arr.size();

    for(int i=0;i<n;i++){
        //char min=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                swap(arr,i,j);
            }
        }
    }
}
void bubble_sort(vector<char> &arr)
{
    // wont pass ik full test 15 - 19
    int n=arr.size();

    for(int i=0;i<n;i++){
        //char min=arr[i];
        for(int j=n-1;j>i;j--){
            if(arr[j] < arr[j-1]){
                swap(arr,j,j-1);
            }
        }
    }
}
void insertion_sort(vector<char> &arr,int n)
{
    // wont pass ik full test 15 - 19
    // base case
    if(n<=0){
        return;
    }
    insertion_sort(arr,n-1);

    // insert nth element at proper location
    while(n>0 && (arr[n] < arr[n-1]) ){
        //swap nth and (n-1)st elements
        swap(arr,n,n-1);
        n=n-1;
    }
    return;
}

void insertion_sort_efficient(vector<char> &arr,int n)
{
    // base case
    if(n<=0){
        return;
    }
    insertion_sort_efficient(arr,n-1);
    char min=arr[n];
    // insert nth element at proper location
    while(n>0 && (min < arr[n-1]) ){
        arr[n]=arr[n-1];
        n=n-1;
    }
    arr[n]=min;
    return;
}

int partition(vector<char> &arr,int s,int e)
{
    // choose pivot element - it could be arr[s] or
    // any arr[i] where i is any random index between s and e
    char pivot;
    int pivot_index=s;

    // swap element at pivot_index with element at index s
    swap(arr,pivot_index,s);

    // get the pivot element
    pivot = arr[s];

    // index of the last element <= pivot and
    // index of last element > pivot
    int small_index,large_index;
    small_index=s;
    large_index=s;

    // traverse the array from s+1 to e
    for(large_index=s+1;large_index<=e;large_index++){
        if(pivot > arr[large_index]){
            // small element found by large_index
            // exchange with next element of small_index
            small_index++;
            swap(arr,small_index,large_index);
        }
    }
    // now exchange the first element with the small_index
    swap(arr,small_index,s);
    // now we have an array where the pivot element is at index
    // small_index and elements at indices s to small_index-1 are
    // less than pivot and elements at indices small_index+1 to e
    // are greater than pivot
    return small_index;
}

void quick_sort(vector<char> &arr,int s,int e)
{
    int pivot;
    // base case
    if(s>=e){
        return;
    }
    pivot=partition(arr,s,e);
    quick_sort(arr,s,pivot-1);
    quick_sort(arr,pivot+1,e);

}

vector<char> merge(vector<char> &l , vector<char> &r){
    vector <char> result;
    int i=0;
    int j=0;
    int k=0;
    int lsize=l.size();
    int rsize=r.size();
    while( (i<lsize) && (j<rsize) ){
        if(l[i] <= r[j]){
            result.push_back(l[i]);
            i++;
        } else {
            result.push_back(r[j]);
            j++;
        }
    }

    while(i<lsize){
        result.push_back(l[i]);
        i++;
    }
    while(j<rsize){
        result.push_back(r[j]);
        j++;
    }
    return result;
}

vector<char> merge_sort_helper(vector<char> &arr , int start , int end)
{
    vector<char> l;
    vector<char> r;
    vector<char> result;
    if(end <= start) {
        result.push_back(arr[start]);
        return result;
    }

    int mid = start + ((end - start)/2);
    l=merge_sort_helper(arr,start,mid);
    r=merge_sort_helper(arr,mid+1,end);
    result=merge(l,r);
    return result;

}

/*
 * Complete the 'merge_sort' function below.
 *
 * The function accepts an integer array as parameter.
 */

void merge_sort(vector<char> &arr) {

    vector<char> result;
    result = merge_sort_helper(arr,0,arr.size()-1);
    //copy result into arr

    int i=0;
    for(auto elem:result){
        arr[i]=elem;
        i++;
    }
}

vector<char> sort_array(vector<char> arr) {

    vector<char> result;
    //select_sort(arr);
    //bubble_sort(arr);
    //insertion_sort(arr,arr.size()-1);
    //insertion_sort_efficient(arr,arr.size()-1);
    //quick_sort(arr,0,arr.size()-1);
    merge_sort(arr);
    return arr;
    //return result;

}

int main()
{
    ostream &fout = cout;

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int str_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<char> arr(str_count);

    for (int i = 0; i < str_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        char arr_item = arr_item_temp[0];

        arr[i] = arr_item;
    }

    vector<char> result = sort_array(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";


    return 0;
}


string ltrim(const string &arr) {
    string s(arr);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &arr) {
    string s(arr);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


