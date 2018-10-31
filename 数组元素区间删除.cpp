#include <stdio.h>

#define MAXN 20

int Delete( int A[], int L, int minA, int maxA );

int main()
{
    int A[MAXN], L, minA, maxA, i;

    scanf("%d", &L);
    for (i=0; i<L; i++) scanf("%d", &A[i]);
    scanf("%d %d", &minA, &maxA);
    L = Delete(A, L, minA, maxA);
    for (i=0; i<L; i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}

int Delete(int A[],int L,int minA,int maxA){
    int B[20];
    int t=0;
    for(int i=0;i<L;i++){
        if(A[i]<=minA || A[i]>=maxA){
            B[t] = A[i];
            t++;
        }
    }

    for(int i=0;i<t;i++){
        A[i] = B[i];
    }
    return t;
}

