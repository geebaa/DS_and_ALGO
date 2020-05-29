#include <bits/stdc++.h>

using namespace std;

class Compare {

    public :

        bool operator()(int &n1,int &n2){
            return n1 > n2;
        }
 
};

/*
 * Complete the function below.
 */
vector <int> topK(vector <int> arr, int k) {

    vector< int >  result;
    unordered_set<int> unique_result;
    priority_queue<int , vector < int > , Compare> min_pq;

    for(auto i : arr){
        if(unique_result.find(i) == unique_result.end()){
            unique_result.insert(i);
            min_pq.push(i);
            if(min_pq.size() > k){
                int elem_to_del;
                elem_to_del = min_pq.top();
                min_pq.pop();
                unique_result.erase(elem_to_del);
            }
        }
    }

/*
    //unique_result(min_pq.begin(),min_pq.end());
    while(min_pq.size()){
        //result.push_back(min_pq.top());
        unique_result.insert(min_pq.top());
        //cout << min_pq.top();
        min_pq.pop();
    }
*/

    result.assign(unique_result.begin(),unique_result.end());
    return result;
}

int main()
{
    ostream &fout = cout;

    vector <int> res;
    int arr_size = 0;
    cin >> arr_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> arr;
    for(int i = 0; i < arr_size; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        arr.push_back(arr_item);
    }

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = topK(arr, k);
    for(int res_i = 0; res_i < res.size(); res_i++) {
    	fout << res[res_i] << endl;;
    }

    
    return 0;
}

