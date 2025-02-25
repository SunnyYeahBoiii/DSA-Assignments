#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int n , m;
int a[MAXN];

void Heapify(int id){
    int L = id * 2;
    int R = id * 2 + 1;

    int largest = id;

    if(L <= m && a[L] > a[largest])
        largest = L;
    if(R <= m && a[R] > a[largest])
        largest = R;
    if(largest != id){
        swap(a[id] , a[largest]);
        Heapify(largest);
    }
}

void HeapSort(){
    m = n;

    for(int i = n ; i > 0 ; i--)
        Heapify(i);
        
    for(int i = 1 ; i <= n ; i++){
        swap(a[1] , a[m]);
        m--;
        Heapify(1);
    }
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
    HeapSort();
    
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