#include<bits/stdc++.h>
using namespace std;
void Qsort(vector<int>&a,int low,int high)
{
    if(low<high)
    {
        int i=low,j=high,temp = a[low];
        while(i<j)
        {
            while(i<j&&a[j]>=temp)j--;
            if(i<j)a[i++] = a[j];
            while(i<j&&a[i]<=temp)i++;
            if(i<j)a[j--] = a[i];
        }
        a[i] = temp;
        Qsort(a,low,i-1);
        Qsort(a,i+1,high);
    }
}
int main ()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    Qsort(v,0,n-1);
    for(int i=0;i<n;i++)
    cout<<v[i]<<' ';
    return 0;
}