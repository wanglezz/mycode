#include<bits/stdc++.h>
using namespace std;
const int num = 1e5+1;
struct User_Information
{
    long long number;
    string name;
    bool sex;
    string IDcard;
    string Information;
    string CarId;
    string reason;
    person p;
    bool beentoyiqu;
    bool fever;
    string accesstime;
    string accessouttime;
    string intime;
    string outtime;
    int Approvernumber;
    bool Approveresult;
    string notaccessreason;
    string location;
}   
struct person
{
    string name;
    string phonenumber;
}
void Statistic()
{
    User_Information u;
    vector<User_Information>v(num);
    string s;
    person searchp;
    string searchlocation;
    string searchname;
    string searchday;
    while(cin>>s)
    {
        if(s=="danbaoren")
        {
            cin>>searchp.name>>searchp.phonenumber;
        }
        else if(s=="location")
        {
            cin>>searchlocation;
        }
        else if(s=="name")
        {
            cin>>searchname;
        }
        else if(s=="day")
        {
            cin>>searchday;
        }
    }
    freopen("D:\\Codefield\\CPP\\program.cpp\\testdata.txt","w",stdout);
    freopen("D:\\Codefield\\CPP\\program.cpp\\testdata.txt","r",stdin);
    while(cin>>u.number)
    {
        cin>>u.name>>u.sex>>u.IDcard>>u.Information>>u.CarId>>u.reason>>u.p.name>>u.p.phonenumber>>u.beentoyiqu>>u.fever>>u.accesstime>>u.intime>>u.outtime>>u.accessouttime>>u.Approvernumber>>u.Approveresult>>u.notaccessreason>>u.location;
        v.push_back(u);
    }
    
}