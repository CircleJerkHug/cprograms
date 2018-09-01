#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define l 100

void countsort(int a[],int k, int n)
{
	int c[l],b[l],i,j;
	for(i=0;i<=k;i++)
	{
		c[i]=0;
	}
	for(j=1;j<=n;j++)
	{
		c[a[j]]++;
	}
	for(i=1;i<=k;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(j=n;j>=1;j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]--;
	}

	printf("\nThe sorted array is:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",b[i]);
	}
}

int main()
{
	int arr[l],n,i,k=0;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		arr[i]=rand()%10;
		printf("%d\t",arr);
	}
	/*printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]>k)
		{
			k=arr[i];
		}
	}*/
	countsort(arr,k,n);
	printf("\n");
}