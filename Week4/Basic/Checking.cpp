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

struct Point{
    int x, y, z;

    bool operator < (Point a){
        if(a.x == x && a.y == y)
            return z < a.z;
        else if(a.x == x)
            return y > a.y;
        else return x < a.x;
    }
};

int n , k;
string a[MAXN];

void m(int L1 , int R1 , int L2 , int R2){
    vector<string> c;
    int j = L2;
    for(int i = L1 ; i <= R1 ; i++){
        while(j <= R2 && a[j] < a[i]){
            c.push_back(a[j]);
            j++;
        }
        c.push_back(a[i]);
    }
    while(j <= R2){
        c.push_back(a[j]);
        j++;
    }

    j = 0;
    for(int i = L1 ; i <= R2 ; i++)
        a[i] = c[j++];
}

void mSort(int L , int R){
    if(L >= R)
        return;

    int mid = (L + R) / 2;

    mSort(L , mid);
    mSort(mid + 1 , R);

    m(L , mid , mid + 1 , R);
}

void solve(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    mSort(1 , n);

    int diff = 0;
    for(int i = 1 ; i <= n ; i++)
        if(a[i] != a[i - 1])
            diff++;
    cout << diff << endl;
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