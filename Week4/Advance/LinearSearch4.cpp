/*
    Cred : SunnyYeahBoi
    It's my last chance (⌐■_■)
    Problem :
*/

#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define endl "\n"
#define NAME "a"

const int MAXN = 1e6 + 5;
const int inf = 1e18;
const int MOD = 1e9 + 7;

void FileInput(){
    if(fopen(NAME".inp" , "r") == NULL)
        freopen(NAME".inp" , "w" , stdout);
    freopen(NAME".inp" , "r" , stdin);
    freopen(NAME".out" , "w" , stdout);
}

int n , k;
map<int , int> c;

void solve(){
    c.clear();

    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        int x;
        cin >> x;
        c[x]++;
    }

    if(c.size() < k || c.size() > 2 * k){
        cout << "NO" << endl;
        return;
    }

    int cnt = 0;
    for(auto x : c)
        if(x.second > 1) cnt++;

    cout << (cnt >= (2 * k - c.size()) ? "YES" : "NO") << endl;
}

int32_t main(){
    //FileInput();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}