#include <stdio.h>
int N, M;
int dst[101][101];
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int i, j, k;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		if (!dst[a][b])
			dst[a][b] = w;
		else
			dst[a][b] = min(dst[a][b], w);
	}
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (i != k && j != k && i != j) // i - > j k ∞Ê¿Ø
				{
					if (dst[i][k] && dst[k][j])
					{
						if (dst[i][j])
						{
							dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
						}
						else
						{
							dst[i][j] = dst[i][k] + dst[k][j];
						}
					}
				}
			}
		}
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			printf("%d ", dst[i][j]);
		}
		printf("\n");
	}
	return 0;
}