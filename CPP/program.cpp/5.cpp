#include<bits/stdc++.h>
using namespace std;
long long int c[100001];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i];
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        long long int sum = 0;
        for(int i=a;i<=b;i++)sum += c[i];
        cout<<sum<<endl;
    }
}
int main ()
{
    solve();
    return 0;
}