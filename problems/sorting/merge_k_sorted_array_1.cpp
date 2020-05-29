#include <bits/stdc++.h>

using namespace std;

class Node {
    public :
        int value;
        int row;
        int col;
   Node(int v, int r,int c)
      : value(v), row(r),col(c)
   {
   }
};

class MaxHeapCompare {
        public :
                bool operator() (Node const & n1 , Node const & n2)
                {
                        return n1.value < n2.value;
                }

};
class MinHeapCompare {
        public :
                bool operator() (Node const & n1 , Node const & n2)
                {
                        return n1.value > n2.value;
                }

};

/*
 * Complete the mergeArrays function below.
 */
vector<int> mergeArrays(vector< vector <int> > arr) {
    /*
     * Write your code here.
     */
    int rows=arr.size(); 
    int cols=arr[0].size(); 
    vector< int > result;
    bool ascending=false; /*assume all raows are non increasing*/
    /*Ascending or descending sort*/
    for(int i=0;i<rows;i++)
    {
        /*if any row is increasing then all rows are increasing*/
        if(arr[i].front() < arr[i].back())
        {
            ascending=true;
            break;
        }
    }
    priority_queue<Node, vector<Node>, MaxHeapCompare> pq_max;
    priority_queue<Node, vector<Node>, MinHeapCompare> pq_min;

    /*Initial heap of all first elements*/
    for(int i=0;i<rows;i++)
    {
        if(arr[i].empty()) continue;
        if(ascending ){
            pq_min.push(Node(arr[i][0],i,0));
        } else {
            pq_max.push(Node(arr[i][0],i,0));
        }
        arr[i].erase(arr[i].begin());// delete the first node of arr[i]
    }
        
    result.reserve(rows*cols);
    int k=0; // index to result array
    bool some_q_is_non_empty = false;
    do {
        int row_popped=0;
        some_q_is_non_empty = false;
        if(ascending ){
            result.emplace_back(pq_min.top().value);
            k++;
            row_popped=pq_min.top().row;
            pq_min.pop();
        } else {
            result.emplace_back(pq_max.top().value);
            k++;
            row_popped=pq_max.top().row;
            pq_max.pop();
        }
        // take the next element from front of array if array is non empty
        if(!arr[row_popped].empty()) {
            if(ascending ){
                pq_min.push(Node(arr[row_popped][0],row_popped,0));
            } else {
                pq_max.push(Node(arr[row_popped][0],row_popped,0));
            }
            arr[row_popped].erase(arr[row_popped].begin());// delete the first node of arr[row_popped]
            some_q_is_non_empty=true;
        }
        else {
            for(int i=0;i<rows;i++)
            {
                if(arr[i].empty()) continue;
                if(ascending ){
                    pq_min.push(Node(arr[i][0],i,0));
                } else {
                    pq_max.push(Node(arr[i][0],i,0));
                }
                arr[i].erase(arr[i].begin());// delete the first node of arr[i]
                some_q_is_non_empty=true;
                break;
            }
        }
    }while(some_q_is_non_empty);
    /*All arrays are empty and some elements remaining in the priority queue*/
    if(ascending) {
        while(!pq_min.empty())
        {
            result.emplace_back(pq_min.top().value);
            k++;
            pq_min.pop();
        }
    } else {
        while(!pq_max.empty())
        {
            result.emplace_back(pq_max.top().value);
            k++;
            pq_max.pop();
        }
    }
    return result;
    // merge into new array
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

