#include <stdio.h>
int main()
{
	int n,c = 2;
	scanf("%d", &n);
	while (n != 1)
	{
		if (n % c == 0)
		{
			printf("%d\n", c);
			n = n / c;
		}
		else
		{
			c = c + 1;
		}
	}
	return 0;
}