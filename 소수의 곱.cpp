#include <stdio.h>
#define INF 9876543210000
int arr[101];
int n, k;
long long int queue[101][100001];
int front[101];
int rear[101];
int size;
int main()
{
	int i = 0, idx = 0;
	long long int x;
	scanf("%d %d", &n,&k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		queue[i][rear[i]++] = arr[i];
	}
	for (i = 0; i < k; i++)
	{
		int idx = 0;
		for (int j = 1; j < n; j++)
		{
			if (queue[idx][front[idx]] > queue[j][front[j]])
			{
				idx = j;
			}
		}
		x = queue[idx][front[idx]++];
		for (idx; idx < n; idx++)
		{
			queue[idx][rear[idx]++] = arr[idx] * x;
		}
	}
	printf("%lld", x);
	return 0;
}