#include<iostream>
using namespace std;
const int maxn = 1e5+1;
void merge(int a[],int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int l[n1+1],R[n2+1];//建立左右两个数组，分别储存两边的值
    for(int i=0;i<n1;i++)
    {
        l[i] = a[p+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i] = a[q+i+1];
    }
    int i=0,j=0;
    l[n1] = R[n2] = maxn;//设置两个哨兵，保证不会将空元素放入a数组
    for(int k=p;k<=r;k++)
    {
        if(l[i]>=R[j])
        {
            a[k] = R[j];
            j++;
        }
        else
        {
            a[k] = l[i];
            i++;
        }
    }
}
void Merge_Sort(int a[],int p,int r)
{
    if(p<r)
    {
        int q = (p+r)/2;//以q为中点将数组拆成两份
        Merge_Sort(a,p,q);//拆分
        Merge_Sort(a,q+1,r);//拆分
        merge(a,p,q,r);//合并
    }
}
int main ()
{
    int n;
    int a[maxn];
    int i=0;
    while(cin>>n)
    {
        a[i] = n;
        i++;
    }
    Merge_Sort(a,0,i-1);
    for(int j=0;j<i;j++)
        cout<<a[j]<<' ';
    cout<<endl;
    return 0;
}