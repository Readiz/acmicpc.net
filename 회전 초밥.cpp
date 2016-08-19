#include <stdio.h>
int n, d, k, c;
int arr[30000];
int check[3001];
int main()
{
	int i, j, max = 0, cnt = 0;
	scanf("%d %d %d %d", &n, &d, &k, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < k; i++)
	{
		if (!check[arr[i]])cnt++;
		
		check[arr[i]]++;
	}
	int flag = 0;
	if (!check[c])flag = 1;
	max = cnt + flag;
	for (i = 0; i < n; i++) // i¹øÂ° ÃÊ¹äÀ» »©°í i+k¹ø¤Š ÃÊ¹äÀ» Æ÷ÇÔ
	{
		flag = 0;
		check[arr[i]]--;
		if (!check[arr[i]])cnt--;
		if (!check[arr[(i+k)%n]])cnt++;
		
		check[arr[(i+k)%n]]++;
		if (!check[c])flag = 1;
		else flag = 0;
		max = max > cnt + flag ? max : cnt + flag;
	}
	printf("%d", max);
	return 0;
}
