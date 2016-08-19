//#include <stdio.h>
//#define MAX 1<<17
//#define INF 987654321
//int cost[17][17];
//int arr[MAX]; // i,j   j상태에서 i를 키려고 할 때
//int n, p;
//char state[17];
//int min(int a, int b)
//{
//	return a < b ? a : b;
//}
//int main()
//{
//	int i, j,result = INF;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= n; j++)
//		{
//			scanf("%d", &cost[i][j]);
//		}
//	}
//	scanf("%s", state);
//	scanf("%d", &p);
//	for (j = 0; j < MAX; j++) {
//		arr[j] = INF;
//	}
//	int cur = 0,cnt = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (state[i] == 'Y') {
//			cur += 1 << i;
//			cnt++;
//		}
//	}
//	if (cnt >= p)
//	{
//		printf("0");
//		return 0;
//	}
//	arr[cur] = 0;
//	int index = 1 << n;
//	for (i = cur; i < index; i++)
//	{
//		int ct = INF,count = 0;
//		for (j = 1; j <= n; j++)
//		{
//			if (i & (1 << (j - 1))) // 켜져있는 발전소에 대하여
//			{
//				count++;
//				for (int k = 1; k <= n; k++)
//				{
//					if (/*cost[j][k] &&*/ !(i & (1 << (k - 1)))) // ☆☆ 비용이 0 인 경우도 포함!
//					{
//						arr[i + (1 << (k - 1))] = min(arr[i + (1 << (k - 1))], arr[i] + cost[j][k]);
//					}//i 상태에서 j로 k를 켬
//				}
//			}
//		}
//		if (count >= p) //p개 이상 켜져있을 때
//			result = min(result, arr[i]);
//	}
//	printf("%d", result != INF ? result : -1);
//	return 0;
//}