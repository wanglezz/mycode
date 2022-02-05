/*
 * @Descripttion: 头部注释
 * @Author: tomato
 * @version: 
 * @Date: 2022-02-05 13:01:31
 * @LastEditors: tomato
 * @LastEditTime: 2022-02-05 15:42:54
 */
#include<bits/stdc++.h>
using namespace std;
const int x = 200+1;
const int y = 6+1;
int a[x][y];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        a[i][1] = 1;a[i][0] = 1;
    }
    for(int x=2;x<=k;x++){a[1][x]=0;a[0][x]=0;}
    for(int i=2;i<=n;i++)
        for(int j=2;j<=k;j++)
            if(i>j)a[i][j] = a[i-1][j-1]+a[i-j][j];
            else a[i][j] = a[i-1][j-1];
    cout<<a[n][k];
    return 0;
}