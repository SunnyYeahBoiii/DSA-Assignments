int n , d;
const int MAXN = 1e6 + 5;
int a[MAXN];
int c[MAXN];

double find_median(int d){
    double ans = 0 , cur_cnt = 0;
    for(int i = 0 ; i <= 200 ; i++){
        cur_cnt += c[i];
        // cout << c[i] << endl;
        if(cur_cnt >= (d + 1) / 2){
            ans = i;
            // cout << cur_cnt << " check " << i << endl;
            break;
        }
    }

    if(d % 2 == 1)
        return ans;

    cur_cnt = 0;
    for(int i = 0 ; i <= 200 ; i++){
        cur_cnt += c[i];
        if(cur_cnt >= (d + 1) / 2 + 1){
            ans = (ans + i) / 2.0;
            break;
        }
    }

    return ans;
}

void solve(){
    cin >> n >> d;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];

    int j = 1 , result = 0;
    for(int i = 1 ; i <= n ; i++){
        while(i - j > d){
            c[a[j]]--;
            j++;
        }
        
        if(i > d && find_median(d) * 2 <= a[i]){
            result++;
            // cout << find_median(i - j + 1) << " " << a[i] << endl;
        }
        
        // if(i > d) cout << find_median(d) << " " << a[i] << endl;
        c[a[i]]++;
    }
    cout << result << endl;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}