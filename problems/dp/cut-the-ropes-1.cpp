#include <bits/stdc++.h>

using namespace std;

long long int max_product_from_cut_pieces(int n) {

    long long int result;
    vector<long long int> dptable(n+1,0);

    // base case since this is a product initialize dptable[0] to 1
    dptable[0]=1;

    // dptable[i] represents the max product for rope of length i
    long long int prod_max=0;

    // ignore the constraint to cut the rope atleast once and
    // compute the best product for each length
    for(int i = 1;i<=n;i++){
        if(i == n){
            prod_max=i-1;
        }else{
            prod_max=i;
        }
        for(int cut=1;cut<i;cut++){
            prod_max=max(prod_max,1LL*cut*dptable[i-cut]);
        }
        dptable[i]=prod_max;
        cout << " i : " << i << " = " << dptable[i] << endl;
    }

    return dptable[n];
}

long long int max_product_from_cut_pieces_1(int n) {

    long long int result;
    vector<long long int> dptable(n+1,0);

    // base case since this is a product initialize dptable[0] to 1
    dptable[0]=1;

    // dptable[i] represents the max product for rope of length i
    long long int prod_max=0;

    // ignore the constraint to cut the rope atleast once and
    // compute the best product for each length
    for(int i = 1;i<=n;i++){
        prod_max=i;
        for(int cut=1;cut<=i;cut++){
            prod_max=max(prod_max,1LL*cut*dptable[i-cut]);
        }
        dptable[i]=prod_max;
        //cout << " i : " << i << " = " << dptable[i] << endl;
    }

    // since the rope has to be cut atleast once , 
    // ignore dptable[n] and find the max just for the length n
    result=0;
    for(int cut = 1;cut<n;cut++){
        result = max(result,1LL*cut*dptable[n-cut]);
    }

    return result;
}


int main()
{
    ostream &fout = cout;

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long long int res = max_product_from_cut_pieces(n);

    fout << res << "\n";

    

    return 0;
}


