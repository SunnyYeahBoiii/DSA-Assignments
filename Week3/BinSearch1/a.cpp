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

    int cnt = 0 , res = 0;
    int L = 1 , R = n;
    while(L <= R){
        int mid = (L + R) / 2;
        if(a[mid] == x){
            res = mid;
            cnt++;
            break;
        }else if(a[mid] > x){
            cnt++;
            R = mid - 1;
        }else{
            cnt++;
            L = mid + 1;
        }
    }

    cout << res - 1 << endl;
    if(res != 0) cout << cnt << endl;
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
