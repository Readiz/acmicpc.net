//#include <stdio.h>
//#define MAX 1<<17
//#define INF 987654321
//int cost[17][17];
//int arr[MAX]; // i,j   j���¿��� i�� Ű���� �� ��
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
//			if (i & (1 << (j - 1))) // �����ִ� �����ҿ� ���Ͽ�
//			{
//				count++;
//				for (int k = 1; k <= n; k++)
//				{
//					if (/*cost[j][k] &&*/ !(i & (1 << (k - 1)))) // �١� ����� 0 �� ��쵵 ����!
//					{
//						arr[i + (1 << (k - 1))] = min(arr[i + (1 << (k - 1))], arr[i] + cost[j][k]);
//					}//i ���¿��� j�� k�� ��
//				}
//			}
//		}
//		if (count >= p) //p�� �̻� �������� ��
//			result = min(result, arr[i]);
//	}
//	printf("%d", result != INF ? result : -1);
//	return 0;
//}