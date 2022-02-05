#include<iostream>
using namespace std;
template<class T>
class num
{
    private:
        T a;
        T b;
    public:
        num(T x,T y){a=x;b=y;};
        T plus(){return a+b;};
        T minus(){return a-b;};
        T chen(){return a*b;};
        T chu(){return a/b;};
        T Ma(){return (a>b)?a:b;};
        T Mi(){return (a<b)?a:b;};
};
int main ()
{
    int a,b;
    double c,d;
    cin>>a>>b;
    cin>>c>>d;
    num<int>x(a,b);
    num<double>y(c,d);
    cout<<x.Ma()<<' '<<x.Mi()<<' '<<x.plus()<<' '<<x.minus()<<' '<<x.chen()<<' '<<x.chu()<<endl;
    cout<<y.Ma()<<' '<<y.Mi()<<' '<<y.plus()<<' '<<y.minus()<<' '<<y.chen()<<' '<<y.chu()<<endl;
    return 0;
}


