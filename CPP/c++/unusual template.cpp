#include<bits/stdc++.h>
using namespace std;
class CException:public exception
{
    private:
        string msg;
    public:
        CException(string s,int i):msg(s)
        {
            stringstream stream;
            stream << i;
            string str;
            stream >> str;
            msg += str;
        };
        const char *what()const noexcept
        {
            return msg.c_str();
        }
};
template<class T>
class CVector
{
    private:
        T *Array;
        int msize,bufsize;
    public:
        CVector():Array(nullptr),msize(0),bufsize(0){};
        CVector(int n):Array(nullptr),msize(n),bufsize(n)
        {
            if(msize>0)
                Array = new T[bufsize];
        }
        ~CVector()
        {
            delete []Array;
        }
        CVector(const CVector &rhs);
        CVector(CVector &&rhs);
        CVector& operator = (const CVector &rhs);
        CVector& operator = (CVector &&rhs);
        void push(const T &rhs);
        T & at(int i)
        {
            if(i<0||i>=msize)
            {
                string msg("invalid index:");
                throw CException(msg,i);
            }
            return Array[i];
        }
        T & operator [](int i)
        {
            return Array[i];
        }
        int size()const
        {
            return msize;
        }
};
template<class T>
void CVector<T>::push(const T &rhs)
{
    if(bufsize<=msize)//空间不够要做扩容
    {
        CVector<T> tmpvec;
        tmpvec.bufsize = bufsize * 2 + 1;
        tmpvec.Array = new T[tmpvec.bufsize];
        tmpvec.msize = msize;
        for(int i=0;i<msize;i++)
        {
            tmpvec.Array[i] = Array[i];
        }
        swap(*this,tmpvec);
    }
    Array[msize++] = rhs;
}
template<class T>
CVector<T>::CVector(const CVector<T>&rhs):Array(nullptr),msize(rhs.msize),bufsize(rhs.bufsize)
{
    if(bufsize==0)
        return ;
    Array = new T[bufsize];
    for(int i=0;i<msize;i++)
    {
        Array[i] = rhs.Array[i];
    }
}
template<class T>
CVector<T>::CVector(CVector<T> &&rhs):Array(rhs.Array),msize(rhs.msize),bufsize(rhs.bufsize)
{
    Array = nullptr;
    msize = 0;
    bufsize = 0;
}
template<class T>
CVector<T>&CVector<T>::operator= (const CVector<T> &rhs)
{
    CVector<T> tmpvec(rhs);
    swap(Array,tmpvec.Array);
    swap(msize,tmpvec.msize);
    swap(bufsize,tmpvec.bufsize);
    return *this;
}
template<class T>
CVector<T>&CVector<T>::operator= (CVector<T> &&rhs)
{
    swap(Array,rhs.Array);
    swap(msize,rhs.msize);
    swap(bufsize,rhs.bufsize);
    return *this;
}
template<class T>
void Parse(int size)
{
    CVector<T> V(size);
    string cmd;
    T x;
    int index;
    while(cin>>cmd)
    {
        try
        {
            if(cmd=="quit")
                break;
            else if(cmd=="push")
            {
                cin>>x;
                V.push(x);
            }
            else if(cmd=="fetch")
            {
                cin>>index;
                x = V.at(index);
                cout<<' '<<x;
            }
            else if(cmd=="put")
            {
                cin>>index>>x;
                V.at(index) = x;
            }
        }
        catch(exception &e)
        {
            cout<<' '<<e.what();
        }
    }
    cout<<endl;
}
int main ()
{
    string s;
    while(cin>>s)
    {
        int size;
        cin>>size;
        if(s=="int")
            Parse<int>(size);
        else 
            Parse<string>(size);
    }
    return 0;
}