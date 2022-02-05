/*
 * @Descripttion: 记忆化搜索
 * @Author: tomato
 * @version: 
 * @Date: 2022-01-28 23:01:55
 * @LastEditors: tomato
 * @LastEditTime: 2022-02-02 16:51:26
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 21;
typedef long long ll;
ll w[maxn][maxn][maxn];
ll vv(ll a,ll b,ll c)
{
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return vv(20,20,20);
    if(w[a][b][c]!=0)return w[a][b][c];
    if(a<b&&b<c)
    {
        w[a][b][c] = vv(a,b,c-1)+vv(a,b-1,c-1)-vv(a,b-1,c);
        return w[a][b][c];
    }
    w[a][b][c] = vv(a-1,b,c)+vv(a-1,b-1,c)+vv(a-1,b,c-1)-vv(a-1,b-1,c-1);
    return w[a][b][c];
}
int main()
{
    ll a,b,c;
    memset(w,0,sizeof(w));
    w[0][0][0] = 1;
    cin>>a>>b>>c;
    while(a!=-1||b!=-1||c!=-1)
    {   
        ll ans = vv(a,b,c);
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<ans<<endl;
        cin>>a>>b>>c;     
    }
    return 0;
}