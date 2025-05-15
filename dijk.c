#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 99

int d[MAX], p[MAX], visited[MAX];

void dijk(int a[MAX][MAX], int s, int n)
{
	int u,v,i,j,min;
	for(v=0;v<n;v++)
	{
		d[v] = INF;
		p[v] = -1;
		visited[v] = 0;
	}
	
	d[s] = 0;
	
	for(i=0; i<n; i++)
	{
		min = INF;
		for(j=0;j<n;j++)
		{
			if(d[j] < min && visited[j] == 0)
			{
				min = d[j];
				u = j;
			}
		}
		visited[u] = 1;
		
		for(v=0;v<n;v++)
		{
			if((d[u] + a[u][v] < d[v]) && u!=v && visited[v] == 0)
			{
				d[v] = d[u] + a[u][v];
				p[v] = u;
			}
		}
	}
}

void path(int v, int s)
{
	if(p[v] != -1)
		path(p[v],s);
	if(v != s)
		printf("-> %d",v);
}

void display(int s, int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
		if(i!=s)
		{
			printf("%d",s);
			path(i,s);
		}
		if(i!=s)
		{
			printf("=%d",d[i]);
			printf("\n");
		}
	}
}

int main()
{
	int a[MAX][MAX], i, j, n, s;
	printf("\nEnter the number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the weighted matrix:\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	printf("\nEnter the source vertex:");
	scanf("%d",&s);
	dijk(a,s,n);
	printf("The shortest path between source and vertices are:\n",s);
	display(s,n);
	
	return 0;
}
