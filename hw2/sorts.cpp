//swap
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return;
}

// selectionSort
int findMax(int A[], int n){
    int max = A[0];
    int maxIdx = 0;
    for(int i=1;i<=n;i++){
        if (max < A[i]) 
        {
            max = A[i];
            maxIdx = i;
        }
    }

    return maxIdx;
}

void selectionSort(int A[], int n){
    for(int i=n-1;i>0;i--){
        int maxIdx = findMax(A, i);
        swap(A, maxIdx, i);
    }
    return;
}

//quickSort
int partition(int A[], int p, int r){
    int a=0, temp;
    for (int i=0;i<r;i++){
        if(A[i]<A[r]){
            swap(A,a,i);
            a++;
        }
    }
    swap(A,a,r);
    return a;

}

void quickSort(int A[], int p, int r)
{
    if(p < r){
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
    return;
}

//insertionSort
void insertionSort(int A[], int n){
    int temp, idx;
    for(int i = 1;i < n;i++){
        int temp = A[i];
        int p = i-1;
        while( (p>=0) && (A[p] > temp)){
            A[p+1] = A[p];
            p--;
        }
        A[p+1] = temp;
    }
    return;
}

//bubbleSort
void bubbleSort(int A[], int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(A[i]>A[j])   swap(A,i,j);
        }
    }
    return;
}

//heapSort
void heapify(int A[], int i, int n){
    int max = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && A[l] > A[max])    max = l;
    if(r<n && A[r] > A[max])    max = r;

    if(max != i){
        swap(A, max, i);
        heapify(A, max, n);
    }
    return;
}

void buildHeap(int A[], int n){
    for(int i=n/2 -1; i>=0; i--){
        heapify(A, i, n);
    }
    return;
}   

void heapSort(int A[], int n){
    buildHeap(A, n);
    for(int i = n-1; i>0; i--){
        swap(A, 0, i);
        heapify(A, 0, i);
    }
    return;
}
