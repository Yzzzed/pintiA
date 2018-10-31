#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(){
int n;
scanf("%d",&n);List a=(List)malloc(sizeof(struct Node));
List head=a;
while(n--){
    scanf("%d",&a->Data);
    if(n){a->Next=(List)malloc(sizeof(struct Node));
    a=a->Next;
    }
}a->Next=NULL;
return head;
}
void Print( List L ){
    while(L){
        printf("%d ",L->Data);
        L=L->Next;
    }
    printf("\n");
}

/* 你的代码将被嵌在这里 */
List Reverse(List L){
  List cur = L;
  List n;
  while(cur != NULL){
    List temp = cur->Next;
    cur->Next = n;
    n = cur;
    cur = temp;
  }
  return n;
}





int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}
