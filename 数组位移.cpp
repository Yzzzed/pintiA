#include <stdio.h>

void moveOne(int *n,int m){
    int temp;
    temp = n[0];
    for(int i=0;i<m-1;i++){
        n[i] = n[i+1];
    }
    n[m-1] = temp;
}


int main(){
    int n,m;
    int arr[100];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    while(m>0){
        moveOne(arr,n);
        m--;
    }
    printf("%d",arr[0]);
    for(int i=1;i<n;i++){
        printf(" %d",arr[i]);
    }
}
