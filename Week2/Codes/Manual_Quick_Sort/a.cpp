#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int n , m;
int a[MAXN];

void QuickSort(int l , int r){
    if(l >= r) return;

    int pivot = a[r];

    int j = l;
    for(int i = l ; i < r ; i++){
        if(a[i] > pivot) continue;
        swap(a[i] , a[j]);
        j++;
    }
    swap(a[r] , a[j]);
    
    QuickSort(l , j - 1);
    QuickSort(j + 1 , r);
}

int main(int argc, char *argv[]){
    freopen("dummy.inp" , "r" , stdin);
    freopen("dummy.out" , "w" , stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];

    clock_t start , end;

    start = clock();
    
    // Sorting - Algorithm starts here
    QuickSort(1 , n);
    
    end = clock();

    fstream out;
    out.open("Time_measured.txt" , fstream::app);

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    out << "Heap sort took : " << fixed << time_taken << setprecision(5);
    out << " sec on test " << atoi(argv[1]) << endl;

    for(int i = 1 ; i <= n ; i++)
        cout << a[i] << " ";
    
    return 0;
}