#include<iostream>
using namespace std;
void Merge(int a[],int l,int m,int r,int b[])
{
    int i = l;
    int j = m+1;
    int k = i;
    while(i<=m&&j<=r)
    {
        if(a[i]<=a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while(i<=m)
        b[k++] = a[i++];
    while(j<=r)
        b[k++] = a[j++];
}
void MergeSort(int a[],int l,int r,int b[])
{
    if(l>=r)
        return;
    int m = (l+r)/2;
    MergeSort(a,l,m,b);
    MergeSort(a,m+1,r,b);
    Merge(a,l,m,r,b);
    for(int i=l;i<=r;i++)
        a[i] = b[i];
}
int main ()
{
    int n;
    int a[1000];
    int b[1000];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        MergeSort(a,0,n-1,b);
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}