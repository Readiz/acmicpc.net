//#include <stdio.h>
//#define INF 987654321
//char Text[1001];
//int dp[26][2];
//int abs(int a, int b) {
//	return a > b ? a - b : b - a;
//}
//int min(int a, int b)
//{
//	return a < b ? a : b;
//}
//int main()
//{
//	int start[26];
//	int end[26] = { 0, };//move count
//	int cnt[26] = { 0, };//enter count
//	int index = 0;
//	for (int i = 0; i < 26; i++)
//	{
//		start[i] = -1;
//	}
//	scanf("%s", Text);
//	while (Text[index] != '\0')
//	{
//		int p = Text[index] - 'a';
//		cnt[p]++;
//		if (start[p] < 0) {
//			start[p] = index;
//		}
//		end[p] = index;
//		index++;
//	}
//	int p = 0;
//	for (int i = 0; i < 26; i++)
//	{
//		if (start[i] >= 0)
//		{
//			p = i - 1;
//			while (p >= 0) {
//				if (start[p] >= 0)
//					break;
//				p--;
//			}
//			if (p < 0)
//			{
//				dp[i][0] = cnt[i] + end[i];
//				dp[i][1] = cnt[i] + end[i];
//				start[i] = end[i];
//			}
//			else
//			{
//				dp[i][0] = min(dp[p][0] + abs(end[p], start[i]), dp[p][1] + abs(start[p], start[i]));
//				dp[i][1] = min(dp[p][0] + abs(end[p], end[i]), dp[p][1] + abs(start[p], end[i]));
//				dp[i][0] += cnt[i] + abs(start[i], end[i]);
//				dp[i][1] += cnt[i] + abs(start[i], end[i]);
//			}
//
//		}
//	}
//	p = 25;
//	while (1)
//	{
//		if (start[p] >= 0)break;
//		p--;
//	}
//	printf("%d", min(dp[p][0], dp[p][1]));
//	
//	return 0;
//}