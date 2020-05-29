#include <bits/stdc++.h>


using namespace std;


string ltrim(const string &);
string rtrim(const string &);

void swap(int i,int j,vector<char>& balls){
    char tmp=balls[i];
    balls[i] = balls[j];
    balls[j] = tmp;
}

void dutch_flag_sort(vector<char>& balls) {
    
    int n = balls.size();
    int r_here = 0,i = 0,b_here = n-1;
    while(i <= b_here){
        if(balls[i] == 'R'){
            swap(i,r_here,balls);
            r_here++;
            i++;
        }else if(balls[i] == 'B'){
            swap(i,b_here,balls);
            b_here--;
        } else {
            i++;
        }
    }
}

int main()
{
    ostream &fout = cout;
    
    string balls_count_temp;
    getline(cin, balls_count_temp);

    int balls_count = stoi(ltrim(rtrim(balls_count_temp)));

    vector<char> balls(balls_count);

    for (int i = 0; i < balls_count; i++) {
        string balls_item_temp;
        getline(cin, balls_item_temp);

        char balls_item = balls_item_temp[0];

        balls[i] = balls_item;
    }

    dutch_flag_sort(balls);

    for (int i = 0; i < balls.size(); i++) {
        fout << balls[i];

        if (i != balls.size() - 1) {
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
