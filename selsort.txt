#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(long int *a, long int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(long int arr[], long int n)
{
	long int i, j, min;
	for(i=0; i<n-1; i++)
	{
		min = i;
		for(j = i+1; j<n; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
				swap(&arr[min], &arr[i]);
			}
		}
	}
}

int main()
{
	long int n = 5000;
	int iteration = 0;
	double time[10];
	printf("A_size, Selection\n");
	
	while(iteration++ < 10)
	{
		long int a[n];
		for(int i=0; i<n; i++)
		{
			long int num = rand()%n+1;
			a[i] = num;
		}
		
		clock_t start, end;
		start = clock();
		selectionSort(a,n);
		end = clock();
		time[iteration] = ((double)(end-start));
		printf("%li, %li\n",n,(long int)time[iteration]);
		n+=500;
	}
	
	return 0;
}
