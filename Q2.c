#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void printlist(struct node* node)
{
	while(node!=NULL)
	{
		printf("%d\t",node->data);
		node=node->next;
	}
}

struct node poslast(struct node *pos)
{
	while(pos!=NULL && pos->next!=NULL)
		pos=pos->next;
	return pos; 
}

struct node *partition(struct node *head, struct node *last,struct node *newhead,struct node *newlast)
{
	struct node *pivot=last;
	struct node *prev=NULL, *cur=head, *last=pivot;

	while(cur!=pivot)
	{
		if(cur->data < pivot->data)
		{
			if(*newhead==NULL)
				*newhead=cur;
		}
		else
		{
			if(prev)
				prev->next=cur->next;
			struct node *temp=cur->next;
			cur->next=NULL;
			last->next=cur;
			last=cur;
			cur=temp;
		}
	}
}