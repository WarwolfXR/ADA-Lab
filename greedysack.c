#include <stdio.h>

int main()
{
	float weight[50], profit[50], ratio[50], totalvalue=0, temp, capacity, amount;
	int n,i,j;
	
	printf("\nEnter the number of items:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter weight and profit for item %d:",i);
		scanf("%f%f", &weight[i], &profit[i]);
	}
	
	printf("\nEnter the capacity of the knapsack:");
	scanf("%f",&capacity);
	
	for(i=0; i<n; i++)
		ratio[i] = profit[i]/weight[i];
	
	for(i=0; i<n; i++)
	for(j=i+1; j<n; j++) 
	
		if(ratio[i]<ratio[j])
		{
				// Swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                // Swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
                // Swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
		}
	
		
	printf("Knapsack problem using Greedy Algorithm:\n");
	for(i=0; i<n; i++)
	{
		if(weight[i]>capacity) break;
		else
		{
			totalvalue = totalvalue + profit[i];
			capacity = capacity - weight[i];
		}
	}
	
	if(i<n) totalvalue = totalvalue + (ratio[i]*capacity);
	printf("\nMaximum value is: %f\n",totalvalue);
	
	return 0;
}	
