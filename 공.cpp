#include <stdio.h>
int main()
{
	int M;
	int x = 1;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == x)
			x = b;
		else if (b == x)
			x = a;
	}
	printf("%d", x);
	return 0;
}