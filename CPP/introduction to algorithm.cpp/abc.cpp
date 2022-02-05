#include<bits/stdc++.h>
struct Node{
    int key;
    int number;
    struct Node *next;
    struct Node *prve;
};
struct DLinklist{
    Node *head;
    int Linksize;
    int length;
};
int LINK_INIT_SIZE = 100;
void InitLinklist(DLinklist &L)//双向循环链表初始化
{
    L.head = (Node *)malloc(sizeof(Node));
    if(!L.head)exit(_OVERFLOW);
    L.head->next = L.head;
    L.head->prve = L.head;
    L.length = 0;
    L.Linksize = LINK_INIT_SIZE;
}
void ElemDelete(Node *p)//删除节点
{
    p->prve->next = p->next;
    p->next->prve = p->prve;
    free(p); 
}
void yosefu(DLinklist &L,Node *phead,int m)
{       
    if(!L.length)return;
    Node *p = phead;
    if(m>L.length/2)
    {
        m = abs(L.length-m)+2;
        while(m--)
        {
            p = p->prve;
            if(p==L.head)
            p = p->prve;
        }
        printf("%d ",p->number);
    }
    else
    {
        while(m--)
        {
            p = p->next;
            if(p==L.head)
            p = p->next;
        }
        printf("%d ",p->number);
    }
    m = p->key;
    Node *q = p->next;
    if(q==L.head)q = q->next;
    ElemDelete(p);
    L.length--;
    yosefu(L,q,m-1);
}
int main()
{
    int n;
    int key;
    scanf("%d",&n);
    DLinklist L;
    InitLinklist(L);
    L.length = n;
    Node *q = L.head;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&key);
        Node *p = (Node *)malloc(sizeof(Node));
        p->key = key;
        p->number = i;
        q->next = p;
        p->prve = q;
        p->next = L.head;
        L.head->prve = p;
        q = p;//将节点插入链表
    }
    int m;
    scanf("%d",&m);
    m = m%n;
    yosefu(L,L.head,m);
    return 0;
}