#include <bits/stdc++.h>

using namespace std;

// Complete the findMaxPossibleArea function below.
long long int findMaxPossibleArea(vector<long long int> heights, int l, int r) {
    long long int max_area=0;
    int n=heights.size();
    
    //stack has the maxheight at a index on top always
    stack<pair<long long int,long long int>> height_index_stack;
    // map of unique height to contributions from deleted heights to this height
    map<long long int,long long int> accumulated_contribution;
    pair<long long int,long long int> top_height_index;
    for(int i=l;i<=r;i++){
        pair<long long int,long long int> curr_height_index=make_pair(heights[i],i);
        if(!height_index_stack.empty()){
            top_height_index = height_index_stack.top();
            if(top_height_index.first <= curr_height_index.first){
                // non decreasing sequence
                height_index_stack.push(curr_height_index);
            }else{
                // current height is less than top of stack
                // pop stack until 
                // top_height_index.first <= curr_height_index.first
                // compute area and then store max_area
                while(!height_index_stack.empty()){
                    top_height_index = height_index_stack.top();
                    if(top_height_index.first > curr_height_index.first){
                        height_index_stack.pop();
                        long long int curr_height_area=0;
                        curr_height_area = top_height_index.first *((i-1)-top_height_index.second+1)*1ll;
                        if(accumulated_contribution.find(top_height_index.first)  != accumulated_contribution.end()){
                            curr_height_area += accumulated_contribution[top_height_index.first]*1ll;
                            accumulated_contribution.erase(top_height_index.first);
                        }
                        max_area = max(curr_height_area,max_area)*1ll;
                        if(accumulated_contribution.find(curr_height_index.first)  != accumulated_contribution.end()){
                            accumulated_contribution[curr_height_index.first]+=curr_height_index.first*1ll;
                        }else{
                            accumulated_contribution[curr_height_index.first] = curr_height_index.first*1ll;
                        }
                    }else{
                        break;
                    }
                }
                // change the curr_height_index
                // push the curr_height_index on stack
                height_index_stack.push(curr_height_index);
            }

        }else{
            // push the curr_height_index on stack
            height_index_stack.push(curr_height_index);
        }
    }
    // suppose we had only increasing sequence, the stack will not be empty
    // calculate the area for all the heights in the stack
    top_height_index = height_index_stack.top();
    long long int index_at_top=top_height_index.second;
    while(!height_index_stack.empty()){
        top_height_index = height_index_stack.top();
        height_index_stack.pop();
        long long int curr_height_area=0;
        curr_height_area = top_height_index.first * (index_at_top - top_height_index.second + 1)*(1ll);
        if(accumulated_contribution.find(top_height_index.first)  != accumulated_contribution.end()){
            curr_height_area += (accumulated_contribution[top_height_index.first])*(1ll);
            accumulated_contribution.erase(top_height_index.first);
        }
        max_area = max(curr_height_area,max_area)*(1ll);
    }
    return max_area;

}


int main()
{
    ostream &fout = cout;

    int heights_count;
    cin >> heights_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<long long int> heights(heights_count);

    for (int heights_itr = 0; heights_itr < heights_count; heights_itr++) {
        long long int heights_item;
        cin >> heights_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        heights[heights_itr] = heights_item;
    }

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < q; ++i)
    {
        int l;
        cin >> l;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int r;
        cin >> r;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long long int res = findMaxPossibleArea(heights, l, r);

        fout << res << "\n";
    }

    

    return 0;
}


