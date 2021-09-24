#include <stdio.h>

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

int main(){
    int A[5] = {29, 10, 14, 37, 13};
    insertionSort(A, 5);

    for (int i=0;i<5;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}