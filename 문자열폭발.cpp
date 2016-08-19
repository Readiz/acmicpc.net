//#include <stdio.h>
//char arr[1000001];
//int check[1000001];
//char stack[1000001];
//int stackTop = 0;
//char target[37];
//int TextLength = 0;
//int targetLength = 0;
//int top = 0;
//int length(char *x)
//{
//	int i = 0;
//	while (x[i] != '\0')i++;
//	return i;
//}
//int compare()
//{
//	int i = stackTop - targetLength;
//	int j = 0;
//	for (j = 0; j < targetLength; j++)
//	{
//		if (stack[i+j] != target[j])return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int temp = 0;
//	int flag = 0, i;
//	scanf("%s", arr);
//	scanf("%s", target);
//	
//	TextLength = length(arr);
//	targetLength = length(target);
//	for (i = 0; i < TextLength;)
//	{
//		if(!flag && stackTop < targetLength-1)stack[stackTop++] = arr[i++];
//		else
//		{
//			if(!flag)stack[stackTop++] = arr[i];
//			if (compare())
//			{
//				stackTop = stackTop - targetLength;
//
//				flag = 1;
//			}
//			else
//			{
//				i++;
//				flag = 0;
//			}
//		}
//	}
//	if (!stackTop)printf("FRULA");
//	else
//	{
//		for (i = 0; i < stackTop; i++)
//		{
//			printf("%c", stack[i]);
//		}
//	}
//	return 0;
//}