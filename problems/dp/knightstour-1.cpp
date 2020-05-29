#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
vector < vector <int> > adjlist { {4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{6,2},{1,3},{2,4}};
int num_neighbors[10]={2,2,2,2,3,0,3,2,2,2};
long long int numPhoneNumbers(int startdigit, int phonenumberlength) {
    long long int result;
    vector < vector <long long int> > dptable;
    
    // initialize DP table for base cases 
    // dptable will return 0 if phonenumberlength is 0 for any startdigit
    // dptable will return 1 if phonenumberlength is 1 for any startdigit
    // 
    for(int row=0;row<=10;row++) {
        vector<long long int> temp;
        for(int col=0;col<2;col++){
            temp.push_back(col);
        }
        dptable.push_back(temp);
    }
    
    vector < vector <long long int> >::iterator dptable_itr;
    dptable_itr = dptable.begin(); 
    // compute other cells of DPtable
    for(int col=2;col<=phonenumberlength;col++) {
        for(int row=0;row<10;row++){
            vector <long long int> curr_row = dptable.at(row);
            dptable_itr[row].push_back(0);// add the new cell to the grid
            // below loop is a summation of all 
            // phone numbers of length col - 1 from all neighbors
            for(int neighbor=0;neighbor<adjlist[row].size();neighbor++) {
                vector <long long int> neigh_row = dptable.at(adjlist[row][neighbor]);
                dptable_itr[row][col]=dptable_itr[row][col]+neigh_row[col - 1];
            }
            //cout << "row : " << row << "col : " << col << "val : " << dptable_itr[row][col] << endl;
        }
    }
    result = dptable[startdigit][phonenumberlength];
    return result;

}

int main()
{
    ostream &fout = cout;

    long long int res;
    int startdigit;
    cin >> startdigit;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int phonenumberlength;
    cin >> phonenumberlength;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = numPhoneNumbers(startdigit, phonenumberlength);
    fout << res;

    
    return 0;
}

