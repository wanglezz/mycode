#include<iostream>
using namespace std;
const int maxn = 1e5+1;
int parent(int i)//父节点
{
    return i/2;
}
int left(int i)//左儿子
{
    return 2*i;
}
int right(int i)//右儿子
{
    return 2*i+1;
}
void MAX_HEAPIFY(int a[],int i,int heapsize,int length)//建立最大堆
{
    //将i节点与其左右儿子节点比较，其中最大的下标储存在largest变量中
    int l = left(i);
    int r = right(i);
    int largest = 0;
    if(l<=heapsize&&a[l]>a[i])
        largest = l;
    else
        largest = i;
    if(r<=heapsize&&a[r]>a[largest])
        largest = r;
    //然后交换a[largest]与a[i]，最后递归调用MAX_HEAPIFY构建最大堆
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        MAX_HEAPIFY(a,largest,heapsize,length);
    }
}
void build_max_Heap(int a[],int heapsize,int length)
{
    heapsize = length;
    for(int i=length/2;i>=1;i--)
    {
        MAX_HEAPIFY(a,i,heapsize,length);
    }
}
void heapsort(int a[],int heapsize,int length)
{
    build_max_Heap(a,heapsize,length);
    for(int i=length;i>=2;i--)
    {
        swap(a[1],a[i]);
        heapsize = heapsize - 1;    
        MAX_HEAPIFY(a,1,heapsize,length);
    }
}
int main ()
{
    int a[maxn];
    int i=1;
    int n;
    while(cin>>n)
    {
        a[i++] = n;
    }
    int heapsize = i-1;
    int length = i-1;
    heapsort(a,heapsize,length);
    for(int i=1;i<=length;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}