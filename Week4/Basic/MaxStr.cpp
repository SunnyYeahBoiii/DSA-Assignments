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

string s;

void solve(){
    cin >> s;

    sort(s.begin() , s.end() , greater<char>());

    int sum = 0;
    for(auto x : s)
        sum += (x - '0');

    // cout << sum % 3 << endl;

    if(sum % 3 == 1){
        int id = -1;
        for(int i = 0 ; i < s.size() ; i++){
            int digit = s[i] - '0';
            if(digit % 3 == 1)
                id = i;
        }

        if(id != -1){
            s[id] = '*';
            for(auto x : s)
                if(x != '*') cout << x;
            cout << endl;
            return;
        }

        int id2 = -1;
        for(int i = 0 ; i < s.size() ; i++){
            int digit = s[i] - '0';
            if(digit % 3 == 2){
                id2 = id;
                id = i;
            }
        }

        s[id] = '*';
        s[id2] = '*';
        for(auto x : s)
            if(x != '*') cout << x;
        cout << endl;
    }else if(sum % 3 == 2){
        int id = -1;
        for(int i = 0 ; i < s.size() ; i++){
            int digit = s[i] - '0';
            if(digit % 3 == 2)
                id = i;
        }

        if(id != -1){
            s[id] = '*';
            for(auto x : s)
                if(x != '*') cout << x;
            cout << endl;
            return;
        }

        int id2 = -1;
        for(int i = 0 ; i < s.size() ; i++){
            int digit = s[i] - '0';
            if(digit % 3 == 1){
                id2 = id;
                id = i;
            }
        }

        s[id] = '*';
        s[id2] = '*';
        for(auto x : s)
            if(x != '*') cout << x;
        cout << endl;
    }else cout << s << endl;
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