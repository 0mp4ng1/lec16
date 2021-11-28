#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

void RabinKarp(char* A, char* P, int d, int q){
    
    int n = strlen(A);
    int m = strlen(P);

    int* b = (int*)malloc(sizeof(int)*(n-m));

    int p = 0;
    b[0] = 0;

    for(int i=0;i<m;i++){
        p = (d*p + (P[i] - 97)) % q;
        b[0] = (d*b[0] + (A[i] - 97) ) % q;
    }

    int h = (int)pow(d, m-1) % q;
    

    for(int i=0;i<=n-m;i++){
        if(i){
            b[i] = (d*(b[i-1] - h*(A[i-1]-97)) + (A[i+m-1]-97)) % q;
            if(b[i]<0) b[i] = b[i] + q;
        }
        if(p == b[i]){
            if(!strncmp(P, A + i, m)){
                printf("find at %d\n", i);
                free(b);
                return;
            }
        }
    }
    printf("not found!!\n");
    free(b);
    return;

}


int main(){
    char str[256];
    cout << "Input string" << endl;
    cin >> str;

    char pattern[256];
    cout << "Input pattern" << endl;
    cin >> pattern;

    RabinKarp(str, pattern, 5, 113);

}