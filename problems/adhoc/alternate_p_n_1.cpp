#include <bits/stdc++.h>

using namespace std;

int shift_arr(vector<int> &array,int s_i,int e_i,int shift_count,bool isRight){
    int tmp=array[e_i];
    while(e_i>s_i){
        array[e_i] = array[e_i-1];
        e_i--;
    }
    return tmp;
}

/*
 * Complete the function below.
 */
vector<int> alternating_positives_and_negatives(vector<int> array) {
    vector <int> result;
    int ptr;
    int n=array.size();
    //set the pointers
    ptr=0;
    bool next_is_p=true;
    while(ptr < n){
        //cout << " ptr : " << ptr << endl;
        if(next_is_p){
            if(array[ptr]<0){
                // find the first +ve number between ptr+1 and n
                // right shift array from ptr by 1
                // copy the +ve number at ptr
                int find_ptr=ptr+1;
                while(find_ptr < n){
                    if(array[find_ptr] >=0){
                        //found +ve number
                        break;
                    }else{
                        find_ptr++;
                    }
                }
                if(!(find_ptr < n)){
                    //job done
                    break;
                }else{
                    int tmp = shift_arr(array,ptr,find_ptr,1,true);
                    array[ptr]=tmp;
                }  
            }
        }else{
            if(array[ptr]>=0){
                // find the first -ve number between ptr+1 and n
                // right shift array from ptr by 1
                // copy the -ve number at ptr  
                int find_ptr=ptr+1;
                while(find_ptr < n){
                    if(array[find_ptr] <0){
                        //found -ve number
                        break;
                    }else{
                        find_ptr++;
                    }
                }
                if(!(find_ptr < n)){
                    //job done
                    break;
                }else{
                    int tmp = shift_arr(array,ptr,find_ptr,1,true);
                    array[ptr]=tmp;
                }  
            }
        } 
        ptr++;
        next_is_p = !next_is_p;
    }


    return array;

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


