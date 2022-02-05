#include<bits/stdc++.h>
using namespace std;
struct TimeInfo
{
    string strIn,strOut;
};
struct human
{
    string strName;
    string strPhone;
    string strJobNumber;
};
struct ApprovalForm
{
    TimeInfo Apply,Actual;
    long long Order;
    string strName;
    bool bGender;
    string strPhone;
    string strID_card;
    string strUnit;
    string strPlateNumber;
    string strWhy;
    human hGuarantee;
    string strArea;
    bool bAffectedArea;
    bool bCold;
    int iApprover;
    bool bResult;
    string strReason;
};
int FindByOrder(long long Order)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].Order==Order)
        return i;
    }
}
vector<ApprovalForm>CountByName(const vector<ApprovalForm> &data, string cmpName)
{
    vector<ApprovalForm>res;
    for(int i=0;i<data.size();i++)
    {
        if(cmpName==data[i].strName)
        res.push_back(data[i]);
    }
    return res;
}
vector<ApprovalForm>CountByArea(const vector<ApprovalForm>& data, string cmpArea)
{
    vector<ApprovalForm>res;
    for(int i=0;i<data.size();i++)
    {
        if(cmpArea==data[i].strArea);
        res.push_back(data[i]);
    }
    return res;
}
vector<ApprovalForm>CountByHuman(const vector<ApprovalForm>& data, string cmpJobNumber)
{
    vector<ApprovalForm>res;
    for(int i=0;i<data.size();i++)
    {
        if(cmpJobNumber==data[i].hGuarantee.strJobNumber);
        res.push_back(data[i]);
    }
    return res;
}
vector<ApprovalForm>CountByTime(const vector<ApprovalForm>& data, string cmpTime)
{
    vector<ApprovalForm>res;
    for(int i=0;i<data.size();i++)
    {
        if(cmpTime==data[i].Apply.strIn);
        res.push_back(data[i]);
    }
    return res;
}