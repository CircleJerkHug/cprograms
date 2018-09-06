#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack
{
	int top;
	unsigned capacity;
	int *array;
};

struct Stack* createstack(unsigned capacity)
{
	struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(int *)malloc(stack->capacity * sizeof(int));
	return stack;
}

int isfull(struct Stack* stack)
{
	return stack->top==stack->capacity-1;
}

int isempty(struct Stack* stack)
{
	return stack->top==-1;
}

void push(struct Stack* stack,int item)
{
	if(isfull(stack))
		return;
	stack->array[++stack->top]=item;
	printf("%d pushed to the stack\n",item);
}

int pop(struct Stack* stack)
{
	if(isempty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

int main()
{
	int i,num,n;
	struct Stack* stack=createstack(100);
	printf("Enter the number of elements in stack:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the number:");
		scanf("%d",&num);
		push(stack,num);
	}
	printf("%d popped from the stack\n",pop(stack));
	return 0;
}