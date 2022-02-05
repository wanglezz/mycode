#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int main ()
{
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cin>>s;
        int flag = 1;
        int n = s.size()-2;
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]!='?')
            {
                if(s[n-i+1]=='?')
                {
                    s[n-i+1]=s[i];
                }
                else if(s[i]!=s[n-i+1])flag = 0;
            }
        }
        if(a%2==1||b%2==1)
        {
            int i = s.size()/2;
            if(s[i]!='?')flag = 0;
            s[i] = (a%2==1?'0':'1');
            if(a%2==1)
            {
                a--;
            }
            else {
                b--;
            }
        }
        if(a%2==1||b%2==1)flag = 0;
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]=='?')
            {
                if(a>1)
                {
                    s[i] = s[n-i+1] = '0';
                    a -= 2;
                }
                if(b>1)
                {
                    s[i] = s[n-i+1] = '1';
                    b -= 2;
                }
                if(a<=1&&b<=1) flag = 0;
            }
        }
        if(flag)cout<<s<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}