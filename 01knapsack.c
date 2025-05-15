#include <stdio.h>

int max(int a, int b)
{
	return (a>b)?a:b;
}

int knapsack(int W, int wt[], int val[], int n)
{
	int i, w, k[n+1][W+1];
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0 || w==0)
				k[i][w]=0;
			else if(wt[i-1] <= w)
				k[i][w] = max(val[i-1] + k[i-1][w-wt[i-1]], k[i-1][w]);
			else
				k[i][w] = k[i-1][w];
		}
	}
	return k[n][W];
}

int main()
{
	int val[100], wt[100], W, n;
	printf("\nEnter the number of items:");
	scanf("%d",&n);
	printf("\nEnter the values & weights of %d items:\n",n);
	for(int i=0; i<n; i++)
	{
		printf("Enter the value and weight for item %d:",i+1);
		scanf("%d%d",&val[i], &wt[i]);
	}
	printf("\nEnter the knapsack capacity:");
	scanf("%d",&W);
	printf("\nMaximum value that can be obtained: %d\n", knapsack(W, wt, val, n));
	
	return 0;
}
