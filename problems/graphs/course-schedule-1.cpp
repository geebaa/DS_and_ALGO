#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

bool dfs(unordered_map<int ,unordered_set<int>> &adj_list,int i,vector<int> &visited,vector<int> &arrival,vector<int> &departure,vector<int> &result,int &curr_time)
{

    arrival[i]=curr_time++;
    visited[i]=1;
    for(auto neighbor:adj_list[i]){
        if(visited[neighbor] == -1){
            // not yet visited
            // explore
            if(dfs(adj_list,neighbor,visited,arrival,departure,result,curr_time) == true){
                // subtree returned true after finding a cycle
                // return same to parent
                return true;
            }
        }else{
            // check backedge - absense of departure time in neighbor indicates backedge
            // presense of backedge in a directed graph indicates cycle
            if(departure[neighbor] == -1){
                return true;
            }
        }
    }
    // insert this course since all dependant courses have finished
    result.push_back(i);
    departure[i]=curr_time++;
    return false;
}

/*
 * Complete the function below.
 */
vector<int> course_schedule(int n, vector<vector<int>> prerequisites) {

    vector<int> result;
    unordered_map<int ,unordered_set<int>> adj_list(n);
    vector<int> visited(n,-1);
    vector<int> arrival(n,-1);
    vector<int> departure(n,-1);
    int curr_time=0;
    bool is_cycle_present=false;
    // build adj_list
    for(auto pre_req:prerequisites){
        int course=pre_req[0];
        int depends_on=pre_req[1];
        adj_list[course].insert(depends_on);

    }
    //
/*
    for(auto adj:adj_list){
        cout << "Course : " << adj.first << " depends on " << endl;
        for(auto elem:adj.second){
            cout << "     " << elem;
        }
        cout << endl;
    }
*/

    for(int i=0;i<n;i++){
        if(visited[i] == -1){
            is_cycle_present=dfs(adj_list,i,visited,arrival,departure,result,curr_time);
            if(is_cycle_present){
                return {-1};
            }
        }
    }
    return result;

}
int main()
{

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string e_temp;
    getline(cin, e_temp);

    int e = stoi(ltrim(rtrim(e_temp)));

    vector<vector<int>> prerequisites(e);

    for (int i = 0; i < e; i++) {
        prerequisites[i].resize(2);

        string prerequisites_row_temp_temp;
        getline(cin, prerequisites_row_temp_temp);

        vector<string> prerequisites_row_temp = split(rtrim(prerequisites_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int prerequisites_row_item = stoi(prerequisites_row_temp[j]);

            prerequisites[i][j] = prerequisites_row_item;
        }
    }
    ostream &fout = cout;
    vector<int> result = course_schedule(n, prerequisites);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }
    
    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


