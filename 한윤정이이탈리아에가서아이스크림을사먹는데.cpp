//#include <stdio.h>
//char arr[1001];
//int length(char *x) {
//	int index = 0;
//	while (x[index] != '\0')index++;
//
//	return index;
//}
//int main()
//{
//	scanf("%s", arr);
//
//	int l = length(arr);
//	int cnt = 0;
//	int q = l - 1;
//	for (int p = 0; p < q;)
//	{
//		if (arr[p] == arr[q]) {
//			p++, q--;
//		}
//		else {
//			cnt++;
//			p = cnt;
//			q = l - 1;
//		}
//	}
//	printf("%d", l + cnt);
//	return 0;
//}