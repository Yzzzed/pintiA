#include <stdio.h>

void mult(int x1,int x2,int *arr1,int *arr2,int *arr3,int *k){
    for(int i=0;i<2*x1;i+=2){
        for(int j=0;j<2*x2;j+=2){
            arr3[*k] = arr1[i] * arr2[j];
            (*k)++;
            arr3[*k] = arr1[i+1] + arr2[j+1];
            (*k)++;
        }
    }

    for(int a=0;a<2*x1*x2-2;a=a+2){  //合并同类项
    	if(arr3[a]!=0){
            for(int b=a+2;b<2*x1*x2;b=b+2){
                if(arr3[b]!=0&&arr3[a+1]==arr3[b+1]){
                    arr3[a]=arr3[a]+arr3[b];
                    arr3[b]=0;
                    arr3[b+1]=0;
                }
            }
		}
	}

    for(int a=0;a<2*x1*x2-2;a=a+2){//排序
    	for(int b=a+2;b<2*x1*x2;b=b+2){
    		if(arr3[a+1]<arr3[b+1]){
    			int xi=arr3[a];     //系数交换
    			arr3[a]=arr3[b];
    			arr3[b]=xi;
    			int zhi=arr3[a+1];  //指数交换
    			arr3[a+1]=arr3[b+1];
    			arr3[b+1]=zhi;
			}
		}

	}

}

void add(int x1,int x2,int *arr1,int *arr2,int *arr4,int *l){
    for(int i=1;i<2*x1;i+=2){
        for(int j=1;j<2*x2;j+=2){
            if(arr1[i] == arr2[j] && arr1[i]!=0 && arr2[j]!=0){
                arr4[*l] = arr1[i-1] + arr2[j-1];
                (*l)++;
                arr4[*l] = arr1[i];
                (*l)++;
                break;
            }
        }
    }
    int r=0;
    for(int i=1;i<2*x1;i+=2){
        for(int j=1;j<2*x2;j+=2){
            if(arr1[i] == arr2[j]){
                r=1;
                break;
            }
        }
        if(r==0){
            arr4[*l] = arr1[i-1];
            (*l)++;
            arr4[*l] = arr1[i];
            (*l)++;
        }
        r=0;
    }
    int t=0;
    for(int i=1;i<2*x2;i+=2){
        for(int j=1;j<2*x1;j+=2){
            if(arr2[i] == arr1[j]){
                t=1;
                break;
            }
        }
        if(t==0){
            arr4[*l] = arr2[i-1];
            (*l)++;
            arr4[*l] = arr2[i];
            (*l)++;
        }
        t=0;
    }

    for(int a=0;a<2*(x1+x2)-2;a=a+2){  //合并同类项
    	if(arr4[a]!=0){
            for(int b=a+2;b<2*(x1+x2);b=b+2){
                if(arr4[b]!=0&&arr4[a+1]==arr4[b+1]){
                    arr4[a]=arr4[a]+arr4[b];
                    arr4[b]=0;
                    arr4[b+1]=0;
                }
            }
		}
	}

    for(int a=0;a<2*(x1+x2)-2;a=a+2){//排序
    	for(int b=a+2;b<2*(x1+x2);b=b+2){
    		if(arr4[a+1]<arr4[b+1]){
    			int xi=arr4[a];     //系数交换
    			arr4[a]=arr4[b];
    			arr4[b]=xi;
    			int zhi=arr4[a+1];  //指数交换
    			arr4[a+1]=arr4[b+1];
    			arr4[b+1]=zhi;
			}
		}

	}
}

int main(){
    int x1,x2,k=0,l=0;
    scanf("%d",&x1);
    int arr1[1000];
    for(int i=0;i<2*x1;i++){
        scanf("%d",&arr1[i]);
    }
    scanf("%d",&x2);
    int arr2[1000];
    for(int i=0;i<2*x2;i++){
        scanf("%d",&arr2[i]);
    }
    int arr3[2000];
    mult(x1,x2,arr1,arr2,arr3,&k);

    int arr4[2000];
    add(x1,x2,arr1,arr2,arr4,&l);

    if(arr3[0]!=0){
        printf("%d %d",arr3[0],arr3[1]);
        for(int i=2;i<(x1*x2*2)&&arr3[i]!=0;i=i+2){
            printf(" %d %d",arr3[i],arr3[i+1]);
        }
    }else{
        printf("0 0");
    }
    printf("\n");

    if(arr4[0]!=0){
        printf("%d %d",arr4[0],arr4[1]);
        for(int i=2;i<(x1*x2*2)&&arr4[i]!=0;i=i+2){
            printf(" %d %d",arr4[i],arr4[i+1]);
        }
    }else{
        printf("0 0");
    }
}
