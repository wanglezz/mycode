#include<iostream>
#include<cstring>
using namespace std;
class cString
{
	public:
		cString();
		cString(const char *str);
		~cString(){
			delete []s;
		}
		cString(const cString &rhs);
		cString(cString &&rhs)noexcept;
		cString & operator = (const cString &rhs);
		cString & operator = (cString &&rhs)noexcept;
		friend ostream & operator <<(ostream &os,const cString &rhs);
		friend cString operator +(const cString &s1,const cString &s2);
		cString substr(int start,int length);
		char &operator[](int index);
		const char&operator [](int index)const;
		operator const char * ()const;
	private:
		explicit cString(int length)
		{
			s = new char[length+1];
			len = length;
		}
		char *s;
		int len;
};
cString::cString()
{
	len = 0;
	s = new char[1];
	s[0] = '\0';
}
cString::cString(const char *str)
{
	len = strlen(str);
	s = new char[len+1];
	strcpy(s,str);
}
cString::cString(const cString &rhs)
{
	len = rhs.len;
	s = new char[len+1];
	strcpy(s,rhs.s);	
}
cString::cString(cString &&rhs)noexcept
{
	len = rhs.len;
	s = rhs.s;
	rhs.s = NULL;	
} 
cString &cString::operator =(const cString &rhs)
{
	cString tmp(rhs);
	swap(s,tmp.s);
	swap(len,tmp.len);
	return *this; 
}
cString & cString::operator =(cString &&rhs)noexcept
{
	swap(s,rhs.s);
	swap(len,rhs.len);
	return *this;	
} 
cString cString::substr(int start,int length)
{
	cString temp(length);
	strncpy(temp.s,s+start,length);
	temp.s[length] = '\0';
	return temp;
}
ostream & operator << (ostream &os,const cString &rhs)
{
	os<<rhs.s;
	return os;
}
cString operator + (const cString &s1,const cString &s2)
{
	cString temp(s1.len+s2.len);
	strcpy(temp.s,s1.s);
	strcat(temp.s,s2.s);
	return temp;
}
const char& cString::operator[](int index)const
{
	if(index<0||index>len)
	{
		static char c;
		return c;
	}
	return s[index];
}
char & cString::operator[](int index)
{
	if(index<0||index>len)
	{
		static char c;
		return c;
	}
	return s[index];
}
cString::operator const char *()const
{
	return s;
}
int main ()
{
	char s1[256],s2[256];
	cin>>s1>>s2;
	cString s[4]{cString(s1),cString(s2)};
	char op;
	int i,j,k,l,pos;
	while(cin>>op)
	{
		switch(op)
		{
			case 'P':
				cin>>i;
				cout<<s[i-1]<<endl;
				break;
			case'A':
				cin>>i>>j;
				s[j-1] = s[i-1];
				break;
			case'C':
				cin>>i>>j>>k;
				s[k-1] = s[i-1] + s[j-1];
				break;
			case'F':
				cin>>i>>pos>>l>>k;
				s[k-1] = s[i-1].substr(pos,l);
				break;
		}
	}
}