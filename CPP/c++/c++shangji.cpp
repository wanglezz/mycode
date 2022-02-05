#include <iostream>
using namespace std;

/* 你提交的代码将被嵌在这里 */
class CRAFT
{
    protected:
        double speed;
    public:
        CRAFT(double s):speed(s){cout<<"创建航行器"<<"(速度"<<":"<<speed<<")"<<endl;};
        ~CRAFT(){cout<<"销毁航行器"<<"(速度"<<":"<<speed<<")"<<endl;};
        virtual void Show(){cout<<"航行"<<"(速度"<<":"<<speed<<")"<<endl;};
        double getspeed(){return speed;};
};
class PLANE:public CRAFT
{
    protected:
        double width;
    public:
        double getwidth(){return width;};
        PLANE(double s,double w):CRAFT(s),width(w){cout<<"创建飞机"<<"(翼展"<<":"<<width<<")"<<endl;};
        void Show(){cout<<"航行"<<"(速度"<<":"<<getspeed()<<','<<"翼展"<<":"<<getspeed()<<")"<<endl;};
        ~PLANE(){cout<<"销毁飞机"<<"(翼展"<<":"<<width<<")"<<endl;};
};
class SHIP:public CRAFT
{
    protected:
        double depth;
    public:
    double getdepth(){return depth;};
    SHIP(double s,double w):CRAFT(s),depth(w){cout<<"创建船"<<"(吃水"<<":"<<depth<<")"<<endl;};
    void Show(){cout<<"航行"<<"(速度"<<":"<<getspeed()<<','<<"吃水"<<":"<<getspeed()<<")"<<endl;};
    ~SHIP(){cout<<"销毁船"<<"(吃水"<<":"<<depth<<")"<<endl;};  
}
class SEAPLANE:public PLANE,public SHIP
{
    public:
    SEAPLANE(double s,double w,double d):speed(s),width(w),depth(d){cout<<"创建水上飞机"<<endl;};
    void Show(){cout<<"航行"<<"(速度:"<<getspeed()<<",翼展:"<<getwidth()<<",吃水:"<<getdepth()<<")"<<endl;};
    ~SEAPLANE(){cout<<"销毁水上飞机"<<endl;};
};
int main()
{
    CRAFT *p;
    p = new SEAPLANE(415.2, 36.5, 2.1);
    p->Show();
    delete p;
    return 0;
}