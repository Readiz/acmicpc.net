#include <stdio.h>
typedef long long ll;
#define max 1024
ll arr[max + 1][max + 1];
ll data[max + 1][max + 1];
int N,M;
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}
void update(int row,int idx, ll value)
{
	int col;
	while (row <= N)
	{
		col = idx;
		while (col <= N)
		{
			arr[row][col] += value;
			col += (col & -col);
		}
		row += (row & -row);
	}
}
ll sum(int row,int idx)
{
	ll ret = 0;
	int col;
	while (row > 0)
	{
		col = idx;
		while (col > 0)
		{
			ret += arr[row][col];
			col -= (col & -col);
		}
		row -= (row & -row);
	}
	return ret;
}
int main()
{
	int i, j, k;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%lld", &data[i][j]);
			update(i, j, data[i][j]);
		}
	}
	for (i = 0; i < M; i++)
	{
		int type,a,b,c,d;
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if (d < b)swap(&b, &d);
			printf("%lld\n", sum(c,d) + sum(a-1,b-1) - sum(c,b-1) - sum(a-1,d));
		}
		else
		{
			ll x;
			scanf("%d %d %lld", &a, &b, &x);
			update(a, b, x - data[a][b]);
			data[a][b] = x;
		}
	}
	return 0;
}