#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<string> split(const string &);

vector<vector<int> > nearest_neighbours(int p_x, int p_y, int k, vector<vector<int> > &n_points) {
    vector<vector<int>> result;

    //priority_queue<double> pq;
    priority_queue<double, vector<double>,greater<double>> pq;
    map<double,vector<vector<int>>> dist_map;
    for(auto point:n_points){
        double dist;
        long long int hyp_sqr;
        hyp_sqr = pow(point[0] - p_x,2);
        hyp_sqr += pow(point[1] - p_y,2);
        dist = sqrt(hyp_sqr);
        //dist = sqrt((point[0] - p_x)^2 + (point[1] - p_y)^2);
        pq.push(dist);
        dist_map[dist].push_back(point);
        cout << "dist : " << dist << " point : " << point[0] << " , "<< point[1]<<endl;
    }
    for(int i=0;i<k;i++){
        if(!pq.empty()){
            cout << " top : " << i << " " << pq.top() << endl;
            result.push_back(dist_map[pq.top()].back());
            dist_map[pq.top()].pop_back();
            pq.pop();
        }
    }
    cout << " Result : " <<endl;
    return result;
}


int main()
{
    ostream &fout = cout;

    string p_x_temp;
    getline(cin, p_x_temp);

    int p_x = stoi(ltrim(rtrim(p_x_temp)));

    string p_y_temp;
    getline(cin, p_y_temp);

    int p_y = stoi(ltrim(rtrim(p_y_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string n_points_rows_temp;
    getline(cin, n_points_rows_temp);

    int n_points_rows = stoi(ltrim(rtrim(n_points_rows_temp)));

    string n_points_columns_temp;
    getline(cin, n_points_columns_temp);

    int n_points_columns = stoi(ltrim(rtrim(n_points_columns_temp)));

    vector<vector<int> > n_points(n_points_rows);

    for (int i = 0; i < n_points_rows; i++) {
        n_points[i].resize(n_points_columns);

        string n_points_row_temp_temp;
        getline(cin, n_points_row_temp_temp);

        vector<string> n_points_row_temp = split(rtrim(n_points_row_temp_temp));

        for (int j = 0; j < n_points_columns; j++) {
            int n_points_row_item = stoi(n_points_row_temp[j]);

            n_points[i][j] = n_points_row_item;
        }
    }

    vector<vector<int> > result = nearest_neighbours(p_x, p_y, k, n_points);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

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


