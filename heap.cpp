#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
	int large=i,l=2*i+1,r=2*i+2;

	if(l<n && arr[l]>arr[large])
		large=l;
	if(r<n && arr[r]>arr[large])
		large=r;
	if(large!=i)
	{
		swap(arr[i], arr[large]);
		heapify(arr,n,large);
	}
}

void heapsort(int arr, int n)
{
	int i;
	for(i==n/2-1;i>=0;i--)
		heapify(arr,n,i);
	for(i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}

void printarr(int arr[], int size)
{
	int i;
	for(i=0;i<=size;i++)
		cout<<arr[i]<<" "; 
	cout<<"\n";
}

void main()
{
	int n,int arr[10];
	cout<<"Enter the number of elements";
	cin>>n;
	for(i=0;i<=n;i++)
	{
		arr[i]=rand()%100;
		cout<<arr[i];
	}
	heapsort(arr,n);
	cout<<"Sorted array:";
	printarr(arr,n);
}