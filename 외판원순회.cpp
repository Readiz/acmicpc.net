//#include <stdio.h>
//#define INF 987654321
//int cost[17][17];
//int dp[17][1 << 17];
//int n;
//int min(int a, int b)
//{
//	return a < b ? a : b;
//}
//int f(int index, int cur)
//{
//	if (cur == (1 << n) - 1)
//	{
//		if (index == 1)
//			return 0;
//		else
//			return INF;
//	}
//	else if (index == 1 && cur)return INF;
//	int ret = dp[index][cur];
//	if (ret != -1)return ret;
//
//	ret = INF;
//	for (int i = 1; i <= n; i++)
//	{
//		if (!(cur & 1 << (i-1)) && cost[index][i])
//		{
//			ret = min(ret, cost[index][i] + f(i, cur + (1 << (i-1))));
//		}
//	}
//	dp[index][cur] = ret;
//	return ret;
//}
//int main()
//{
//	int i, j;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= n; j++)
//		{
//			scanf("%d", &cost[i][j]);
//		}
//	}
//	for (i = 0; i <= n; i++)
//	{
//		for (j = 0; j <= 1<< n; j++)
//		{
//			dp[i][j] = -1;
//		}
//	}
//	printf("%d", f(1, 0));
//	return 0;
//}