#include <stdio.h>
#define INF 987654321
int arr[101][101];
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int dst(int a, int b)
{
	return a > b ? a - b : b - a;
}
int main()
{
	int iCount;
	int testcase;
	scanf("%d", &testcase);
	for (iCount = 0; iCount < testcase; iCount++)
	{
		int dp[101][101][11] = { 0, };
		int move[101][101][11] = { 0, };
		int check[101][101] = { 0, };
		int N, M, K, i, j;
		scanf("%d %d %d", &M, &N, &K);
		for (i = 0; i <= N; i++)
		{
			for (j = 0; j <= M; j++)
			{
				int tmp;
				scanf("%d", &tmp);
				if (tmp < 0)
				{
					check[i][j] = 1;
					tmp = -tmp;
				}
				arr[i][j] = tmp;
				for (int k = 0; k <= 10; k++)
				{
					dp[i][j][k] = INF;
				}
			}
		}
		int floor = 0;
		move[0][0][0] = 1;
		dp[0][0][0] = 0;
		for (j = 1; j <= M; j++)
		{
			if (check[0][j] && floor < 10)
			{	
				if (move[0][j - 1][floor])
				{
					floor = floor + 1;
					dp[0][j][floor] = dp[0][j - 1][floor - 1] + dst(arr[0][j], arr[0][j - 1]);
					move[0][j][floor] = 1;
				}
			}
			else
			{
				if (move[0][j - 1][floor])
				{
					dp[0][j][floor] = dp[0][j - 1][floor] + dst(arr[0][j], arr[0][j - 1]);
					move[0][j][floor] = 1;
				}
			}
		}
		floor = 0;
		for (i = 1; i <= N; i++)
		{
			if (check[i][0] && floor < 10)
			{
				if (move[i - 1][0][floor])
				{
					floor = floor + 1;
					dp[i][0][floor] = dp[i - 1][0][floor - 1] + dst(arr[i][0], arr[i - 1][0]);
					move[i][0][floor] = 1;
				}
			}
			else
			{
				if (move[i - 1][0][floor])
				{
					dp[i][0][floor] = dp[i - 1][0][floor] + dst(arr[i][0], arr[i - 1][0]);
					move[i][0][floor] = 1;
				}
			}
		}
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				int floor = check[i][j];
				for (int k = 0; k <= 10; k++)
				{
					if (k == 10)
					{
						floor = 0;
					}
					if (move[i - 1][j][k])
					{
						dp[i][j][k + floor] = min(dp[i][j][k + floor], dp[i - 1][j][k] + dst(arr[i][j], arr[i - 1][j]));
						move[i][j][k + floor] = 1;
					}
					if (move[i][j - 1][k])
					{
						dp[i][j][k + floor] = min(dp[i][j][k + floor], dp[i][j - 1][k] + dst(arr[i][j], arr[i][j - 1]));
						move[i][j][k + floor] = 1;
					}
				}
			}
		}
		int ret = INF;
		for (int k = K; k <= 10; k++)
		{
			if (move[N][M][k])
				ret = min(ret, dp[N][M][k]);
		}
		printf("Case #%d\n", iCount + 1);
		printf("%d\n", ret);

	}
	return 0;
}