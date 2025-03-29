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

        for (int i = 1; i <= n - 1; ++i) {

            // Assume the current position holds
            // the minimum element
            int min_idx = i;
    
            // Iterate through the unsorted portion
            // to find the actual minimum
            for (int j = i + 1; j <= n; ++j) {
                if (a[j] < a[min_idx]) {
    
                    // Update min_idx if a smaller
                    // element is found
                    min_idx = j; 
                }
            }
    
            // Move minimum element to its
            // correct position
            if(i != min_idx){
                swap(a[i], a[min_idx]);
                print();
            }
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