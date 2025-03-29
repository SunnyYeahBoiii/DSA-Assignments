// Author : MinhPhuongVu A.K.A SunnyYeahBoii

/* 
Code Ideal: I'm too lazy for something like this .__.
*/

#include "bits/stdc++.h"

using namespace std;

#define NAME "a"
#define FileInput() if(NAME != "remizdabest"){freopen(NAME".inp" , "r" , stdin);freopen(NAME".out" , "w" , stdout);}
#define int long long
#define endl "\n"
#define INF 1 << 30

int nexti[1000005];

void solve(){
	string a , b;
	cin >> a;
	cin >> b;

	a = '*' + a;
	b = '&' + b;

	int j = 0;
	nexti[1] = 0;
       	for(int i = 2 ; i < b.size() ; i++){
		while(j > 0 && b[j+1] != b[i])
			j = nexti[j];
		if(b[j+1] == b[i]) j++;
		nexti[i] = j;
	}	

	j = 0;

    vector<int> id;

	for(int i = 1 ; i < a.size() ; i++){
		while(j > 0 && b[j+1] != a[i])
			j = nexti[j];
		
		if(b[j+1] == a[i])
			j++;

		//cout << j << endl;
		if(j+1 == b.size()){
			// cout << i-j+1 << " ";
            id.push_back(i - j + 1);
			j = nexti[j];
		}
	}
	/*
	for(int i = 1 ; i < b.size() ; i++)
		cout << nexti[i] << " ";
	*/

    cout << (id.size() > 0 ? "YES" : "NO") << endl;
    for(auto x : id)
        cout << x << " ";
	cout << endl;
}

int32_t main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        //FileInput();
        solve();
        return 0;
}