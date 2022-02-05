#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;
const double PI = 3.1416;
class Shape
{
    public:
        virtual ~Shape() {};
        virtual double areas()const = 0;
};
double totalarea(vector<Shape*>&s)
{
    double ans = 0;
    for(unsigned int i=0;i<s.size();i++)
    {
        ans += s[i]->areas();
    }
    return ans;
};
class Circle:public Shape
{
    public:
        double areas()const;
        Circle(double x):r(x) {};
    private:
        double r;
};
double Circle::areas()const
{
    return (r*r*PI);
};
class Rectangle:public Shape
{
    public:
        double areas()const;
        Rectangle(double x,double y):a(x),b(y) {};
    private:
        double a;
        double b;
};
double Rectangle::areas()const 
{
    return a*b;
};
class Triangle:public Shape
{
    public:
        double areas()const;
        Triangle(double x,double y,double z):a(x),b(y),c(z) {};
    private:
        double a;
        double b;
        double c;
};
double Triangle::areas()const
{
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
};
int main ()
{
    string t;
    vector<Shape *>v;
    double a,b,c;
    while(cin>>t)
    {
        if(t=="circle")
        {
            cin>>a;
            v.push_back(new Circle(a));
        }
        else if(t=="rectangle")
        {
            cin>>a>>b;
            v.push_back(new Rectangle(a,b));
        }
        else if(t=="triangle")
        {
            cin>>a>>b>>c;
            v.push_back(new Triangle(a,b,c));
        }
    }
    cout<<fixed<<setprecision(4)<<totalarea(v)<<endl;
    for(unsigned int i=0;i<v.size();i++)
    {
        delete v[i];
    }
    return 0;
}