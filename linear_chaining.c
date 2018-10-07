#include <stdio.h>
#include <stdlib.h>


typedef struct node                                         //structure for linked list
{
  int data;
  struct node* next;
}node, *list;

list create_node()                                           //Dynamically allocating memory                              
{
  list temp=(list)malloc(sizeof(node));
  temp->next=NULL;
  return temp;
}

int hash(int a)                                              //taking hash function h=k mod 10
{
  return a%10;
}

void ins(int a,int idx, list h[])                             //inserting elements in hash table
{
  if(h[idx]==NULL)
  {
    h[idx]=create_node();
  }
  list ptr=h[idx];
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  ptr->data=a;
  ptr->next=create_node();
}

void pr(list h[])                                                   //printing the hash table with linked list which has encountered collision 
{
  for (int i = 0; i < 10; ++i)
  {
    list itr=h[i];
    printf("%d:",i+1 );
    if(itr!=NULL)
    { 
      while(itr->next!=NULL)
      {
        printf("->%d",itr->data );
        itr=itr->next;
      }
    }
    printf("\n");
  }
}

int main()                                                          //main method for taking number of elements
{
  int n,i;
  list h[10]={NULL};
  scanf("%d",&n);
  for (int i = 0; i < n; ++i)
  {
    int a;
    scanf("%d",&a);
    ins(a,hash(a),h);
  }
  pr(h);
}