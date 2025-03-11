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

int n;
int a[MAXN];

void solve(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];

    int id1 = 1;
    int id2 = 1;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] > a[id1])
            id1 = i;
        if(a[i] < a[id2])
            id2 = i;
    }

    int res = a[id1] - a[id2];
    a[id1] = -1;
    a[id2] = -1;

    id1 = -1;
    id2 = -1;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == -1) continue;
        if(id1 == -1 || a[i] > a[id1])
            id1 = i;
        if(id2 == -1 || a[i] < a[id2])
            id2 = i;
    }

    if(id1 != -1)res += a[id1] - a[id2];
    cout << res << endl;
}

int32_t main(){
    FileInput();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
