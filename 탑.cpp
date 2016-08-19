#include <stdio.h>
int N;
int arr[500001];
int top;
typedef struct Node {
	int value;
	int idx;
}Node;
Node stack[500001];
int main()
{
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		while (top && stack[top].value < arr[i])
		{
			top--;
		}
		if (!top)
		{
			printf("%d ", 0);
		}
		else
		{
			printf("%d ", stack[top].idx);
		}
		stack[++top].idx = i + 1;
		stack[top].value = arr[i];
	}
	return 0;
}