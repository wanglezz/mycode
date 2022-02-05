#include<bits/stdc++.h>
using namespace std;
long long int c[100001];
void solve()
{
   int m,n;
   while(cin>>m>>n)
   {
       if(m%(n+1)==0)cout<<"none";
       else if(n>=m)
       {
           for(int i=m;i<n;i++)cout<<i<<' ';
           cout<<n;
       }
       else 
       {
           int a[2000];
           int cnt = 0;
           for(int i=1;i<=n;i++)
           {
               if((m-i)%(n+1)==0)
               {
                   a[cnt++] = i;
               }
           }
           for(int i=0;i<cnt-1;i++)cout<<a[i]<<' ';
           cout<<a[cnt-1];
       }
       cout<<endl;
   }
}
int main ()
{
    solve();
    return 0;
}