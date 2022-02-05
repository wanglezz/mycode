#include<iostream>
using namespace std;
int main ()
{
    int a[10000];
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
        {
            int x = a[i];
            int j = i-1;
            while(j>=0&&x<a[j])
            {
                a[j+1] = a[j];
                --j;
            }
            a[j+1] = x;
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}