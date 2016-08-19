//#include <stdio.h>
//long long int arr[100001];
//long long int stack[100001][2];
//#define INF 9987654321
//int top = 0;
//int main()
//{
//	int n;
//	int i;
//	long long int max = 0;
//	long long int min = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%lld", &arr[i]);
//	}
//	for (i = 0; i < n; i++)
//	{
//		if (stack[top][0] < arr[i])
//		{
//			stack[++top][0] = arr[i]; // 높이
//			stack[top][1] = i;// 위치
//		}
//		else if(stack[top][0] > arr[i])
//		{
//			min = INF;
//			while (top && stack[top][0] > arr[i]) {
//				int weight = i - stack[top][1];
//				max = max > weight * stack[top][0] ? max : weight * stack[top][0];
//				min = min < stack[top][1] ? min : stack[top][1];
//				top--;
//			}
//			if (stack[top][0] != arr[i])
//			{
//				stack[++top][0] = arr[i];
//				stack[top][1] = min;
//				
//			}
//		}
//	}
//	while (top)
//	{
//		int weight = n - stack[top][1];
//		max = max > weight * stack[top][0] ? max : weight * stack[top][0];
//		top--;
//	}
//	printf("%lld", max);
//	return 0;
//}