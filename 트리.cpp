#include <stdio.h>
int a[51];
int c[51];
int d;
int go(int p)
{
	while (p != -1)
	{
		if (p == d)return 0;
		p = a[p];
	}
	return 1;
}
int main()
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		c[a[i]] = 1;
	}
	scanf("%d", &d);
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (!c[i]) // leaf
		{
			ret = ret + go(i);
		}
	}
	printf("%d", ret);
	return 0;
}