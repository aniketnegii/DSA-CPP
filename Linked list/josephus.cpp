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

void insbeg(struct node **cstart,int x)
{
	struct node *p;
	p=getnode();
	p->info=x;
	if((*cstart)==NULL)
	{
		*cstart=p;
		p->next=(*cstart);
	}
	else{
	p->next=(*cstart)->next;
	(*cstart)->next=p;
	}
}

void insend(struct node **cstart,int x)
{
	struct node *q;

		q=getnode();
		q->info=x;
		if((*cstart)==NULL)
	{
		*cstart=q;
		q->next=(*cstart);
	}
	else{
		q->next=(*cstart)->next;
		(*cstart)->next=q;
		*cstart=q;
	}
}

void insafter(struct node **q,int x)
{
	if((*q)==NULL)
		cout<<"Void insertion";
	else{
		struct node *p=getnode();
		p->info=x;
		p->next=(*q)->next;
		(*q)->next=p;
	}
}


int delbeg(struct node **start)
{
	struct node *p,*q;
	int x;
	
	if((*start)!=NULL)
	{	
		p=(*start)->next;
		if(p->next==p)
		{
			*start=NULL;
			x=p->info;
			free(p);
		}
		else
		{
			(*start)->next=p->next;
			x=p->info;
			free(p);
		}
	}
	else{
	cout<<"void deletion";
	}
	return x;
}

int delend(struct node **start)
{
	struct node *p,*q;
	int x;
	
	if((*start)!=NULL)
	{	
		p=(*start)->next;

		if(p->next==p)
			{
				(*start)=NULL;
				x=p->info;
			}

		else{
				while(p->next!=(*start))
				{
					p=p->next;
				}
				p->next=(*start)->next;
				q=*start;
				(*start)=p;
				x=q->info;
				free(q);
		}
		
	}
	else{
	cout<<"void deletion";
	}
	return x;
}

int delafter(struct node **p)
{
	struct node *q;
	int x;
	
	if(*p!=NULL)
	{	
			q=(*p)->next;
			(*p)->next=q->next;
			x=q->info;
			free(q);
	}
	else{
	cout<<"void deletion";
	}
	return x;
}


void traverse(struct node *link)
{
	struct node *p;
	p=link->next;
	while(p!=link)
	{
		cout<<p->info;
		p=p->next;
        cout<<" -> ";
	}
	cout<<p->info;
}

int josephus(struct node *cstart,int k)
{
	int x,count;
	struct node *p,*q;
	p=cstart->next;
	while(p->next!=p)
	{
		count=1;
		while(count!=k-1)
		{
			count+=1;
			p=p->next;
		}
		q=p;
		p=p->next;
		p=p->next;
		x=delafter(&q);	
		cout<<x<<" "<<"is killed"<<endl;
	}
	
	return p->info;

}


int main()
{
        struct node *cstart=NULL,*p,*q;
        int x=1,survivor;
  		for(int i=1;i<102;i++)
        	{
        		insend(&cstart,x);
        		x+=1;
        	}
        	traverse(cstart);
        	cout<<endl;
		survivor=josephus(cstart,1);   
		cout<<"The person to survive is => "<<survivor;     
}
