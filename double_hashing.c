#include <stdio.h>
#include <stdlib.h>

typedef struct slot
{
	int data;
	int vis;
}slot;

int n_p(int n)							//calculates next smallest prime
{										//bigger than n		
	int i=n+1;
	while(1)
	{
		int count=0;
		for (int j = 2; j < n; ++j)
		{
			if(i%j==0) count++;
		}
		if (count==0)
		{
			return i;
		}
		else i++;
	}
}

int hash1(int key,int m)				//hash func 1
{
	return key%m;
}

int hash2(int key,int n)				//hash func 2
{
	return (1+(key%n));
}

int hash(slot a[],int key,int size,int prime )
{
	int j=0,i;
	while(j<size)
	{
		i=((hash1(key,prime))+j*(hash2(key,prime-1)))%size;		//setting i
		if(a[i].vis==0||a[i].vis==2)
		{
			a[i].data=key;								//empty slot found
			a[i].vis=1;
			return i;
		}
		else
		{
			j++;									//else collision
		}
	}
	return (-1);									//array full
}


int main()
{
	int i,j,m,n,index;
	printf("enter n=");
	scanf("%d",&n);
	m=n_p(2*n);
	slot a[m];
	for (int i = 0; i < n; ++i)
	{
		a[i].vis=0;
	}
	printf("enter numbers\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&j);
		index=hash(a,j,2*n,m);
		if(index>=0)printf("inserted at index %d\n",index );
		else printf("Array full. error\n");
	}
}
