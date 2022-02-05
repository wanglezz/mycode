#include<bits/stdc++.h>
# define Elemtype char
typedef struct CNode{
    Elemtype data;
    struct CNode *firstchild;
    struct CNode *nextsibling;
}CNode,*CTree;
struct CStack{
    int size;
    CNode *top;
    CNode *base;
};
void InitStack(CStack &s)
{
    s.base = (CNode*)malloc(sizeof(CNode)*50);
    if(!s.base)exit(_OVERFLOW);
    s.top = s.base;
    s.size = 50;
}
void Push(CStack &s,CNode e)
{
    s.top++;
    s.top->data=e.data;
    s.top->firstchild=e.firstchild;
    s.top->nextsibling=e.nextsibling;
}
void Pop(CStack &s,CNode &e)
{
    e.firstchild=s.top->firstchild;
    e.nextsibling=s.top->nextsibling;
    e.data=s.top->data;
    s.top--;
}
bool stack_empty(CStack s)
{
    if(s.top-s.base>0)return false;
    return true;
}
CTree Creat(CTree t)
{
    char ch;
    scanf(" %c",&ch);
    if(ch=='#'){t=NULL;return t;}
    else
    {
        t = (CNode*)malloc(sizeof(CNode));
        t->data = ch;
        t->firstchild = NULL;
        t->nextsibling = NULL;
        printf("输入%c的第一个孩子\n",ch);
        t->firstchild = Creat(t->firstchild);
        printf("输入%c的下一个兄弟\n",ch);
        t->nextsibling = Creat(t->nextsibling);
    }
    return t;
}
void print(CNode* p)
{
    printf("%c ",p->data);
}
void Forder_recursion(CNode*root)
{
    if(!root)return;
    print(root);
    Forder_recursion(root->firstchild);
    Forder_recursion(root->nextsibling);
}
void Lorder_recursion(CNode*root)
{
    if(!root)return;
    Lorder_recursion(root->firstchild);
    print(root);
    Lorder_recursion(root->nextsibling);
}
void Forder_nonrecursion(CNode*root)
{
    CStack s;
    InitStack(s);
    CNode e;
    while(root)
    {
        e.firstchild=root->firstchild;
        e.data=root->data;
        e.nextsibling=root->nextsibling;
        print(root);
        Push(s,e);
        root = root->firstchild;
    }
    while(!stack_empty(s))
    {
        Pop(s,e);
        CNode* p = e.nextsibling;
        if(p)
        {
            CNode *q = p;
            while(q)
            {
                print(q);
                e.data = q->data;
                e.firstchild = q->firstchild;
                e.nextsibling = q->nextsibling;
                Push(s,e);
                q=q->firstchild;    
            }
        }
    }
    return;
}
void Lorder_nonrecursion(CNode*root)
{
    CStack s;
    InitStack(s);
    CNode e;
    while(root)
    {
        e.firstchild=root->firstchild;
        e.data=root->data;
        e.nextsibling=root->nextsibling;
        Push(s,e);
        root = root->firstchild;
    }
    while(!stack_empty(s))//判空
    {
        Pop(s,e);
        CNode *temp = &e;
        print(temp);
        CNode *p = e.nextsibling;
        if(p)
        {
            CNode *q = p;
            while(q)
            {
                e.data = q->data;
                e.firstchild = q->firstchild;
                e.nextsibling = q->nextsibling;
                Push(s,e);
                q=q->firstchild;    
            }
        }

    }
    return;
}
void InitTree(CTree &t)
{
    t = (CNode*)malloc(sizeof(CNode));
    t->data = ' ';//头节点
    t->firstchild = NULL;
    t->nextsibling = NULL;
    printf("输入根节点:\n");
    t->firstchild = Creat(NULL);
}
int main ()
{
    CTree t;
    InitTree(t);
    CNode *root = t->firstchild;
    //printf("%c %c",root->data,root->firstchild->data);
    Forder_recursion(root);
    printf("\n");
    Lorder_recursion(root);
    printf("\n");
    Forder_nonrecursion(root);
    printf("\n");
    Lorder_nonrecursion(root);
    return 0;
}