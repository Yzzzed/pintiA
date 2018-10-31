#include <stdio.h>
#include<string.h>
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    while(N){
        char x[50];
        int t=0;
        scanf("%s",x);
        for(int i=0;i<strlen(x);i++){
            if(x[i]=='S'){
                t++;
            }
			else{
                t--;
            }
            if(t<0 || t>M){
                break;
            }
        }
        if(t==0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        N--;
    }
     return 0;
}
