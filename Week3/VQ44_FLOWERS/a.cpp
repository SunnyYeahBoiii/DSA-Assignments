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
int a[MAXN];
map<int , int> cnt;

void solve(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
        
    if(cnt.size() >= k){
        for(auto x : cnt){
            if(k > 0)cout << x.first << " ";
            k--;
        }
    }else{
        for(auto& x : cnt){
            cout << x.first << " ";
            x.second--;
            k--;
        }

        for(auto x : cnt){
            while(x.second > 0 && k > 0){
                k--;
                x.second--;
                cout << x.first << " ";
            }
        }
    }
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
