#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(long int *a, long int *b)
{
	long int temp = *a;
	*a = *b;
	*b = temp;
}

long int partition(long int arr[], long int low, long int high)
{
	long int i = low;
	long int j = high;
	long int pivot = arr[low];
	
	while(i<j)
	{
		while(arr[i]<=pivot && i<high)
		{
			i++;
		}
		
		while(arr[j]>pivot && j>low)
		{
			j--;
		}
		
		if(i<j)
		{
			swap(&arr[i], &arr[j]);
		}
	}
	
	swap(&arr[low], &arr[j]);
	
	return j;
}

void quicksort(long int arr[], long int low, long int high)
{
	if(low<high)
	{
		long int pi = partition(arr, low, high);
		quicksort(arr, low, pi-1);
		quicksort(arr, pi+1, high);
	}
}

int main()
{
	long int n = 10000;
	double time[10];
	int it=0;
	printf("A_Size, QuickSort\n");
	
	while(it++<10)
	{
		long int a[n];
		for(int i=0; i<n; i++)
		{
			long int num = rand()%n+1;
			a[i] = num;
		}
		
		clock_t start, end;
		start = clock();
		quicksort(a, 0, n-1);
		end = clock();
		time[it] = ((double)(end-start)/CLOCKS_PER_SEC);
		printf("%li, %f\n", n, time[it]);
		n+=10000;
	}
	return 0;
}
		
