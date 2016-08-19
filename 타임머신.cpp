#include <stdio.h>
#define INF 987654321
typedef struct Node {
	int s;
	int e;
	int w;
}Node;
int N, M;
Node edge[6000];
int dst[501];
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &edge[i].s, &edge[i].e, &edge[i].w);
	}
	for (i = 2; i <= N; i++)
	{
		dst[i] = INF;
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (dst[edge[j].s] != INF)
			{
				dst[edge[j].e] = min(dst[edge[j].e], dst[edge[j].s] + edge[j].w);
			}
		}
	}
	int flag = 0;
	for (j = 0; j < M; j++)
	{
		if (dst[edge[j].e] > dst[edge[j].s] + edge[j].w)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		printf("-1");
	}
	else
	{
		for (i = 2; i <= N; i++)
		{
			if (dst[i] == INF)
			{
				dst[i] = -1;
			}
			printf("%d\n", dst[i]);
		}
	}
	return 0;
}