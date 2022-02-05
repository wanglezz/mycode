#include<iostream>
using namespace std;
const int maxn = 1e5+1;
void radix_sort(int a[],int length,int pos)
{
    
}
void RADIX_SORT(int a[],int length,int d)
{
    for(int i=1;i<=d;i++)
    {
        radix_sort(a,length,i);
    }
}
int main ()
{
    int a[maxn];
    int length = 1;
    int n;
    while(cin>>n)
    {
        a[length++] = n;
    }
    length--;
    int max = 0;
    int d = 0;
    for(int i=1;i<=length;i++)if(a[i]>max)max = a[i];
    while(max!=0)
    {
        max /= 10;
        d++;
    }
    RADIX_SORT(a,length,d);
}