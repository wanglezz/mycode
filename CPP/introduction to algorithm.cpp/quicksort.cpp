#include<iostream>
using namespace std;
const int maxn = 1e5+1;
int PARTITION(int a[],int p,int r)
{
    //将数组根据a[r]划分为两个子数组
    int x = a[r];
    int i = p - 1;
    for(int j=p;j<=r-1;j++)//遍历数组
    {
        if(a[j]<=x)//如果该元素小于a[r]，i+=1，并将其与a[i]交换，从而保证下标小于i+1的元素的值小于a[r]
            {
                i = i + 1;
                swap(a[i],a[j]);
            }
    }
    swap(a[i+1],a[r]);//将a[r]插入作为分隔元素
    return i+1;//返回分隔开的数组的中间下标
}
void QUICKSORT(int a[],int p,int r)
{
    if(p<r)
    {
        int q = PARTITION(a,p,r);
        QUICKSORT(a,p,q-1);//递归调用，将子数组继续分割排序
        QUICKSORT(a,q+1,r);
    }
}
int main ()
{
    int a[maxn];
    int length = 1;
    int n;
    while(cin>>n)
    {
        a[length++] = n;
    }
    length--;
    QUICKSORT(a,1,length);
    for(int i=1;i<=length;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}