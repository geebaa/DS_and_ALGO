#include <bits/stdc++.h>

using namespace std;

vector<int> min_stack(vector<int> operations) {

    stack<pair<int,int>> min_stack;
    vector<int> result;
    for(auto i : operations){
        switch(i){
            case 0  :
                if(min_stack.empty()){
                    result.push_back(-1);
                }else{
                    result.push_back(min_stack.top().second);
                }
                break;
            case -1 :
                if(!min_stack.empty()){
                    min_stack.pop();
                }
                break;
            default :
                // min so far is on the top of stack
                // if current element is less than that
                // push a new min with value
                if(min_stack.empty()){
                    min_stack.push(make_pair(i,i));
                }else{
                    min_stack.push(make_pair(i,min(i,min_stack.top().second)));
                }
        }
    }    
    return result; 
}


int main()
{
    ostream &fout = cout;

    int operations_size;
    cin >> operations_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> operations(operations_size);
    for (int operations_i = 0; operations_i < operations_size; operations_i++) {
        int operations_item;
        cin >> operations_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        operations[operations_i] = operations_item;
    }

    vector<int> res = min_stack(operations);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";
    
    
    return 0;
}

