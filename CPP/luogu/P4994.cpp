/*
 * @Descripttion: 头部注释
 * @Author: tomato
 * @version: 
 * @Date: 2022-02-05 15:51:09
 * @LastEditors: tomato
 * @LastEditTime: 2022-02-05 19:51:00
 */
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9+1;
int a[maxn];
int main()
{
    int m;
    cin>>m;
    a[0] = 0;a[1] = 1;
    for(int i=2;;i++)
    {
        a[i] =(a[i-1]+a[i-2])%m;
        if(!a[i-1]&&a[i]==1)
        {
            cout<<i-1;
            break;
        }
    }
    return 0;
}