#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int a[2] = { 1,2 };
	if (n <= 2) printf("%d", n);
	else
	{
		int ret =0;
		for (int i = 3; i <= n; i++)
		{
			ret = (a[0] + a[1])%10007;
			a[0] = a[1];
			a[1] = ret;
		}
		printf("%d", ret);
	}

}