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
    int x; cin >> x;

    int pos = 0;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == x){
            pos = i;
            break;
        }
    }

    cout << pos - 1;

    if(pos == 0)
        return;

    cout << endl << pos << endl;

    pos = 0;
    for(int i = n ; i > 0 ; i--){
        if(a[i] == x){
            pos = i;
            break;
        }
    }
    cout << n - pos << endl << (n - pos + 1) << endl;
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
