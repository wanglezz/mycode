#include<stdio.h>
double mypow(int x,int n)
{
    double ans = 1;
    while(n--)
    {
        ans *= x;
    }
    return ans;
}
double factor(int n)
{
    if(n==1)return 1;
    else return factor(n-1)*n;
}
int main ()
{
    int x = 3;
    int n = 2;
    double ans = mypow(x,n);
    double f = factor(x);
    printf("%lf %lf",ans,f);
    return 0;
}