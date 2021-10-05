#include<bits/stdc++.h>
using namespace std;

struct node{
    int info;
	struct node *next;
};


struct node *getnode()
{
	struct node *p;
	p=new node;
	return p;
}

void insbeg(struct node **link,int x)
{
	struct node *p;
	p=getnode();
	p->info=x;
	p->next=*link;
	*link=p;
}

void insafter(struct node **link,int x)
{
	struct node *p,*q;
	p=*link;
	while(p->info!=x)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
		q=getnode();
		q->info=x;
		q->next=p->next;
		p->next=q;
	}
	else
	{
		cout<<"void insertion";
	}
}

void insend(struct node **link,int x)
{
	struct node *p,*q;
	p=*link;
    if(p==NULL)
        insbeg(link,x);
    else{
        	while(p->next!=NULL)
        		{
        			p=p->next;
        		}
        		q=getnode();
        		q->info=x;
        		p->next=q;
        		q->next=NULL;
        }
}

int delafter(struct node *p)
{
	if(p!=NULL && p->next!=NULL)
	{
		struct node *q;
		q=p->next;
		p->next=q->next;
		int x=q->info;
		free(q);
		return x;
	}
		return -1;
}

void traverse(struct node *link)
{
	struct node *p;
	p=link;
	while(p!=NULL)
	{
		cout<<p->info;
		p=p->next;
        if(p!=NULL)
            cout<<" -> ";
	}
}

void delrepeat(struct node *start)
{
	struct node *curr,*prev;
	map<int,int>m;
	curr=start;
	m[curr->info]=1;
	prev=curr;
	curr=curr->next;

	while(curr!=NULL)
	{
		if(m[curr->info])
		{
			prev->next=curr->next;
			free(curr);
		}
		else{
			m[curr->info]=1;
			prev=curr;
		}
		curr=prev->next;

	}
}

struct node *deletek(struct node *start,int k)
{
	struct node *start2=getnode();
	start2->next=start;
	struct node *p,*q;
	p=start2;
	q=start2;
	for (int i=1; i<=k; i++)
        {
            p=p->next;
        }
	while(p->next!=NULL)
	{
		p=p->next;
		q=q->next;	
	}
	q->next=q->next->next;
	return start2->next;
}
int main()
{
	struct node *start=NULL;
		insend(&start,600);
        insend(&start,400);
        insend(&start,300);
        insend(&start,200);
        insend(&start,100);
        insend(&start,90);
        start=deletek(start,4);
        traverse(start);
 }
