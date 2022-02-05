#define MAXQSIZE 100
typedef struct{
    ElemType *base;
    int front;
    int length;
}SqQueue;
status InitQueue(SqQueue &q)
{
    q.base = (ElemType *)malloc(MAXQSIZE*sizeof(ElemType));
    if(!q.base)exit(OVERFLOW);
    q.front = q.length = 0;
    return OK;
}
status EnQueue(SqQueue &q,ElemType e)
{
    if(q.front == q.length%MAXQSIZE&&q.length)return ERROR;
    int rear = (q.front+q.length)%MAXQSIZE;
    q.base[q.front] = e;
    q.length++;
    return OK;
}
status DeQueue(SqQueue &q,ElemType &e)
{
    if(q.length)return ERROR;
    e = q.base[q.front];
    q.front = (q.front+1)%MAXQSIZE;
    return OK;
}