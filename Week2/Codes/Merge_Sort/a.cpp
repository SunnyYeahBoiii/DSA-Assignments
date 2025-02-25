#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int n , m;
int a[MAXN];

void Merge(int L1 , int R1 , int L2 , int R2){
    vector<int> C;
 
    // A = [L1 , R1]
    // B = [L2 , R2]
    
    int j = L2;
    for(int i = L1 ; i <= R1 ; i++){
        while(j <= R2 && a[j] <= a[i]){
            C.push_back(a[j]);
            j++;
        }
        C.push_back(a[i]);
    }
    while(j <= R2){
        C.push_back(a[j]);
        j++;
    }
 
    j = 0;
    for(int i = L1 ; i <= R2 ; i++){
        a[i] = C[j];
        j++;
    }
}
 
void MergeSort(int L , int R){
    if(R - L + 1 <= 1)
        return;
 
    int mid = (L + R) / 2;
 
    // [L , mid]
    MergeSort(L , mid);
    // [mid + 1 , R]
    MergeSort(mid + 1 , R);
 
    Merge(L , mid , mid + 1 , R);
}

int main(int argc, char *argv[]){
    freopen("dummy.inp" , "r" , stdin);
    freopen("dummy.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];

    time_t start , end;

    time(&start);
    
    // Sorting - Algorithm starts here
    MergeSort(1 , n);
    
    end = clock();

    fstream out;
    out.open("Time_measured.txt" , fstream::app);

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    out << "Merge sort took : " << fixed << time_taken << setprecision(5);
    out << " sec on test " << atoi(argv[1]) << endl;

    for(int i = 1 ; i <= n ; i++)
        cout << a[i] << " ";
    
    return 0;
}