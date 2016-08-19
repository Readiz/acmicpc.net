#include <stdio.h>
int main()
{
	int n;
	int dp[1001] = { 0 , 1,3 };
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 2] * 2 + dp[i - 1])%10007;
	}
	printf("%d", dp[n]);
	return 0;
}