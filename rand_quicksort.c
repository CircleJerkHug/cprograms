#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int partition(int a[],int p,int r)
{
  int x,i,j,temp,w,min,max;
  min=max=a[p];
  if((r-p)!=1)
    {
      for(i=p;i<=r;i++)
	{
	  if(a[i]>min)
	  min=a[i];
	  if(a[i]>max)
	    max=a[i];
	}
  for(;;)
    {
      srand(time(NULL));
      w=p+rand()%(r-p+1);
      if(a[w]!=min && a[w]!=max)break;
    }
    }
  else
    {
      srand(time(NULL));
      w=p+rand()%(r-p+1);
    }
  temp=a[w];
  a[w]=a[p];
  a[p]=temp;
  x=a[p];
  i=p;
  for(j=p+1;j<=r;j++)
    {
      if(x>=a[j])
	{
	  i++;
	  temp=a[i];
	  a[i]=a[j];
	  a[j]=temp;
	}
    }
  temp=a[i];
  a[i]=x;
  a[p]=temp;
  return i;
}

void printarr(int arr[],int size)
{
  int i;
  for(i=0;i<size;i++)
    {
      printf("%d\t",arr[i]);
    }
  printf("\n");
}


void quicksort(int arr[], int low, int high)
{
  if(low<high)
    {
      int pos=partition(arr,low,high);
      quicksort(arr,low,pos-1);
      quicksort(arr,pos+1,high);
    }
}

int main()
{
  int n,i,*arr;
  printf("Enter the number of elements:\n");
  scanf("%d",&n);
  arr=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    {
      arr[i]=rand()%100;
      printf("%d\t",arr[i]);
    }
  quicksort(arr,0,n-1);
  printf("\n");
  printf("The sorted array is:\n");
  printarr(arr,n);
}
