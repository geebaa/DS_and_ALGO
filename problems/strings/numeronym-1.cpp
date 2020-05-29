#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the neuronyms function below.
 */
vector<string> neuronyms(string word) {
    /*
     * Write your code here.
     */
    int n=word.length();
    vector<string> result;

    for(int i=1;i<=n-2;i++){
        for(int j = (n-1)-i;j>1;j--){
            string numeronym = word.substr(0,i);
            numeronym.append(to_string(j));
            numeronym.append(word.substr(i+j));
            //cout << " numeronym : " << numeronym << endl;
            result.push_back(numeronym);
        }
    }
    return result;

}


int main()
{
    ostream &fout = cout;

    string word;
    getline(cin, word);

    vector<string> res = neuronyms(word);

    for (int res_itr = 0; res_itr < res.size(); res_itr++) {
        fout << res[res_itr];

        if (res_itr != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    

    return 0;
}

