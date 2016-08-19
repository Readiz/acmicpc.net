#include <stdio.h>
#define MAX(a,b) (a > b) ? (a):(b);
int arr[1001][1001];
int dp[1001][1001];
int main()
{
	int n, m;
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			dp[i][j] = MAX(dp[i][j], dp[i - 1][j - 1]);
			dp[i][j] = MAX(dp[i][j], dp[i - 1][j]);
			dp[i][j] = MAX(dp[i][j], dp[i][j - 1]);
			dp[i][j] += arr[i][j];
		}
	}
	printf("%d", dp[n][m]);
	return 0;
}