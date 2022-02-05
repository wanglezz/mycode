#include<iostream>
using namespace std;
class cset
{
   public:
      cset();
      ~cset();
      cset(const cset&);
      cset(cset &&)noexcept;
      bool remove(int x);
      bool in(int x);
      cset &operator = (const cset &rhs);
      cset &operator = (cset && rhs)noexcept;
      bool add(int x);
      void display();
      cset Join(const cset&rhs)const;
   private:
      struct Node
      {
         int data;
         Node *next;
      } *phead;
};
cset::cset()
{
   phead = new Node;
   phead->next = NULL;
}
cset::~cset()
{
   while(phead->next)
   {
      Node *p = phead;
      phead = p->next;
      delete p;
   }
}
bool cset::add(int x)
{
   Node *q = new Node;
   q->data = x;
   Node *p = phead;
   while(p->next&&x>p->next->data)
   {
      p = p->next;
   }
   if(p->next&&p->next->data==x)
      return false;
   q->next = p->next;
   p->next = q;
   return true;
}
void cset::display()
{
   Node *p = phead->next;
   cout<<'{';
   while(p->next)
   {
      cout<<p->data<<',';
      p = p->next;
   }
   cout<<p->data<<'}'<<endl;
}
cset cset::Join(const cset &rhs)const
{
   cset result;
   Node *last = result.phead;
   Node *p = phead->next;
   Node *q = rhs.phead->next;
   while(p&&q)
   {
      if(p->data==q->data)
      {
         Node *s = new Node;
         s->data = p->data;
         last->next = s;
         last = s;
         p = p->next;
         q = q->next;
      }
      else if(p->data<q->data)
         p = p->next;
      else  
         q = q->next;

   }
   last->next = NULL;
   return result;
}
bool cset::in(int x)
{
   Node *p = phead;
   while(p->next&&p->next->data<x)
   {
      p = p->next;
   }
   if(p->next&&p->next->data==x)
      return true;
   return false;
}
cset::cset(const cset&rhs)
{
   phead = new Node;
   Node *last = phead;
   Node *p = rhs.phead->next;
   while(p)
   {
      Node *q = new Node;
      q->data = p->data;
      last->next = q;
      last = q;
      p = p->next;
   }
   last->next = NULL;
}
cset::cset(cset&&rhs)noexcept
{
   phead = rhs.phead;
   rhs.phead = NULL;
}
cset & cset::operator = (const cset &rhs)
{
   cset tmp(rhs);
   Node *t = phead;
   phead = tmp.phead;
   phead = t;
   return *this;
}
cset & cset::operator = (cset &&rhs)noexcept
{
   Node *p = this->phead;
   this->phead = rhs.phead;
   rhs.phead = p;
   return *this;
}
int main ()
{
   cset a,b,s,s2;
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
   s = a.Join(b);
   s.display();
   return 0;
}
