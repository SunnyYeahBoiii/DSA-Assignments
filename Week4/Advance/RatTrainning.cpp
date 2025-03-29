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
 int MOD = 1e9 + 7;

void FileInput(){
    if(fopen(NAME".inp" , "r") == NULL)
        freopen(NAME".inp" , "w" , stdout);
    freopen(NAME".inp" , "r" , stdin);
    freopen(NAME".out" , "w" , stdout);
}

// x1 + ... + xn = n
// xi >= 0

// n K n = 2n - 1 C (n - 1)

int n , p;

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

    inv[MOD - 1] = pow_mod(fact[MOD - 1] , MOD - 2);
    for(int i = MOD - 2 ; i >= 0 ; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
}

int nCk(int n , int k){
    if(k > n)
        return 0;
    // cout << fact[n] << " " << inv[k] << " " << inv[n - k] << endl;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD; 
}

void solve(){
    cin >> n;
    int K = n - 1 , N = 2*n - 1;
    // cout << N << " " << K << endl;

    int result = 1;
    while(N > 0){
        int tn = N % MOD;
        int tk = K % MOD;

        N /= MOD;
        K /= MOD;

        // cout << tn << " " << tk << " " << nCk(tn , tk) << endl;

        result = result * nCk(tn , tk) % MOD;
    }

    cout << result << endl;
}

int32_t main(){
    //FileInput();
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t >> MOD;
    preCompute();
    while(t--)
        solve();
    return 0;
}