//#include <stdio.h>
//#include <algorithm>
//using namespace std;
//typedef struct Node {
//	int s;
//	int e;
//}Node;
//bool comp(Node a, Node b)
//{
//	if (a.s < b.s)return true;
//	else return false;
//}
//Node arr[100];
//int dp[100];
//int M = 0;
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d %d", &arr[i].s, &arr[i].e);
//		dp[i] = 1;
//	}
//	sort(arr, arr + n, comp);
//	int cnt = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (arr[i].e > arr[j].e && dp[i] < dp[j] + 1)
//				dp[i] = dp[j] + 1;
//		}
//		M = M > dp[i] ? M : dp[i];
//	}
//	printf("%d", n - M);
//	return 0;
//}