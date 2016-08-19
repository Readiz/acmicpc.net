//#include <stdio.h>
//int n;
//int A[26];
//int B[26];
//int Al, Bl;
//char Text[11];
//int abs(int a, int b)
//{
//	return a > b ? a - b : b - a;
//}
//int main()
//{
//	int index,result = 0;
//	scanf("%d", &n);
//	scanf("%s", Text);
//	for (index = 0; Text[index] != '\0'; index++)
//	{
//		A[Text[index] - 'A'] ++;
//	}
//	Al = index;
//	for (int i = 1; i < n; i++)
//	{
//		scanf("%s", Text);
//		for (int j = 0; j < 26; j++) { B[j] = 0; }
//		for (index = 0; Text[index] != '\0'; index++)
//		{
//			B[Text[index] - 'A'] ++;
//		}
//		Bl = index;
//		int flag = 1 , first = 2;
//		for (int j = 0; j < 26; j++)
//		{
//			int p = abs(B[j], A[j]);
//			if (p)
//			{
//				if (p > 1 || !first)
//				{
//					flag = 0;
//					break;
//				}
//				first = first - 1;
//			}
//		}
//		if (flag)
//		{
//			if (!first && abs(Al,Bl) )
//			{
//				// X
//			}
//			else
//			{
//				result++;
//			}
//		}
//	}
//	printf("%d", result);
//	return 0;
//}