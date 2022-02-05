#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void insert(Node *head,int x)
{
    Node *p = new Node;
    p->data = x;
    Node *q = head;
    while(q->next&&x>q->next->data)
    {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
}
void destroy(Node *head)
{
    Node *p = head;
    while(p)
    {
        head = head->next;
        delete(p);
        p = head;
    }
}
void print(Node *head)
{
    head = head->next;
    while(head->next)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data;
    cout<<endl;
}
void reverse(Node *head)
{
    Node *p,*q;
    p = head->next;
    head->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
}
Node *megre(Node *head1,Node *head2)
{
    Node *p = new Node;
    p = head1->next;
    while(p->next)
    {
        p = p->next;
    }
    head2 = head2->next;
    p->next = head2->next;
    return head1;
}
Node *Split(Node *head)
{
    Node *p = head->next;
    Node *a;
    Node *q;
    Node *head2 = new Node;
    head2->next = NULL;
    a = head;
    q = head2;
    while(p)
    {
    	if(p->data%2==1)
    	{
    		a->next = p;
    		a = p;
    		p = p->next;
		}
		else
		{
			q->next = p;
			q = p;
			p = p->next;
		}
	 }
	 a->next = NULL;
	 q->next = NULL;
	 return head2; 
}
int main ()
{
    Node *pos = new Node;
    Node *neg = new Node;
    pos->next = NULL;
    neg->next = NULL;
    int x;
    while(cin>>x)
    {
        if(x>0)insert(pos,x);
        else insert(neg,x);
    }
    if(pos->next)print(pos);
    else cout<<endl;
    if(neg->next)print(neg);
    else cout<<endl;
    Node *head = megre(neg,pos);
    if(head->next)print(head);
    else cout<<endl;
    destroy(pos);
    destroy(neg);
    destroy(head);
    return 0;
}