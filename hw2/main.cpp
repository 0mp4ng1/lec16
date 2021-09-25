#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"
#include "makeArr.h"

#define SIZE 1000

float CheckTime_selectionSort(int A[], int n){
    clock_t start, end;
    float time;

    start = clock();
    selectionSort(A, n);
    end = clock();
    time = (float)(end - start) / CLOCKS_PER_SEC;
    printf("[selection Sort : %fs]\n", time);
    return time;
}

float CheckTime_bubbleSort(int A[], int n){
    clock_t start, end;
    float time;

    start = clock();
    bubbleSort(A, n);
    end = clock();
    time = (float)(end - start) / CLOCKS_PER_SEC;
    printf("[bubble Sort : %fs]\n", time);
    return time;
}

float CheckTime_quickSort(int A[], int n){
    clock_t start, end;
    float time;

    start = clock();
    quickSort(A, 0, n-1);
    end = clock();
    time = (float)(end - start) / CLOCKS_PER_SEC;
    printf("[quick Sort : %fs]\n", time);
    return time;
}

float CheckTime_heapSort(int A[], int n){
    clock_t start, end;
    float time;

    start = clock();
    heapSort(A, n);
    end = clock();
    time = (float)(end - start) / CLOCKS_PER_SEC;
    printf("[heap Sort : %fs]\n", time);
    return time;
}

void rankSort(float s, float b, float q, float h){
    printf("\n---------------------[RANK]---------------------\n");
    float a[4];
    a[0] = s; a[1] = b; a[2] = q; a[3] = h;

    for(int i=0;i<4;i++){
        for(int j=i;j<4;j++){
            if(a[i]>a[j]){
                float t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    for(int i=0;i<4;i++){
        if(a[i] == s)
            printf("%d.%18s%fs\n",i+1,"selection Sort : ", s);
        if(a[i] == b)
            printf("%d.%18s%fs\n",i+1,"bubble Sort : ", b);
        if(a[i] == q)
            printf("%d.%18s%fs\n",i+1,"quick Sort : ", q);
        if(a[i] == h)
            printf("%d.%18s%fs\n",i+1,"heap Sort : ", h);
    }
    printf("\n");
    return;
}


int main(){
    float s = 0, b = 0, q = 0, h =0;
    printf("DATA SIZE : %d\n",SIZE);
    for(int i=0;i<5;i++){

        printf("\n---------------------[ROUND %d]---------------------\n",i+1);

        int A[SIZE], B[SIZE], C[SIZE], D[SIZE];
        makeArr(A, SIZE);
        memcpy(B, A, sizeof(A));
        memcpy(C, A, sizeof(A));
        memcpy(D, A, sizeof(A));

        s += CheckTime_selectionSort(A, SIZE);
        b += CheckTime_bubbleSort(B, SIZE);
        q += CheckTime_quickSort(C, SIZE);
        h += CheckTime_heapSort(D, SIZE);
    }

    printf("\n---------------------[AVERAGE]---------------------\n");
    printf("[selection Sort : %fs]\n", s/5);
    printf("[bubble Sort : %fs]\n", b/5);
    printf("[quick Sort : %fs]\n", q/5);
    printf("[heap Sort : %fs]\n", h/5);

    rankSort(s/5, b/5, q/5, h/5);

    return 0;
}