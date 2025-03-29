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

int n , k , p , q;

void solve(){
    cin >> n >> k >> p >> q;

    int Alice = 2 * (p - 1) + q;

    int c1 = Alice - k;
    int c2 = Alice + k;

    if(c1 <= 0 && c2 > n)
        cout << -1 << endl;
    else if(c1 > 0){
        cout << (c1 - 1) / 2 + 1 << " " << (c1 % 2 ? 1 : 2) << endl;
    }else cout << (c2 - 1) / 2 + 1 << " " << (c2 % 2 ? 1 : 2) << endl;
}

int32_t main(){
    //FileInput();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}