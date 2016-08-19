//#include <stdio.h>
//#include <limits.h>
//char Text[1000001];
//char Pattern[1000001];
//int position[1000001];
//int stack[4001];
//int top = 0;
//int tL, pL;
//int length(int len,char* x)
//{
//	int index = len;
//	while (x[index] != '\n' && x[index] !='\0') {
//		index++;
//	}
//	return index;
//}
//void fail()
//{
//	int i, j;
//	j = 0;
//	position[0] = -1;
//	for (i = 1; i <= pL;i++)
//	{
//		if (Pattern[i] == Pattern[j]) {
//			position[i] = j++;
//		}
//		else {
//			position[i] = j;
//			j = 0;
//		}
//	}
//}
//int main()
//{
//	gets_s(Text);
//	gets_s(Pattern);
//	fail(); // 실패함수 정의
//	for (int i = 0, j = 0; i < tL;) {
//		if (Text[i] == Pattern[j]) {
//			if (j == pL - 1) {
//				stack[top++] = i+2-pL;
//			}
//			i++,j++;
//		}
//		else {
//			j = position[j];
//			if (j < 0) {
//				i++;
//				j = 0;
//			}
//		}
//	}
//	printf("%d\n", top);
//	for (int i = 0; i < top; i++) {
//		printf("%d\n", stack[i]);
//	}
//	return 0;
//}