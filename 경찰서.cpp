//#include <stdio.h>
//#define INF 987654321
//int cost[1001];
//int check[1001];
//int arr[1001][1001];
//int selected[1001];
//int cnt;
//int min;
//int n;
//void f(int index,int type)
//{
//	check[index] = 1;
//	for (int i = 0; i < n; i++)
//	{
//		if ((type? arr[i][index] : arr[index][i]) && !check[i])
//		{
//			f(i,type);
//		}
//	}
//	if (!type)
//		selected[cnt++] = index;
//	else
//		min = min < cost[index] ? min : cost[index];
//}
//int main()
//{
//	int i, j,result = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++) { scanf("%d", &cost[i]); }
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%1d", &arr[i][j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		if (!check[i])f(i,0);
//	}
//	for (i = 0; i < n; i++) { check[i] = 0; }
//	for (i = 0; i < n; i++)
//	{
//		int p = selected[n-i-1];
//		if (!check[p])
//		{
//			min = INF;
//			f(p, 1);
//			result += min;
//		}
//	}
//	printf("%d", result);
//
//	return 0;
//}