#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<int> getNeighbors(int node,unordered_map<int,int> &board,int end)
{
    vector<int> neighbors;

    //for each die choice
    for(int i=1;i<=6;i++){
        if( (node +i) <= end){
            neighbors.push_back(board[node +i]);
        }
    }
    //cout << " Neighbors of : " << node << endl;
    //for(auto neighbor:neighbors){
    //    cout << " " << neighbor;
    //}
    //cout << endl;
    return neighbors;
}
void bfs(int &start,int &end,unordered_map<int,int> &board,vector<int> &visited,int &min_rolls){

    queue<int> q;
    q.push(start);
    visited[start]=1;
    vector<int> neighbors;
    while(!q.empty()){
        // level processing
        int n=q.size();
        for(int i=0;i<n;i++){
            // for each node in that level
            int node = q.front();
            q.pop();
            if(node == end){
                //reached end of board
                return;
            }
            // throw the die
            neighbors=getNeighbors(node,board,end);
            for(auto neighbor:neighbors){
                if(visited[neighbor] == -1){
                    visited[neighbor]=1;
                    q.push(neighbor);
                }
            }
        }
        // increment min_rolls for the die thrown above
        min_rolls++;
    }
    // if here then could not reach the end
    min_rolls=-1;

}


// Complete the minNumberOfRolls function below.
int minNumberOfRolls(int n, vector<int> moves) {

    int min_rolls=0;
    // start is arguable and subjective. 
    // normally start from 0 and atleast 1 throw of a die
    // is required but if start is set to 0 , many test cases fail
    int start=1; 
    int end = n;
    unordered_map<int,int> board; // store the final position when landing on a cell
    vector<int> visited(n+1,-1);
    for(int i=1;i<=n;i++){
        // board is 1 based and moves is 0 based
        board[i] = (moves[i-1]==-1)?i:moves[i-1]+1;
    }

    bfs(start,end,board,visited,min_rolls);
    return min_rolls;


}

int main()
{
    ostream &fout = cout;

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string moves_count_temp;
    getline(cin, moves_count_temp);

    int moves_count = stoi(ltrim(rtrim(moves_count_temp)));

    vector<int> moves(moves_count);

    for (int i = 0; i < moves_count; i++) {
        string moves_item_temp;
        getline(cin, moves_item_temp);

        int moves_item = stoi(ltrim(rtrim(moves_item_temp)));

        moves[i] = moves_item;
    }

    int res = minNumberOfRolls(n, moves);

    fout << res << "\n";

    

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

