#include <stdio.h>
int n, m;
char arr[11][12];
char Text[12];
int main()
{
	int testcase;
	int iCount = 0;
	int i, j;
	scanf("%d", &testcase);
	for (iCount = 0; iCount < testcase; iCount++)
	{
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)
		{
			scanf("%s", &Text);
			for (j = 0; j < m; j++)
			{
				arr[i][j] = Text[j];
			}
			arr[i][j] = '\0';
		}
		for (i = 0; i < n; i++)
		{
			printf("%s\n", arr[n - 1 - i]);
		}
	}
	return 0;
}