#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[10000001];
int K = 0;
int n = 0;
int main()
{
	setbuf(stdout, NULL);
	int iCount = 0;
	int testcase;
	int i = 0, end = 0, dX = 0, Count = 0;
	scanf("%d", &testcase);
	for (iCount = 0; iCount < testcase; iCount++)
	{

		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}
		scanf("%d", &K);
		Count = 0, dX = 0, end = 0;
		while (1)
		{
			for (i = 1; arr[dX + i] - arr[dX] <= K; i++)
			{
				if (dX + i == n)
				{
					Count++;
					end = 1;
					break;
				}
			}
			if (i == 1 || end)
			{
				break;
			}
			Count++;
			dX = dX + i - 1;
		}
		if (!end)
		{
			printf("Case #%d\n-1\n", iCount + 1);
		}
		else
		{
			printf("Case #%d\n%d\n", iCount + 1, Count);
		}
	}

	return 0;
}