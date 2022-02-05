#include<iostream>
#include<stdlib.h>
using namespace std;
const int maxn = 1e5+1;
//三个数组a,b,c,a数组存放待排序数组,b数组存放输出数组,c数组提供临时储存空间
void COUNTING_SORT(int a[],int b[],int k,int n)//计数排序
{
    int c[maxn];
    for(int i=0;i<=k;i++)c[i] = 0;
    for(int j=1;j<=n;j++)
        c[a[j]] = c[a[j]]+1;
    for(int i=1;i<=k;i++)
        c[i] = c[i] + c[i-1];
    for(int j=n;j>=1;j--)
        {
            b[c[a[j]]] = a[j];
            c[a[j]] = c[a[j]] - 1;
        }
}
int main ()
{
    int a[maxn],b[maxn];
    int n;
    int length = 1;
    int k = maxn;
    while(cin>>n)
    {
        a[length++] = n;
    }
    length--;
    COUNTING_SORT(a,b,k,length);
    for(int i=1;i<=length;i++)
        cout<<b[i]<<' ';
    cout<<endl;
    system("pause");
    return 0;
}