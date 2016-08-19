//#include <stdio.h>
//int cost[3];
//int max = 0;
//int MAX(int a, int b)
//{
//	return a > b ? a : b;
//}
//int min(int a, int b)
//{
//	return a < b ? a : b;
//}
//int main()
//{
//	int n;
//	int a, b, c;
//	int iCount;
//	int testcase;
//	int i,j;
//	scanf("%d", &testcase);
//	for (iCount = 0; iCount < testcase; iCount++)
//	{
//		scanf("%d %d %d", &a, &b, &c);
//		max = 0;
//		for (i = 0; i < 3; i++)
//		{
//			scanf("%d", &cost[i]);
//		}
//		int p = min(a, b);
//		int q = min(b, c);
//		for (i = 0; i <= p; i++)//AB i번
//		{
//			for (j = 0; j <= q; j++)//BC j번
//			{
//				int sum = cost[0] * i;
//				int B = b - i - j;
//				int A = a - i; 
//				if (B >= 0) // b j만큼 사용가능함
//				{
//					sum += cost[1] * j;
//					if (A > 0 && c - j > 0) { // 남은게 있을 때
//						int q = min(A, c - j);
//						sum += cost[2] * q;
//					}
//					max = MAX(sum, max);
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//		printf("%d\n", max);
//	}
//	return 0;
//}