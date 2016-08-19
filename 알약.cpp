//#include <stdio.h>
//long long int arr[31] = { 1,1,2 };
//int main()
//{
//	int i = 0, j;
//
//	for (i = 3; i < 31; i++)
//	{
//		for (j = 0; j < i; j++)
//		{
//			arr[i] = (arr[i] + (arr[j] * arr[i - j - 1]));
//		}
//	}
//	while(1)
//	{
//		int n;
//		scanf("%d", &n);
//		if (!n)break;
//		printf("%lld\n", arr[n]);
//	}
//	
//	return 0;
//}