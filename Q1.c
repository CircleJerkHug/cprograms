#include<stdio.h>
#include<stdlib.h> 

struct node
{
	int data;
	struct node *next;
}typedef Node;

void printlist(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d \t",head->data);
		head=head->next;
	}
	printf("\n");
}

void push(struct node **head, int value)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));

	newnode->data=value;
	newnode->next=*head;
	*head=newnode;
}

void append(struct node **head,int value)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	struct node *last=*head;
	newnode->data=value;
	newnode->next=NULL;
	if(*head==NULL)
	{
		*head=newnode;
		return;
	}
	while(last->next!=NULL)
	{
		last=last->next;
		last->next=newnode;
		return;
	}
}

int main()
{
	int i,n,num,a,ch;
	Node *head=NULL;
	head=malloc(sizeof(head));
	if(head==NULL)
		return 0;
	printf("Enter the number of nodes");
	scanf("%d",&n);
	Node *temp=head;

	for(i=0;i<n;i++)
	{
		if(i!=0)
		{
			temp->next=malloc(sizeof(Node));
			temp=temp->next;
		}
		printf("Enter the value to be stored in node %d :",i+1);
		scanf("%d",&temp->data);
		temp->next=NULL;
	}
	printlist(head);
	printf("Enter the choice 1 for push at beginning and 2 for end\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("\n");
		printf("Enter the node value to be pushed\n");
		scanf("%d",&num);
		push(&head,num);	break;
		case 2:
		printf("Enter the value to append\n");
		scanf("%d",&a);
		append(&head,a);	break;
	}
	printlist(head);
	/*{
		printf("\n");
		printf("Enter the node value to be pushed\n");
		scanf("%d",&num);
		push(&head,num);
		printlist(head);
		printf("Enter the value to append\n");
		scanf("%d",&a);
		append(&head,a);
		printlist(head);
	}
}*/
}