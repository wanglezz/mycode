#include<bits/stdc++.h>
    using namespace std;
    struct Node{
        int data;
        Node *next;
    };
    void insert(Node *head,int x)
    {
        Node *p = new Node;
        p->data = x;
        Node *q = head;
        while(q->next)
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
    void destroy(Node *head)
    {
        while(head->next)
        {
            Node *p = head->next;
            delete head;
            head = p;
        }
    }
    int main ()
    {
        int m;
        int n;
        cin>>m;
        Node *head = new Node;
        head->next = NULL;
        for(int i=1;i<=m;i++)
        insert(head,i);
        Node *head2 = new Node;
        head2->next = NULL;
        while(cin>>n)
        {
            if(n!=1)
            {
                Node *p = head->next;
            while(p->next)p = p->next;
            p->next = head->next;
            Node *q = head->next;
            while(q!=q->next)
            {
                for(int i=1;i<n-1;i++)
                q = q->next;
                insert(head2,q->next->data);
                q->next = q->next->next;
                q = q->next;
            }
            insert(head2,q->next->data);
            head->next = head2->next;
            head2->next = NULL;
            }
        }
        Node *p = head->next;
        while(p->next)
        {
        	printf("%4d",p->data);
        	p = p->next;
		}
		printf("%4d\n",p->data);
		destroy(head);
		destroy(head2);
        return 0;
    }