void merge(int a[] , int n , int b[] , int m , int c[]){
    int j = 0 , k = 0;
        for(int i = 0 ; i < n ; i++){
            while(j < m && b[j] <= a[i]){
                c[k++]= b[j];
                j++;
            }
            c[k++] = a[i];
        }
    while(j < m){
        c[k++] = b[j];
        j++;
    }
}