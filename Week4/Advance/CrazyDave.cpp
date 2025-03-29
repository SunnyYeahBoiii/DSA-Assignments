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
pair<int , int> b[MAXN];

vector<int> G[MAXN];
bool vis[MAXN];

int DFS(int u){

    vis[u] = true;

    for(auto v : G[u]){
        if(vis[v]) continue;
        return DFS(v) + 1;
    }

    return 1;
}

void solve(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i] , b[i] = {a[i] , i};

    sort(b + 1 , b + 1 + n);

    for(int i = 1 ; i <= n ; i++)
        G[i].push_back(b[i].second);

    int result = 0;
    for(int i = 1 ; i <= n ; i++){
        if(vis[i]) continue;
        result += DFS(i) - 1;
    }

    // cout << result << endl;

    sort(b + 1 , b + 1 + n , greater<pair<int , int>>());

    for(int i = 1 ; i <= n ; i++)
        G[i].clear() , vis[i] = false;

    for(int i = 1 ; i <= n ; i++){
        G[i].push_back(b[i].second);
        // cout << i << " " << b[i].first << " " << b[i].second << endl;
    }
    int result2 = 0;
    for(int i = 1 ; i <= n ; i++){
        if(vis[i]) continue;
        result2 += DFS(i) - 1;
    }


    cout << min(result , result2) << endl;
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