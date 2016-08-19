#include <stdio.h>
#include <algorithm>
#include <limits.h>
#define min(a,b) (a<b)?(a):(b)
#define INF 987654321
using namespace std;
int main()
{
	int dp[100001];
	int coin[101];
	int N, K;
	int i, j;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &coin[i]);
	}
	for (j = 0; j <= K; j++)
	{
		dp[j] = INT_MAX;
	}
	sort(coin, coin + N);
	dp[0] = 0;
	for (i = 0; i < N; i++)
	{
		for (j = coin[i]; j <= K; j++)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	printf("%d", (dp[K]==INT_MAX)?-1:dp[K]);
	return 0;
}