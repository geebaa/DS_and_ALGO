#include <bits/stdc++.h>

using namespace std;

class Compare {
        private:
            bool max=true;
        public :
                Compare(bool cmptype){
                    max = cmptype;
                }
                bool operator () (pair<int,int> const & n1 , pair<int,int> const & n2)
                {
                        if(max){
                            return n1.first < n2.first;
                        } else {
                            return n1.first > n2.first;
                        }
                }

};

/*
 * Complete the mergeArrays function below.
 */
vector<int> mergeArrays(vector< vector <int> > arr) {
    /*
     * Write your code here.
     */
    bool at_least_one_q_non_empty=true;
    vector<int> result;
    int k=arr.size();
    bool cmptype=true;
    int n = arr[0].size();
    for(int i=0;i<k;i++){
        if(arr[i][0] > arr[i][n-1] ){
            cmptype = true;
            break;
        }else if(arr[i][0] < arr[i][n-1]){
            cmptype = false;
            break;
        }
    }
    Compare cmp(cmptype);
    priority_queue< pair<int,int>, vector< pair<int,int> >, Compare> pq_max(cmp);

    for(int i=0;i<k;i++){
        pq_max.push(make_pair(arr[i][0],i));
        arr[i].erase(arr[i].begin());
    }
    while(!pq_max.empty()){
        pair <int,int> top_elem = pq_max.top();
        pq_max.pop();
        result.push_back(top_elem.first);
        if(!arr[top_elem.second].empty()) {
            pq_max.push(make_pair(arr[top_elem.second][0],top_elem.second));
            arr[top_elem.second].erase(arr[top_elem.second].begin());
        }
    }


    return result;
}


int main()
{
    ostream &fout = cout;

    int arr_rows;
    cin >> arr_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int arr_columns;
    cin >> arr_columns;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector< vector< int > > arr(arr_rows);
    for (int arr_row_itr = 0; arr_row_itr < arr_rows; arr_row_itr++) {
        //arr[arr_row_itr].resize(arr_columns);
        arr[arr_row_itr] = vector<int>(arr_columns);
        for (int arr_column_itr = 0; arr_column_itr < arr_columns; arr_column_itr++) {
            cin >> arr[arr_row_itr][arr_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> res = mergeArrays(arr);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
    return 0;
}

