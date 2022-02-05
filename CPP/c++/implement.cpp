#include<bits/stdc++.h>
using namespace std;
class CPoint
{
    public:
        int x,y;
        CPoint(int a,int b):x(a),y(b){};
        CPoint(const CPoint&point)
        {
            x = point.x;
            y = point.y;
        }
};
class CShape
{
    public:
        virtual bool Hitin(const CPoint &)const = 0;
        virtual ~CShape(){};
};
class CUIControl
{
    public:
        CShape *m_pShape;
        bool HitTest (const CPoint &point);
        void SetShape(CShape *pShape);
        virtual void clicked ()const = 0;
        virtual ~CUIControl(){};
};
bool CUIControl::HitTest(const CPoint &point)
{
    if(m_pShape->Hitin(point))return true;
    return false;
}
void CUIControl::SetShape(CShape *pShape)
{
    m_pShape = pShape;
}
class CButton:public CUIControl
{
    private:
        string m_strName;
    public:
        CButton(string strName)
        {
            m_strName = strName;
        };
        virtual void clicked()const;
};
void CButton::clicked()const
{
    cout<<"button-"<<m_strName<<" Clicked"<<endl;
}
class CMenu:public CUIControl
{
    private:
        string m_strName;
    public:
        CMenu(string strName)
        {
            m_strName = strName;
        };
        virtual void clicked()const;
};
void CMenu::clicked()const
{
    cout<<"menu-"<<m_strName<<" Clicked"<<endl;
}
class CRectangle:public CShape
{
    private:
        CPoint m_pos;
        int m_width;
        int m_height;
    public:
        virtual bool Hitin(const CPoint &point)const;
        CRectangle(CPoint pos,int x,int y):m_pos(pos),m_width(x),m_height(y){};
};
bool CRectangle::Hitin(const CPoint &point)const
{
    if(point.x-m_pos.x<=m_width&&point.y-m_pos.y<=m_height&&point.x-m_pos.x>=0&&point.y-m_pos.y>=0)
        return true;
    return false;
}
class CCircle:public CShape
{
    private:
        CPoint m_center;
        double m_radius;
    public:
        CCircle(CPoint center,double r):m_center(center),m_radius(r){};
        virtual bool Hitin(const CPoint &point)const;
};
bool CCircle::Hitin(const CPoint &point)const
{
    double s;
    s = sqrt((point.x-m_center.x)*(point.x-m_center.x)+(point.y-m_center.y)*(point.y-m_center.y));
    if(s<m_radius)return true;
    return false;
}
int main ()
{
    vector<CUIControl *>v(100);
    int n;
    string s;
    cin>>n;
    int a,b,c,d;
    double r;
    for(int i=0;i<n;i++)
    {
        string name;
        //cout<<1;
        cin>>name;
        if(name=="menu")
        {
            cin>>s;
            cin>>name;
            if(name=="circle")
            {
                cin>>a>>b>>r;
                CPoint p(a,b);
                v[i] = new CMenu(s);
                v[i]->SetShape(new CCircle(p,r));
            }
            else
            {
                cin>>a>>b>>c>>d;
                //cout<<1;
                CPoint p(a,b);
                v[i] = new CMenu(s);
                v[i]->SetShape(new CRectangle(p,c,d));
            }
        }
        else if(name=="button")
        {
            cin>>s;
            cin>>name;
            if(name=="circle")
            {
                cin>>a>>b>>r;
                CPoint p(a,b);
                v[i] = new CButton(s);
                v[i]->SetShape(new CCircle(p,r));
            }
            else if(name=="rectangle")
            {
                cin>>a>>b>>c>>d;
                CPoint p(a,b);
                v[i] = new CButton(s);
                v[i]->SetShape(new CRectangle(p,c,d));
            }
        }
    }
    while(cin>>s>>a>>b)
    {
        CPoint p(a,b);
        int i;
        for(i=n-1;i>=0;i--)
        {
            if(v[i]->m_pShape->Hitin(p))
            {
                v[i]->clicked();
                break;
            }
        }
        if(i==-1)cout<<"none hit"<<endl;
    }
    return 0;
}