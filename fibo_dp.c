//Using dynamic programming for Fibonacci Series
#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
	//extra space to handle case, n=0
	int f[n+2],i;
	f[0]=0;
	f[1]=1;

	for(i=2;i<=n;i++)
	{
		f[i]=f[i-1]+f[i-2];
	} 
	return f[n];
}

int main()
{
	int n,i;
	printf("Enter the number of terms:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%d\t",fib(i));
	}
	printf("\n");
	return 0;
}