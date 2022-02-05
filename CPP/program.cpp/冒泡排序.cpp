#include<iostream>
using namespace std;
class Vector
{ 
friend ostream &operator<<(ostream &out, const Vector &v);
private:
int *data;
int size;
public:
 Vector();
Vector(int a[],int n);
Vector(const Vector &s);
~Vector();
Vector &operator=(const Vector &v);
int &operator[](int index);
}; 
Vector::Vector()
{ 
data=NULL;
size=0;
} 
Vector::Vector(int a[],int n)
{ 
size = n;
data = new int[size];
for(int i=0;i<size;i++)
 data[i]=a[i];
} 
Vector::Vector(const Vector &s)
{ 
size = s.size;
data = new int[size];
for(int i=0;i<size;i++)
 data[i]=s.data[i];
} 
Vector::~Vector()
{ 
if(data!=NULL)
 delete[]data;
} 
Vector &Vector::operator=(const Vector &v)
{ 
if(this == &v)
 return *this;
if(size != v.size)
 { 
 delete[] data;
 size = v.size;
 data = new int[size];
 } 
for(int i=0;i<=size;i++)
 data[i] = v.data[i];
return *this;
} 
int &Vector::operator[](int index)
{ 
return data[index];
} 
ostream &operator<<(ostream &out, const Vector &v)
{ 
for(int i=0;i<v.size;i++)
 out<<v.data[i]<<" ";
return out;
}