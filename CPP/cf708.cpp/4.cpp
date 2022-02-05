#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
struct Node{
    string name;
    int height;
    int weight;
};
class Student
{
    private:
        int num = 0;
        Node s;
        int j;
    public:
        int number(){return num;};
        void Print()
        {
            printf("%06d ",num);
            cout<<s.name<<' '<<s.height<<' '<<s.weight<<endl;
        }
        void student(int x,string c,int a,int b)
        {
            if(a>s.height)
            {
                s.name = c;
                s.height = a;
                s.weight = b;
            }
            num = x;
        }
};
Student stud[10000000];
int main ()
{
    int n;
    cin>>n;
    int num;
    string name;
    int height;
    int weight;
    int max = -1;
    for(int i=0;i<n;i++)
    {
        cin>>num>>name>>height>>weight;
        stud[num].student(num,name,height,weight);
        if(max<num)max = num;
    }
    stud[0].Print();
    //stud[1].Print();
    //stud[3].Print();
    //cout<<max<<endl;
    for(int i=1;i<=max;i++)
    {
        if(stud[i].number()!=0)
        stud[i].Print();
    }
    return 0;
}