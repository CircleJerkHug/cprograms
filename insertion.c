#include<stdio.h>
#include<stdlib.h>

void insertion(int arr[], int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

void printarr(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d\t",arr[i]);
}

int main()
{
	int *arr,n,i;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100;
		printf("%d\t",arr[i]);
	}
	insertion(arr,n);
	printf("\n");
	printarr(arr,n);
}