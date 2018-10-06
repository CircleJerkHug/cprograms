#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n;
	printf("Enter the size of array");
	scanf("%d",&n);
	int a[n][n],b[n][n],c[n][n],i,j,k;
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			printf("Enter the element a[%d][%d]\n",i,j);
			scanf("%d",&a[i][j]);
			}
		}
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			printf("Enter the element b[%d][%d]\n",i,j);
			scanf("%d",&b[i][j]);
			}
		}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=0;
			for(k=0;k<n;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];	
			}
		}
	}
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
		{
			printf("%d\t",c[i][j]);
		}
	printf("\n");
	}
}

	
