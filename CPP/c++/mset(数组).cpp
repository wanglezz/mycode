#include<iostream>
using namespace std;
const int maxn = 100;
class mset
{
    public:
        mset():count(0){};
        bool add(int x);
        void display()const;
        mset Union(const mset&rhs)const;
        mset subtract(const mset&rhs);
        bool in(int x)const;
        mset intersection(const mset&rhs)const;
    private:
        int data[maxn];
        int count;
};
bool mset::add(int x)
{
    if(in(x))return false;
    if(count>=maxn)
    throw"OverFlow";
    int i = count-1;
    while(i>=0&&x<data[i])
    {
        data[i+1] = data[i];
        i--;
    }
    data[i+1] = x;
    count++;
    return true;
}
void mset::display()const
{
    cout<<"{";
    int i;
    for(i=0;i<count-1;i++)
    cout<<data[i]<<",";
    if(i<count)cout<<data[i];
    cout<<"}"<<endl;
}
mset mset::Union(const mset&rhs)const
{
    mset result;
    int i,j;
    i = j = 0;
    while(i<count&&j<rhs.count)
    {
        if(result.count>=maxn)
        throw"OverFlow";
        if(data[i]<rhs.data[j])
        {
            result.data[result.count++] = data[i];
            i++;
        }
        else if(data[i]==rhs.data[j])
        {
            result.data[result.count++] = data[i];
            i++;
            j++;
        }
        else
        {
            result.data[result.count++] = rhs.data[j];
            j++;
        }
    }
    while(i<count)
    {
        if(result.count>=maxn)
            throw"OverFlow";
        result.data[result.count++] = data[i];
        i++;
    }
    while(j<rhs.count)
    {
        if(result.count>=maxn)
            throw"OverFlow";
        result.data[result.count++] = rhs.data[j];
        j++;
    }
    return result;
}
mset mset::intersection(const mset&rhs)const
{
    mset result;
    int j = 0;
    for(int i=0;i<rhs.count;i++)
    {
        if(in(rhs.data[i]))
        {
            result.data[j++] = rhs.data[i];
            result.count++;
        }
    }
    return result;
};
mset mset::subtract(const mset&rhs)
{
    mset result;
    int j = 0;
    for(int i=0;i<count;i++)
    {
    	if(!rhs.in(data[i]))
    	{
    		result.data[j++] = data[i];
    		result.count++;
		}
	}
    return result;
}
bool mset::in(int x)const
{
    int i=0;
    while(i<count&&x>data[i])i++;
    if(i<count&&x==data[i])return true;
    return false;
}
int main ()
{
    mset a,b,s,e,f;
    int i,m,n,x;
    cin>>m>>n;
    for(i=0;i<m;i++)
    {
        cin>>x;
        a.add(x);
    }
    for(i=0;i<n;i++)
    {
        cin>>x;
        b.add(x);
    }
    a.display();
    b.display();
    s = a.Union(b);
    s.display();
    e = a.intersection(b);
    e.display();
    
    f = a.subtract(b);
    f.display();
    return 0;
}