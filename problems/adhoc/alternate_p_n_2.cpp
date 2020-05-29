#include <bits/stdc++.h>

using namespace std;

int get_next_ptr(int ptr,vector<int> &array,bool get_next_positive_ptr,int max_ptr){
    int curr_ptr=ptr+1;
    if(get_next_positive_ptr){
        while(curr_ptr < max_ptr){
            if(array[curr_ptr]>=0){
                return curr_ptr;
            }else{
                curr_ptr++;
            }
        }
    }else {
        while(curr_ptr < max_ptr){
            if(array[curr_ptr]<0){
                return curr_ptr;
            }else{
                curr_ptr++;
            }
        }
    }
    return curr_ptr;
}
/*
 * Complete the function below.
 */
vector<int> alternating_positives_and_negatives(vector<int> array) {
    vector <int> result=array;
    int n=array.size();
    int p_ptr=-1,n_ptr=-1;
    int ptr=0;
    cout << endl;
    while( (p_ptr < n) && (n_ptr < n) ){

        if(ptr&1){
            n_ptr=get_next_ptr(n_ptr,array,false,n);
            cout << " " << n_ptr;
            if(n_ptr < n){
                result[ptr]=array[n_ptr];
            }else{
                break;
            }
        }else{
            p_ptr=get_next_ptr(p_ptr,array,true,n);
            cout << " " << p_ptr;
            if(p_ptr < n){
                result[ptr]=array[p_ptr];
            }else{
                break;
            }
        }
        ptr++;
    }
    //ptr--;
    cout << endl;
    cout << " ptr : " << ptr << " p_ptr : " << p_ptr << " n_ptr : " << n_ptr << endl;
    while(p_ptr < n){
        p_ptr=get_next_ptr(p_ptr,array,true,n);
        if(p_ptr < n){
            result[ptr]=array[p_ptr];
        }
        ptr++;
    }
    while(n_ptr < n){
        n_ptr=get_next_ptr(n_ptr,array,false,n);
        if(n_ptr < n){
            result[ptr]=array[n_ptr];
        }
        ptr++;
    } 
    return result;

}


int main()
{
    ostream &fout = cout;

    int array_size;
    cin >> array_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> array(array_size);
    for (int array_i = 0; array_i < array_size; array_i++) {
        int array_item;
        cin >> array_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        array[array_i] = array_item;
    }

    vector<int> res = alternating_positives_and_negatives(array);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";


    return 0;
}


