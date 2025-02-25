#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("dummy.inp" , "r" , stdin);
    freopen("dummy.out" , "w" , stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for(auto& x : a)
        cin >> x;

    time_t start , end;

    // Sorting - Algorithm starts here
    sort(a.begin() , a.end());
    
    for(auto x : a)
    cout << x << " ";
    
    return 0;
}