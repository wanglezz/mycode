#include<iostream>
using namespace std;
const int maxn = 1e5+1;
void insertion_sort(int a[],int len)//升序插入
{
    for(int i=1;i<len;i++)
    {
        int key = a[i];//保存当前的值，便于比较
        int j = i-1;//从当前位置前一位开始比较
        while(j>-1&&a[j]>key)//当找到小于key值的值终止循环
        {
            a[j+1] = a[j];//每比较一次就将a[j]的值后移一位
            j--;
        }
        a[j+1] = key;//在小于key值的后一位插入key
    }
}
void f(int a[],int n)//降序插入
{
    for(int i=1;i<n;i++)
    {
        int key = a[i];
        int j = i-1;
        while(j>-1&&a[j]<key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
int main ()
{
    int a[maxn];
    int i = 0;
    int n;
    while(cin>>n)
    {
        a[i] = n;
        i++;
    }
    f(a,i);
    for(int j=0;j<i;j++)
        cout<<a[j]<<' ';
    cout<<endl;
    return 0;
}