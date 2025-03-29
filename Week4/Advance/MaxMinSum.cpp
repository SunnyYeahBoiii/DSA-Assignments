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

const int MAXN = 1e5 + 5;
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

int fact[MAXN];
int inv[MAXN];

int pow_mod(int a , int b){
    if(b <= 0) return 1;
    if(b == 1) return a;

    int t = pow_mod(a , b / 2);

    if(b % 2 == 0)
        return t * t % MOD;
    return t * t % MOD * a % MOD;
}

const int LIM = 1e5;
void preCompute(){
    fact[0] = 1;
    for(int i = 1 ; i <= LIM ; i++)
        fact[i] = fact[i - 1] * i % MOD;
        
    inv[LIM] = pow_mod(fact[LIM] , MOD - 2);
    for(int i = LIM - 1 ; i >= 0 ; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}

int nCk(int n , int k){
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD; 
}

void solve(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];

    sort(a + 1 , a + 1 + n);
    preCompute();
    int result = 0;

    for(int i = 1 ; i <= n ; i++){
        if(i < k) continue;
        int sum = a[i] * nCk(i - 1 , k - 1);
        // cout << a[i] << " " << sum << " " << nCk(i - 1 , k -1) << endl;
        result = (result + sum) % MOD;
    }
    
    for(int i = n ; i > 0 ; i--){
        if(n - i + 1 < k) continue;
        int sum = a[i] * nCk(n - i , k - 1);
        // cout << a[i] << " " << sum << " " << nCk(n - i , k -1) << endl;
        result = ((result - sum) % MOD + MOD) % MOD;
    }

    cout << result << endl;
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