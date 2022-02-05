#include<bits/stdc++.h>
#define STACK_SIZE 100
#define charge 5
struct Node{
    char ch;
    int carnumber;
    int moment;
    Node *next;
};
struct Park{
    Node *top;
    Node *base;
    int size;
};
struct CQueue{
    Node *head;
    Node *tail;
    int length;
};
void InitStack(Park &p,int size)//栈初始化
{
    p.base = (Node *)malloc(sizeof(Node)*size);
    if(!p.base)exit(_OVERFLOW);
    p.top = p.base;
    p.size = size;
}
void InitCQueue(CQueue &q)//队列初始化
{
    q.head = q.tail = (Node*)malloc(sizeof(Node));
    if(!q.head)exit(_OVERFLOW);
    q.head->next = NULL;
    q.length = 0;
}
void Push(Park &p,Node e)//节点e入栈
{
    p.top++;
    p.top->ch = e.ch;
    p.top->carnumber = e.carnumber;
    p.top->moment = e.moment;
}
void Pop(Park &p,Node &e)//节点e出栈
{
    e.moment = p.top->moment;
    e.carnumber = p.top->carnumber;
    e.ch = p.top->ch;
    p.top--;
}
int stackfull(Park p)//判断是否栈满，栈满返回0否则返回1
{   
    if(p.top-p.base>=p.size)return 0;
    return 1;
}
void enQueue(CQueue &q,Node e)//节点e入队列
{
    Node *p = (Node*)malloc(sizeof(Node));
    if(!p)exit(_OVERFLOW);
    p->moment = e.moment;
    p->ch = e.ch;
    p->carnumber = e.carnumber;
    p->next = NULL;
    q.tail->next = p;
    q.tail = p;
    q.length++;
}
void deQueue(CQueue &q,Node &e)//节点e出队列
{
    Node *p;
    p = q.head->next;
    e.ch = p->ch;
    e.carnumber = p->carnumber;
    e.moment = p->moment;
    q.head->next = p->next;
    if(q.tail==p)q.tail = q.head;
    q.length--;
}
int main ()
{
    int n;
    printf("请输入停车场的规模:");
    scanf("%d",&n);
    Park p;//停车场栈
    Park tempp;//车道栈
    CQueue road;//过道队列
    InitStack(p,n);
    InitStack(tempp,STACK_SIZE);
    InitCQueue(road);
    Node e;
    scanf("%c%d%d",&e.ch,&e.carnumber,&e.moment);
    while(e.ch!='E')
    {
        if(!stackfull(p)&&e.ch=='A')//栈满，车辆入队列
            enQueue(road,e);
        if(stackfull(p)&&e.ch=='A')//栈不满，车辆进栈  
            Push(p,e);
        if(e.ch=='D')//有车辆要出栈
        {
            int leavetime = e.moment;
            while(p.top->carnumber!=e.carnumber)//自栈顶向下寻找该车辆进栈时间，同时将前面的车辆一个个出栈进入车道栈
            {
                Node temp;
                Pop(p,temp);
                Push(tempp,temp);
            }
            printf("%d车停留的时间:%d;应缴纳的费用:%d\n",e.carnumber,e.moment-p.top->moment,(e.moment-p.top->moment)*charge);//计算并输出时间和费用
            Pop(p,e);
            while(tempp.top!=tempp.base)//将上一步出栈的元素返回停车场
            {
                Node temp;
                Pop(tempp,temp);
                Push(p,temp);
            }
            if(road.length)//车辆出栈后如果队列不为空，则将队列首元素出队列后进栈，同时将元素的进栈时间改为车辆出栈的时间
            {
                Node temp;
                deQueue(road,temp);
                temp.moment = leavetime;
                Push(p,temp);
            }
        }
        scanf("%c%d%d",&e.ch,&e.carnumber,&e.moment);
    }
    getchar();
    return 0;
}