#include <stdio.h>

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return;
}

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


int main(){
    int A[10] = {31, 8 , 48, 73, 11, 3, 20, 29, 65, 15};
    quickSort(A, 0, 9);
    for(int i=0;i<10;i++)
        printf("%d ",A[i]);
    printf("\n");
}