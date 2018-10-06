#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int arr[], int low, int high)
{
	int pivot=arr[high],i=low-1,j;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
swap(&arr[i+1],&arr[high]);
return (i+1);
}

void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
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
	int *arr,i,n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%100;
		printf("%d\t",arr[i]);
	}
	quicksort(arr,0,n-1);
	printf("\n");
	printarr(arr,n);
	printf("\n");
}