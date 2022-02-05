#include<bits/stdc++.h>
using namespace std;
struct Iris{
    double sepalLength;
    double spealWidth;
    double petalLength;
    double petalWidth;
    char name[20];
};
int datanum;
double dist[120];
struct Iris iris[150];
struct Iris test[30];
struct Iris train[120];
struct Iris final[3];
bool Inputs()//输入数据集
{
    char fname[256];
    cout<<"请输入存放数据的文件名:";
    scanf("%s",fname);
    cout<<endl<<"样本数目:";
    scanf("%d",&datanum);
    FILE *fp = fopen(fname,"rb");
    if(fp==NULL)
    {
        cout<<"不能打开文件！"<<endl;
        return false;
    }
    for(int i=0;i<datanum;i++)
    {
        fscanf(fp,"%lf,%lf,%lf,%lf,%s",&iris[i].sepalLength,&iris[i].spealWidth,&iris[i].petalLength,&iris[i].petalWidth,iris[i].name);
    }
    fclose(fp);
    return true;
}
void Swap(Iris a,Iris b)//交换两个结构体的内容
{
    swap(a.petalLength,b.petalLength);
    swap(a.petalWidth,b.petalWidth);
    swap(a.sepalLength,b.sepalLength);
    swap(a.spealWidth,b.spealWidth);
    swap(a.name,b.name);
}
void disorder()//数据集预处理
{
    srand(time(0));
    for(int i=0;i<1500;i++)
    {
        int index = rand()%150;
        int index1 = rand()%150;
        swap(iris[index],iris[index1]);
    }
}
void dispair()//将数据集分为测试集和训练集
{
    for(int i=0;i<30;i++)
    {
        test[i].sepalLength = iris[i].sepalLength;
        test[i].spealWidth = iris[i].spealWidth;
        test[i].petalLength = iris[i].petalLength;
        test[i].petalWidth = iris[i].petalWidth;
        strcpy(test[i].name,iris[i].name);
    }
    for(int i=30;i<150;i++)
    {
        train[i-30].sepalLength = iris[i].sepalLength;
        train[i-30].spealWidth = iris[i].spealWidth;
        train[i-30].petalLength = iris[i].petalLength;
        train[i-30].petalWidth = iris[i].petalWidth;
        strcpy(train[i-30].name,iris[i].name);
    }
}
double distance2point(Iris a,Iris b)//计算两点之间的欧几里得距离
{
    double ans = 0;
    ans += (a.sepalLength-b.sepalLength)*(a.sepalLength-b.sepalLength);
    ans += (a.spealWidth-b.spealWidth)*(a.spealWidth-b.spealWidth);
    ans += (a.petalLength-b.petalLength)*(a.petalLength-b.petalLength);
    ans += (a.petalWidth-b.petalWidth)*(a.petalWidth-b.petalWidth);
    return sqrt(ans);
}
void judge(Iris a)//找出距离a点最近的三个点
{
    for(int j=0;j<3;j++)
    {
        int index = j;
        for(int i=j+1;i<120;i++)
        {
            if(distance2point(a,train[i])<distance2point(a,train[index]))index = i;
        }
        final[j].petalLength = train[index].petalLength;
        final[j].petalWidth = train[index].petalWidth;
        final[j].sepalLength = train[index].sepalLength;
        final[j].spealWidth = train[index].spealWidth;
        strcpy(final[j].name,train[index].name);
        Swap(train[index],train[j]);
    }
}
bool compare(Iris a)//判断a点与其最近三个点中出现次数最多的种类是否相同
{
    int x1(0),x2(0),x3(0);
    for(int i=0;i<3;i++)
    {
        if(!strcmp(final[i].name,"Iris-setosa"))
        x1++;
        if(!strcmp(final[i].name,"Iris-versicolor"))
        x2++;
        if(!strcmp(final[i].name,"Iris-virginica"))
        x3++;
    }
    int x = max(max(x1,x2),x3);
    if(x==x1)
    {
        if(!strcmp(a.name,"Iris-setosa"))return true;
        else return false;
    }
    else if(x==x2)
    {
        if(!strcmp(a.name,"Iris-versicolor"))return true;
        else return false;
    }
    else if(x==x3)
    {
        if(!strcmp(a.name,"Iris-virginica"))return true;
        else return false;
    }
    return true;
}
double KNN()
{
    int ans = 0;
    for(int i=0;i<30;i++)
    {
        judge(test[i]);
        if(compare(test[i]))
        ans++;
    }
    return (ans/30.0);
}
int main ()
{
    Inputs();
    disorder();
    dispair();
    double percent = KNN();
    cout<<percent<<endl;
    return 0;
}
