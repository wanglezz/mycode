#include<bits/stdc++.h>
#define MAXSIZE 100
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prve;
};
typedef struct{
    Node *head;
    char c;
    int linksize;
}longintger;
void InitSqList(longintger l)
{
    l.head = (Node*)malloc(MAXSIZE*sizeof(Node));
    if(!l.head)exit(_OVERFLOW);
    l.head->next = l.head;
    l.head->prve = l.head;
    l.c = '+';
    l.linksize = MAXSIZE;
}
void plus(longintger a,longintger b)
{
    longintger res;
    InitSqList(res);
    while()
}
