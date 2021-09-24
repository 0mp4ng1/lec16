#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define test_cnt 1

void allocate(int ***arr){
    *arr = (int **)malloc(SIZE * sizeof(int *));
    for(int i=0; i<SIZE; i++)
    {
        (*arr)[i] = (int *)malloc( SIZE * sizeof(int) );
        for(int j=0; j<SIZE; j++) (*arr)[i][j] = 1;
    }
}

void deallocate(int ***arr){
    for(int i=0; i<SIZE; i++) free(*arr[i]);
    free(*arr);
}

int main()
{
   int **c;

// 유동 할당하기
   allocate(&c);

// 결과 출력하기
   for(int i=0; i<SIZE; i++)
   {
        for(int j=0; j<SIZE; ++j) printf("%d ", c[i][j]);
        printf("\n");
   }

// 할당 해제하기
   deallocate(&c);

}
