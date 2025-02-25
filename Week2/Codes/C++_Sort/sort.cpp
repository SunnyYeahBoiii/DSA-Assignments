#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]){
    freopen("dummy.inp" , "r" , stdin);
    freopen("dummy.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for(auto& x : a)
        cin >> x;

    clock_t start , end;

    start = clock();
    
    // Sorting - Algorithm starts here
    sort(a.begin() , a.end());
    
    end = clock();

    fstream out;
    out.open("Time_measured.txt" , fstream::app);

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    out << "C++ sort took : " << fixed << time_taken << setprecision(5);
    out << " sec on test " << atoi(argv[1]) << endl;

    
    for(auto x : a)
    cout << x << " ";
    
    return 0;
}