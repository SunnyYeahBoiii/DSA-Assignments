#include <bits/stdc++.h>
#include "testlib.h" // library for testing

using namespace std;

int Random(int L , int R){ 
    return rnd.next(L , R);
}// returns a random number in range [L , R]

int32_t main(int argc, char *argv[]){
    registerGen(argc, argv, 1);

    freopen("dummy.inp" , "w" , stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n = Random(900 , 1000);
    cout << n << endl;

    vector<int> a;
    for(int i = 1 ; i <= n ; i++)
        a.push_back(Random(1 , 1e9));

    int num_test = atoi(argv[1]);
    if(num_test == 1)
        sort(a.begin() , a.end());
    else if(num_test == 2)
        sort(a.begin() , a.end() , greater<int>());
    
    for(auto x : a)
        cout << x << " ";
    cout << endl;   

    return 0;
}
