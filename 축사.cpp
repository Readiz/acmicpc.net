#include <stdio.h>
#define DST 402
#define PLUS 201
int arr[DST+1][DST+1];
int check[DST+1];
int n, m;
int MIN(int a, int b)
{
	return a < b ? a : b;
}
int f(int index,int step)
{
	int flag = 0;
	check[index] = step;
	for (int i = 0; i <= DST; i++)
	{
		if (check[i] != step && arr[index][i])
		{
			if (i == DST)flag = 1;
			else {
				flag = f(i, step);
			}
			if (flag) {
				arr[index][i]--;
				arr[i][index]++;
				break;
			}
		}
	}
	return flag;
}
int main()
{
	int i, j,nn;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		arr[0][i] = 1;
	}
	for (i = 0; i < m; i++)
	{
		arr[i + PLUS][DST] = 1;
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &nn);
		for (j = 0; j < nn; j++)
		{
			int p;
			scanf("%d", &p);
			arr[i][PLUS + p-1] = 1;
		}
	}
	int step = 1;
	while (1)
	{
		int flag = f(0, step++);
		if (!flag)break;
	}
	int sum = 0;
	for (i = 0; i < m; i++)
	{
		if (arr[DST][i+PLUS])sum++;
	}
	printf("%d", sum);
	return 0;
}