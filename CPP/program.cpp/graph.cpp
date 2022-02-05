#include<bits/stdc++.h>
using namespace std;
#define Maxsize 100
struct Node{
    int a[4];//农夫，羊，狼，白菜
    Node *pre;
    Node *next;
};
struct CQueue{
    Node *head;
    Node *tail;
    int length;
};
int cnt = 0;
char* s[4] = {"农夫","羊","狼","白菜",};
int dis[4][4] = {{1,0,0,0},{1,1,0,0},{1,0,1,0},{1,0,0,1}};
void InitState(Node &state)//状态节点初始化
{
    for(int i=0;i<4;i++)state.a[i] = 0;
    state.next = state.pre = NULL;
}
void InitCQueue(CQueue &q)//队列初始化
{
    q.head = q.tail =(Node*)malloc(sizeof(Node));
    if(!q.head)exit(_OVERFLOW);
    q.head->next = NULL;
    q.length = 0;
}
void enQueue(CQueue &q,Node e)//入队列
{
    Node *p = (Node*)malloc(sizeof(Node));
    if(!p)exit(_OVERFLOW);
    for(int i=0;i<4;i++)p->a[i] = e.a[i];
    p->pre = e.pre;
    p->next = NULL;
    q.tail->next = p;
    q.tail = p;
    q.length++;
}
void deQueue(CQueue &q,Node &e)//出队列
{
    Node *p;
    p = q.head->next;
    for(int i=0;i<4;i++)e.a[i] = p->a[i];
    e.pre = p->pre;
    e.next = p->next;
    q.head->next = p->next;
    if(q.tail==p)q.tail = q.head;
    q.length--;
}
bool Queueempty(CQueue q)
{
    if(q.head==q.tail)return true;
    else return false;
}
bool succes(Node state)//判断是否成功过河
{
    for(int i=0;i<4;i++)
    {
        if(state.a[i]!=1)return false;
    }
    return true;
}
void print(Node *state){
    if(state->pre!=NULL)
        print(state->pre);
    for(int i=0;i<4;i++)printf("%d ",state->a[i]);
    printf("\n");
}
bool safe(int state[])//判断此状态是否安全
{
    if(state[0]==1)
    {
        if(state[1]==0&&state[2]==0)return false;
        if(state[1]==0&&state[3]==0)return false;
    }
    else
    {
        if(state[1]==1&&state[2]==1)return false;
        if(state[1]==1&&state[3]==1)return false;
    }
    return true;
}
Node bfs(Node state)//广搜
{
    CQueue q;
    InitCQueue(q);
    Node nextstate;
    InitState(nextstate);
    enQueue(q,state);//头节点入队列
    while(!Queueempty(q))
    {
        deQueue(q,nextstate);//队头出队列
        if(succes(nextstate))//判断队头是否满足条件
        {
            return nextstate;
        }
        for(int i=0;i<4;i++)
        {
            if(nextstate.a[0]==0&&i==0)continue;//如果农夫没过河则跳过{1，0，0，0}这一步
            int d[4];//d数组保存该点下一状态
            d[0] = nextstate.a[0]+dis[i][0];
            d[1] = nextstate.a[1]+dis[i][1];
            d[2] = nextstate.a[2]+dis[i][2];
            d[3] = nextstate.a[3]+dis[i][3];
            for(int i=0;i<4;i++)if(d[i]>=2)d[i] = 0;
            if(safe(d))//判断状态是否安全
            {
                for(int i=0;i<4;i++)state.a[i] = d[i];
                Node *p = (Node*)malloc(sizeof(Node));
                for(int i=0;i<4;i++)p->a[i] = nextstate.a[i];
                p->next = nextstate.next;
                p->pre = nextstate.pre;//连接上一个节点
                state.next = NULL;
                state.pre = p;
                enQueue(q,state);//该节点进队列
            }
        }
    }
    Node f;
    InitState(f);
    return f;
}
int main ()
{
    Node state;
    InitState(state);
    //for(int i=0;i<4;i++)printf("%d ",state.a[i]);
    Node fstate = bfs(state);
    if(!fstate.pre)printf("fail\n");
    else
    {
        Node* tail = (Node*)malloc(sizeof(Node));
        for(int i=0;i<4;i++)tail->a[i] = fstate.a[i];
        tail->next = fstate.next;
        tail->pre = fstate.pre;
        print(tail);
    }
    return 0;
}