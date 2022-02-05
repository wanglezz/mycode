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
    int flag = 0;
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
    {
        ch = getchar();
        if(ch=='-')
        result.flag = 1;
    }
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
int compare(ubignum *pa,ubignum *pb)
{
    if(pa->digitcount>pb->digitcount)
    {
        return 1;
    }
    else if(pa->digitcount<pb->digitcount)
    {
        return 0;
    }
    else 
    {
        Node *p1,*p2;
        p1 = pa->phead->next;
        p2 = pb->phead->next;
        if(p1==pa->ptail&&p2==pb->ptail)
        {
            //cout<<'1';
            if(p1->data>p2->data)return 1;
            else if(p1->data<p2->data)return 0;
            else return -1;
        }
        while(p1!=pa->ptail&&p2!=pb->ptail)
        {
            if(p1->data>p2->data)return 1;
            else if(p1->data<p2->data)return 0;
            else 
            {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return -1;
    }
}
int main ()
{
    ubignum a,b,c,d;
    a = input();
    b = input();
    if(a.flag==0&&b.flag==0)
    {
        c = add(&a,&b);
        print(c);
        cout<<endl;
        //cout<<compare(&a,&b);
        if(compare(&a,&b)==0)
        {
            d = Minus(&b,&a);
            cout<<'-';
        }
        else d = Minus(&a,&b);
        print(d);
    }
    else if(a.flag==1&&b.flag==1)
    {
        c = add(&a,&b);
        cout<<'-';
        print(c);
        cout<<endl;
        if(compare(&a,&b)==1)
        {
            d = Minus(&a,&b);
            cout<<'-';
        }
        else d = Minus(&b,&a);
        print(d);
    }
    else if(a.flag==0&&b.flag==1)
    {
        if(compare(&a,&b)==0)
        {
            c = Minus(&b,&a);
            cout<<'-';
        }
        else c = Minus(&a,&b);
        print(c);
        cout<<endl;
        d = add(&a,&b);
        print(d);
    }
    else 
    {
        if(compare(&a,&b)==1)
        {
            c = Minus(&a,&b);
            cout<<'-';
        }
        else c = Minus(&b,&a);
        print(c);
        cout<<endl;
        d = add(&a,&b);
        cout<<'-';
        print(d);
    }
    destroy(&a);
    destroy(&b);
    destroy(&c);
    destroy(&d);
    return 0;
}