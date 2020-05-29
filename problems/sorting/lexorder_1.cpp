#include <bits/stdc++.h>

using namespace std;

class Entry_t {
    public :
        string key;
        string maxstr;
        int count;
        Entry_t(){
            cout << "c1" <<endl;
            count=0;
            maxstr="";
            key="";
        };
        Entry_t(int n,string k,string str):count(n),key(k),maxstr(str) {
            cout << "c3" <<endl;
        }
        friend ostream& operator<<(ostream& os, const Entry_t& e){
            os << e.key << ':' << e.count << ',' << e.maxstr;
            return os;
        }
}; 

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

/*
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}
*/
/*
 * Complete the solve function below.
 */
vector<string> solve(vector<string> arr) {
    /*
     * Write your code here.
     */
    vector < string > res;
    ostringstream os;
    unordered_map<string , Entry_t > res_map; 
    unordered_map<string , Entry_t>::iterator it;
    for(int i=0;i<arr.size();i++)
    {
        string curr = arr[i];
        vector<string> words;
        split(curr,' ',words);
        string key=words[0];

        it=res_map.find(key);
        if(it == res_map.end()){
            //new key
            //cout << "new entry" << endl;
            Entry_t new_res(1,key,words[1]);
            cout << "new entry to map " << &(new_res) << endl;
            res_map[key] = new_res;
            //cout << "return after" << endl;
            //map<string , Entry_t>::iterator it_chk=res_map.find(key);
            //cout << "it_chk->second" << &(it_chk->second) <<endl;
            //cout << it_chk->second << endl;
        } else {
            // existing key update result 
            Entry_t *curr_res;
            curr_res = &(it->second);
            curr_res->count++;
            if(curr_res->maxstr < words[1]) {
                curr_res->maxstr.assign(words[1]);
                //cout << curr_res->maxstr;
            }
        }

    }
    unordered_map<string , Entry_t>::iterator res_itr;
    for(res_itr=res_map.begin(); res_itr!=res_map.end(); res_itr++)
    {
        os<<res_itr->second;
        //cout << os.str()<<endl;
        res.push_back(os.str());
        os.str("");
    }

    return res;
}
int main()
{
    ostream &fout = cout;

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        string arr_item;
        getline(cin, arr_item);

        arr[arr_itr] = arr_item;
    }

    vector<string> res = solve(arr);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    

    return 0;
}

