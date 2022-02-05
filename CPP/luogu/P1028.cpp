//递归递推
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1001;
int mp[maxn];
int f(int a)
{
    if(a==1)return 1;
    if(mp[a]!=0)return mp[a];
    int ans = 1;
    for(int i=1;i<=a/2;i++)
    {
        mp[i] = f(i);
        ans += mp[i];
    }
    mp[a] = ans;
    return ans;
}
int main ()
{
    int n;
    cin>>n;
    memset(mp,0,sizeof(mp));
    cout<<f(n)<<endl;
    return 0;
}