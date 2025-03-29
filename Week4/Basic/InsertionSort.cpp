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

void print(){
    for(int i = 1 ; i <= n ; i++)
        cout << a[i] << " ";
    cout << endl;
}

void solve(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];

    for(int i = 2 ; i <= n ; i++){
        int value = a[i];
        int j = i - 1;
        while(j > 0 && a[j] > value){
            a[j + 1] = a[j];
            print();
            j--;
        }

        a[j + 1] = value;
        print();
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