#include <stdio.h>
#define max(a,b) (a>b)?(a):(b);
int main()
{
	int n;
	int arr[1000];
	int dp[1000] = { 0, };
	int i, j,ret = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if(arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ret = max(ret, dp[i]);
	}
	printf("%d", ret);
	return 0;
}