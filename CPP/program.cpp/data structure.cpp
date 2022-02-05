#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int m,n;
    while(cin>>m>>n&&m!=-1&&n!=-1)
    {
        double a[n],b[n];
        double c[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
            c[i] = a[i]/b[i];
        }
        for(int i=0;i<n-1;i++)
        {
            int index = i;
            for(int j=i+1;j<n;j++)
            {
                if(c[j]>c[index])index = j;
            }
            swap(c[index],c[i]);
            swap(b[index],b[i]);
            swap(a[index],a[i]);
        }
        //for(int i=0;i<n;i++)cout<<a[i]<<b[i]<<c[i];
        double ans = 0;
        for(int i=0;i<n;i++)
        {
            if(m>b[i])
            {
                ans += a[i];
                m -= b[i];
            }
            else 
            {
                ans += m*c[i];
                m = 0;
            }
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;    
    }   
    return 0;
}