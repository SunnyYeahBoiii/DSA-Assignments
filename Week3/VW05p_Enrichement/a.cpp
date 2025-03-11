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

int n , m;
vector<int> a[MAXN];

void solve(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        a[i].resize(m + 1 , 0);
        for(int j = 1 ; j <= m ; j++)
            cin >> a[i][j];
    }

    int res = inf;
    for(int i = 1 ; i + 2 <= n ; i++){
        for(int j = 1 ; j + 2 <= m ; j++){
            int sum = 0;
            for(int u = 0 ; u <= 2 ; u++)
                for(int v = 0 ; v <= 2 ; v++)
                    sum += a[i + u][j + v];
            res = min(res , sum);
        }
    }
    cout << res << endl;
}

int32_t main(){
    FileInput();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
