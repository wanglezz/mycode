#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
class unsignedbignumber
{
    private:
        list<int>buffer;
        int length;
    public:
        unsignedbignumber operator +(const unsignedbignumber &rhs);
        unsignedbignumber operator -(const unsignedbignumber &rhs);
        unsignedbignumber &operator =(unsignedbignumber &&rhs);
        bool compare(const unsignedbignumber &rhs);
        void getnumber();
        void display();
};
void unsignedbignumber::getnumber()
{
    char s[maxn];
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        int a = s[i] - '0';
        buffer.push_back(a);
    }
}
void unsignedbignumber::display()
{
    for(list<int>::iterator it=buffer.begin();it!=buffer.end();it++)
    {
        cout<<*it;
    }
    cout<<endl;
}
bool unsignedbignumber::compare(const unsignedbignumber &rhs)
{   
    if(buffer.size()>rhs.buffer.size())return true;
    if(buffer.size()<rhs.buffer.size())return false;
    for(list<int>::iterator it=buffer.size())
}
int main ()
{
    unsignedbignumber a,b;
    a.getnumber();
    //char ch = getchar();
    b.getnumber();
    a.display();
    b.display();
}