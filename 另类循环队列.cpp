#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;  /* �洢Ԫ�ص�����   */
    Position Front;     /* ���е�ͷ��βָ�� */
    int Count;          /* ������Ԫ�ظ���   */
    int MaxSize;        /* �����������     */
};
typedef PtrToQNode Queue;

Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = 0;
    Q->Count = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
/*
bool AddQ( Queue Q, ElementType X );
ElementType DeleteQ( Queue Q );
*/
bool AddQ( Queue Q, ElementType X ){
    if(Q->Count==Q->MaxSize){
        printf("Queue Full\n");
        return false;
    }

    Q->Data[(Q->Count+Q->Front)%Q->MaxSize] = X;
    Q->Count++;
    return true;
}

ElementType DeleteQ( Queue Q ){
    if(Q->Count==0){
        printf("Queue Empty\n");
        return ERROR;
    }
    ElementType ret = Q->Data[Q->Front];
    Q->Front = (Q->Front+1)%Q->MaxSize;
    Q->Count--;
    return ret;

}

int main()
{
    ElementType X,Y,Z;
    Queue Q;


    Q = CreateQueue(20);
/*    while ( !done ) {
        switch( GetOp() ) {
        case addq:
            scanf("%d", &X);
            AddQ(Q, X);
            break;
        case delq:
            X = DeleteQ(Q);
            if ( X!=ERROR ) printf("%d is out\n", X);
            break;
        case end:
            while (Q->Count) printf("%d ", DeleteQ(Q));
            done = 1;
            break;
        }
    }   */
    scanf("%d",&X);
    AddQ(Q,X);
    for(int i=0;i<Q->Count;i++){
        printf("%d ",Q->Data[i]);
    }
    AddQ(Q,Y);
    for(int i=0;i<Q->Count;i++){
        printf("%d ",Q->Data[i]);
    }
    AddQ(Q,Z);
    for(int i=0;i<Q->Count;i++){
        printf("%d ",Q->Data[i]);
    }
}



/*
bool isEmpty(Queue Q){
    return Q->Count==0;
}
bool isFull(Queue Q){
    return Q->Count==Q->MaxSize;
}
*/
