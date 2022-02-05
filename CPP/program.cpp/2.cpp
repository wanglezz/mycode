#include<iostream>
#include<string>
#include<list>
using namespace std;
class ubnum
{
    private:
        list<int>l;
        void Normalize()
    public:
        ubnum();
        void Input();
        void display();
        ubnum add(const ubnum &rhs)const;
        ubnum sub(const ubnum &rhs)const;
        bool compare(const ubnum &rhs)const;
};
ubnum::ubnum()
{
    l.push_back(0);
}
void ubnum::Normalize()
{
    if(l.size()==0)
        l.push_back(0);
    while(l.size()>1&&*l.begin()==0)
        l.pop_front();
}
void ubnum::Input()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        int a = s[i] - '0';
        l.push_back(a);
    }
}
void ubnum::display()
{
    for(auto it=l.begin();it!=l.end();it++)
    {
        cout<<*it;
    }
    cout<<endl;
}
ubnum ubnum::add(const ubnum &rhs)
{
    ubnum ans;
    ans.l.pop_front();
    int icarry = 0;
    auto it = l.rbegin(),it2 = rhs.l.rbegin();
    while(it!=l.rend()&&it2!=rhs.l.rend())
    {
        int digit = *it1 + *it2 + icarry;
        icarry = digit / 10;
        digit %= 10;
        ans.l.push_front(digit);
        ++it;++it2;
    }
    while(it!=l.rend())
    {
        int digit = *it + icarry;
        icarry = digit / 10;
        digit %= 10;
        ans.l.push_front(digit);
        ++it;
    }
    while(it2!=rhs.l.rend())
    {
        int digit = *it + icarry;
        icarry = digit / 10;
        digit %= 10;
        ans.l.push_front(digit);
        ++it2;
    }
    if(icarry!=0)
        ans.l.push_front(icarry);
    return ans;
}