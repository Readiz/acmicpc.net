#include <stdio.h>
int check[8];
int arr[8];
int n;
void f(int index)
{
	if (index == n)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = 1;
			arr[index] = i + 1;
			f(index + 1);
			check[i] = 0;
		}
	}
}
int main()
{
	scanf("%d", &n);
	f(0);
	return 0;
}
