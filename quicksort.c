#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(long int *a, long int *b)
{
	long int temp = *a;
	*a = *b;
	*b = temp;
}

long int partition(long int arr[], long int low, long int high)
{
	long int pivot = arr[low];
	long int i = low-1;
	for(long int j = low; j<= high-1; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return(i+1);
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
	int it = 0;
	double time[10];
	printf("A_size, QuickSort\n");
	
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
		time[it] = ((double)(end-start) / CLOCKS_PER_SEC);
		printf("%li %f\n", n, time[it]);
	}
	
	return 0;
}
