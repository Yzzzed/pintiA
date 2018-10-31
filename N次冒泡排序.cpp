#include <stdio.h>

void bindSort(int *arr,int n,int k){
    while(k){
          for(int i=0;i<n-1;i++){
            int temp;
            if(arr[i]>arr[i+1]){
              temp = arr[i];
              arr[i] = arr[i+1];
              arr[i+1] = temp;
            }
          }
      k--;
      n--;
    }
}

int main(){
  int N,K;
  int arr[100];
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&arr[i]);
  }

  bindSort(arr,N,K);

  printf("%d",arr[0]);
  for(int i=1;i<N;i++){
   printf(" %d",arr[i]);
  }
}
