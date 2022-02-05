/*
 * @Descripttion: dfs(从n个数中选k个数求和，和为质数的个数)
 * @Author: tomato
 * @version: 
 * @Date: 2022-01-30 21:42:10
 * @LastEditors: tomato
 * @LastEditTime: 2022-01-30 22:23:11
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 25;
int n,k;
int a[maxn];
int ans = 0;
int isprime(int n)//判断指数
{
    if(n==0)return 0;
    if(n==1)return 0;
    if(n==2)return 1;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return 0;
    return 1;
}
void dfs(int m,int sum,int startx)//m表示当前选的数的个数，sum表示当前选的数的和，startx表示升序排列以免重复
{
    if(m==k)
    {
        if(isprime(sum))ans++;
        return;
    }
    for(int i=startx;i<=n;i++)
    {
        dfs(m+1,sum+a[i],i+1);
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(0,0,1);
    cout<<ans<<endl;
    return 0;
}