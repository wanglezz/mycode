/*
 * @Descripttion: 递推
 * @Author: tomato
 * @version: 
 * @Date: 2022-02-04 12:40:54
 * @LastEditors: tomato
 * @LastEditTime: 2022-02-05 00:51:44
 */
#include<bits/stdc++.h>
using namespace std;
const int mod = 100003;
long long ans = 0;
const int maxn = 1e5+2;
int a[maxn];
int main()
{
    int n,k;
    cin>>n>>k;
    memset(a,0,sizeof(a));
    a[1] = 1;
    for(int i=2;i<=k;i++)
    {
        a[i] = (2*a[i-1])%mod;
    }
    for(int i=k+1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
            a[i] = (a[i]+a[i-j])%mod;
    }
    if(k==1)a[n]=1;
    cout<<a[n]<<endl;
    return 0;
}