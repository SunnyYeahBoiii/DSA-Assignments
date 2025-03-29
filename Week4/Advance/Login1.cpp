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

int n , q;
map<string , string> dt;

void solve(){
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++){
        string username , password;
        cin >> username >> password;
        dt[username] = password;
    }

    while(q--){
        string username;
        cin >> username;
        if(dt.find(username) != dt.end())
            cout << dt[username] << endl;
        else cout << "Chua Dang Ky!" << endl;
    }
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