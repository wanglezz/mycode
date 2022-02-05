#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prve;
};
struct ubignum{
    int digitcount;
    Node *phead;
    Node *ptail;
};
void _init(ubignum *pubn)
{
    Node *p = new Node;
    pubn->phead = pubn->ptail = p;
    p->next = NULL;
    p->prve = NULL;
    pubn->digitcount = 0;
}
void adddigit(ubignum *pubn,int digit)
{
    if(pubn->digitcount==1&&pubn->ptail->data==0)
    {
        pubn->ptail->data = digit;
        return ;
    }
    Node *p = new Node;
    p->data = digit;
    p->next = NULL;
    p->prve = pubn->ptail;
    pubn->ptail->next = p;
    pubn->ptail = p;
    ++pubn->digitcount;
}
void addfrontdigit(ubignum *pubn,int digit)
{
    Node *p = new Node;
    p->data = digit;
    p->next = pubn->phead->next;
    if(p->next!=NULL)
        p->next->prve = p;
    p->prve = pubn->phead;
    pubn->phead->next = p;
    if(pubn->ptail==pubn->phead)
        pubn->ptail = p;
    ++pubn->digitcount;
}
void Normalize(ubignum *pubn)
{
    if(pubn->digitcount==0)
    {
        adddigit(pubn,0);
    }
    while(pubn->digitcount>1&&pubn->phead->next->data==0)
    {
        Node *p;
        p = pubn->phead->next;
        pubn->phead->next = p->next;
        p->next->prve = pubn->phead;
        delete p;
        --pubn->digitcount;
    }
}
ubignum input()
{
    ubignum result;
    _init(&result);
    char ch;
    do 
        ch = getchar();
    while(ch<'0'||ch>'9');
    while(ch>='0'&&ch<='9')
    {
        adddigit(&result,ch-'0');
        ch = getchar();
    }
    Normalize(&result);
    return result;
}
void destroy(ubignum *pubn)
{
    while(pubn->phead!=NULL)
    {
        Node *p = pubn->phead;
        pubn->phead = p->next;
        delete p;
    }
}
void print(ubignum pubn)
{
    Node *la = pubn.phead->next;
    while(la)
    {
        cout<<la->data;
        la = la->next;
    }
}
ubignum add(ubignum *pa,ubignum *pb)
{
    ubignum presult,*result = &presult;
    _init(result);
    int icarry = 0;
    Node *p1,*p2;
    p1 = pa->ptail;
    p2 = pb->ptail;
    while(p1!=pa->phead&&p2!=pb->phead)
    {
        int digit = p1->data + p2->data + icarry;
        icarry = digit / 10;
        digit %= 10;
        addfrontdigit(result,digit);
        p1 = p1->prve;
        p2 = p2->prve;
    }
    while(p1!=pa->phead)
    {
        int digit = p1->data + icarry;
        icarry = digit / 10;
        digit %= 10;
        addfrontdigit(result,digit);
        p1 = p1->prve;
    }
    while(p2!=pb->phead)
    {
        int digit = p2->data + icarry;
        icarry = digit / 10;
        digit %= 10;
        addfrontdigit(result,digit);
        p2 = p2->prve;
    }
    if(icarry!=0)
    {
        addfrontdigit(result,icarry);
    }
    return presult;
}
ubignum Minus(ubignum *pa,ubignum *pb)
{
    ubignum result,*presult = &result;
    _init(presult);
    int icarry = 0;
    Node *p1,*p2;
    p1 = pa->ptail;
    p2 = pb->ptail;
    while(p1!=pa->phead&&p2!=pb->phead)
    {
        int digit = p1->data - p2->data - icarry;
        if(digit<0)icarry = 1;
        else icarry = 0;
        if(digit<0)digit += 10;
        addfrontdigit(presult,digit);
        p1 = p1->prve;
        p2 = p2->prve;
    }
    while(p1!=pa->phead)
    {
        int digit = p1->data - icarry;
        if(digit<0)icarry = 1;
        else icarry = 0;
        if(digit<0)digit += 10;
        addfrontdigit(presult,digit);
        p1 = p1->prve;
    }
    Normalize(presult);
    return result;
}
int main ()
{
    ubignum a,b,c,d;
    a = input();
    b = input();
    c = add(&a,&b);
    d = Minus(&a,&b);
    print(a);
    cout<<'+';
    print(b);
    cout<<'=';
    print(c);
    cout<<endl;
    print(a);
    cout<<'-';
    print(b);
    cout<<'=';
    print(d);
    destroy(&a);
    destroy(&b);
    destroy(&c);
    destroy(&d);
    return 0;
}
