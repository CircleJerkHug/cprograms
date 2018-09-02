#include<stdio.h>
#include<time.h>
void merge(int arr[],int l,int m,int r)
{
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;
  int L[n1],R[n2];

  for(i=0;i<n1;i++)
    L[i]=arr[l+i];
  for(j=0;j<n2;j++)
    R[j]=arr[m+1+j];
  i=0;j=0;k=l;
  while(i<n1&&j<n2)
    {
      if(L[i]<=R[j])
	{
	  arr[k]=L[i];
	  i++;
	} 
      else
	{
	  arr[k]=R[j];
	  j++;
	}
      k++;
    }
  while(i<n1)
    {
      arr[k]=L[i];
      i++;
      k++;
    }
  while(j<n2)
    {
      arr[k]=R[j];
      j++;
      k++;
    }
}
void mergeSort(int arr[],int l,int r)
{
  if(l<r)
    {
      int m=(l+r)/2;
      mergeSort(arr,l,m);
      mergeSort(arr,m+1,r);
      merge(arr,l,m,r);
    }
}
void printarray(int arr[],int size)
{
  int i;
  printf("\n");
  for(i=0;i<size;i++)
    {
      printf("%d\t",arr[i]);
    }
}
int main()
{
  clock_t t;
  int arr[100],i,n;
  printf("Enter the number of elements");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      arr[i]=rand()%50;
      printf("%d\t",arr[i]);
    }
  t=clock();
   mergeSort(arr,0,n-1);
   t=clock()-t;
   double d=((double)t)/CLOCKS_PER_SEC;
   printf("\n");
   printf("The sorted array is\n");
  printarray(arr,n);
  printf("\n");
  printf("%f",d);
}

