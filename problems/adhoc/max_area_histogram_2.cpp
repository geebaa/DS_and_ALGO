#include <bits/stdc++.h>

using namespace std;

// Complete the findMaxPossibleArea function below.
long long int findMaxPossibleArea(vector<long long int> heights, int l, int r) {

    long long int max_area=0;
    
    // non-decreasing height stack of "height to index"
    // has the maxheight on top always
    stack<pair<long long int,long long int>> height_index_stack;
    pair<long long int,long long int> stack_top;
    // for every arriving histogram bar height
    for(int i=l;i<=r;i++){
        pair<long long int,long long int> curr_elem(heights[i],i);
        //cout << "make pair " << endl;
        if(height_index_stack.empty()){
            height_index_stack.push(curr_elem);
        }else{
            // need to find if the current height if pushed onto
            // stack will still have it non-decreasing
            stack_top = height_index_stack.top();
            if(stack_top.first <=  curr_elem.first){
                //cout << "top <= curr...pushing " << endl;
                height_index_stack.push(curr_elem);
            }else{
                do {
                    //start computing max area for every 
                    // popped element from stack
                    height_index_stack.pop();
                    long long int height = stack_top.first;
                    long long int width;
                    width = (i-stack_top.second);
        
                    long long int area  = width*height;
                    max_area = max(max_area,area);
                    curr_elem.second=stack_top.second;
                    if(height_index_stack.empty()){
                        break;
                    }else{
                        stack_top = height_index_stack.top();
                    }
                } while(!(stack_top.first <=  curr_elem.first));
                height_index_stack.push(curr_elem);
            }
        }
    }
    //cout << "height_index_stack : not empty check " << endl;
    // if stack is not empty, compute the area 
    // area of each bar will be stack_top.first*(r-stack_top.second+1)
    while(!height_index_stack.empty()){
        stack_top = height_index_stack.top();
        height_index_stack.pop();
        long long int width ;
        long long int height = stack_top.first;
        width = r - stack_top.second+1;
        long long int area  = width*height;
        max_area = max(max_area,area);
    }
    //cout << " max_area : " << max_area << endl;
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


