#include <stdlib.h>
#include <time.h>

void makeArr(int A[], int n){
    srand((unsigned int)time(NULL));

    for(int i=0; i<n; i++)
    {
         A[i] = rand() % n; //0~n-1까지의 랜덤 숫자
         for (int j=0; j<i; j++){
             if(A[i] == A[j])
                i--;
         }
    }
    return;
}

