#include<iostream>
using namespace std;
class rational
{
    private:
        int numt;
        int denot;
    public:
        rational();
        rational(int a,int b);
        rational(const rational &rhs);
        rational & operator = (const rational &rhs);
        friend void check(rational &rhs);
        friend ostream &operator <<(ostream &os,const rational &rhs);
        friend rational operator + (const rational &a,const rational &b);
        friend rational operator - (const rational &a,const rational &b);
        friend rational operator * (const rational &a,const rational &b);
        friend rational operator / (const rational &a,const rational &b);
};
void check(rational &rhs)
{
    for(int i=2;i<=min(abs(rhs.numt),abs(rhs.denot));i++)
    {
        if(rhs.numt%i==0&&rhs.denot%i==0)
        {
            rhs.numt /= i;
            rhs.denot /= i;
        }
    }
}
rational::rational()
{
    numt = 0;
    denot = 0;
}
rational::rational(int a,int b)
{
    numt = a;
    denot = b;
}
rational::rational(const rational &rhs)
{
    numt = rhs.numt;
    denot = rhs.denot;
}
rational &rational::operator = (const rational &rhs)
{
    rational tmp(rhs);
    numt = tmp.numt;
    denot = tmp.denot;
    return *this;
}
rational operator + (const rational &a,const rational &b)
{
    rational tmp;
    tmp.numt = a.numt*b.denot + a.denot*b.numt;
    tmp.denot = a.denot*b.denot;
    return tmp;
}
rational operator * (const rational &a,const rational &b)
{
    rational tmp;
    tmp.numt = a.numt * b.numt;
    tmp.denot = a.denot * b.denot;
    return tmp;
}
rational operator - (const rational &a,const rational &b)
{
    rational tmp;
    tmp.numt = a.numt*b.denot - a.denot*b.numt;
    tmp.denot = a.denot * b.denot;
    return tmp;
}
rational operator / (const rational &a,const rational &b)
{
    rational tmp;
    tmp.numt = a.numt * b.denot;
    tmp.denot = a.denot * b.numt;
    return tmp;
}
ostream & operator <<(ostream &os,const rational &rhs)
{
    if(rhs.denot==1)os<<rhs.numt<<'\t';
    else if(rhs.numt<0&&rhs.denot<0)os<<-rhs.numt<<'/'<<-rhs.denot<<'\t';
    else if(rhs.numt*rhs.denot<0)os<<'-'<<abs(rhs.numt)<<'/'<<abs(rhs.denot)<<'\t';
    else os<<rhs.numt<<'/'<<rhs.denot<<'\t';
    return os;
};
int main ()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    rational r1(a,b),r2(c,d);
    check(r1);
    check(r2);
    cout<<r1<<endl<<r2<<endl;
    rational e,f,g,h;
    e = r1 + r2;
    f = r1 - r2;
    g = r1 * r2;
    h = r1 / r2;
    check(e);
    check(f);
    check(g);
    check(h);
    cout<<e<<f<<g<<h;
    return 0;
}