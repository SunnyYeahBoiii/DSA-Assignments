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

struct Node{
    int data;
    Node* l;
    Node* r;

    Node(int _data = 0){
        data = _data;
        l = nullptr;
        r = nullptr;
    }
};

int n , q;
Node* a[MAXN];

void solve(){
    cin >> n >> q;

    for(int i = 1 ; i <= n ; i++)
        a[i] = new Node(i);

    for(int i = 1 ; i <= n ; i++){
        a[i] -> r = a[(i == 1 ? n : i - 1)];
        a[i] -> l = a[(i == n ? 1 : i + 1)];
    }

    while(q--){
        int x , y;
        cin >> x >> y;
        
        a[x] -> r -> l = a[x] -> l;
        a[x] -> l -> r = a[x] -> r;
        
        a[x] -> r = a[y];
        a[x] -> l = a[y] -> l;
        a[y] -> l -> r = a[x];
        a[y] -> l = a[x];
    }
    
    Node* t = a[1];
    int cnt = 0;
    while(cnt == 0){
        cout << (t -> data) << " ";
        t = t -> l;
        if(t -> data == 1)
            cnt++;
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