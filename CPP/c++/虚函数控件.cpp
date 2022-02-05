#include<iostream>
#include<string>
#include<vector>
using namespace std;
class CUIControl 
{
    public:
        virtual void Clicked ()const = 0;
        virtual ~CUIControl() {};
};
class CMenu:public CUIControl
{
    public:
        void Clicked()const;
        CMenu(string c):s(c) {};
    private:
        string s;
};
void CMenu::Clicked()const
{
    cout<<"menu-"<<s<<' '<<"Clicked"<<endl;
};
class CButton:public CUIControl
{
    public:
        void Clicked()const;
        CButton(string c):s(c) {};
    private:
        string s;
};
void CButton::Clicked()const
{
    cout<<"button-"<<s<<' '<<"Clicked"<<endl;
}
int main ()
{
    vector<CUIControl *>v;
    string s,a;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(s=="menu")
        {
            cin>>a;
            v.push_back(new CMenu(a));
        }
        else if(s=="button")
        {
            cin>>a;
            v.push_back(new CButton(a));
        }
    }
    while(cin>>s)
    {
        int t;
        cin>>t;
        v[t-1]->Clicked();
    }
    for(unsigned int i=0;i<v.size();i++)
        delete v[i];
    return 0;
}