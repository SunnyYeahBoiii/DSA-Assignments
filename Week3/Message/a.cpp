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
string sb , se;

bool check(int L1 , int R1 , int L2 , int R2){
    int i = L1 , j = L2;
    while(i <= R1 && j <= R2){
        // cout << L1 << " " << R1 << " " << L2 << " " << R2 << " " << sb[i] << " " << se[j] << endl;
        if(sb[i] != se[j])
            return false;
        i++;
        j++;
    }
    return true;
}

void solve(){
    cin >> sb >> se;

    int res = -1 , n = (int)sb.size() - 1;
    for(int i = (int)sb.size() - 1 ; i >= 0 ; i--){
        // cout << i << " " << (int)sb.size() - 1 << " " << 0 << " " << n - i << endl;
        if(check(i , (int)sb.size() - 1 , 0 , n - i))
            res = i;
    }

    // cout << res << endl;

    if(res == -1){
        cout << sb.size() + se.size() << endl;
        cout << sb << se << endl;
        return;
    }

    cout << sb.size() + (int)se.size() - (n - res + 1) << endl;
    cout << sb;
    for(int i = n - res + 1 ; i < se.size() ; i++)
        cout << se[i];
    
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
