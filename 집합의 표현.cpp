#include <stdio.h>
int head[1000002];
int find(int x)
{
	while (head[x] != -1)
	{
		x = head[x];
	}
	return x;
}
void set(int x, int p)
{
	int temp;
	while (x != p)
	{
		temp = head[x];
		head[x] = p;
		x = temp;
	}
}
int main()
{
	int n, m;
	int i, j, k;
	int type, a, b, p, q;
	scanf("%d %d", &n, &m);
	for (i = 0; i <= n; i++)
	{
		head[i] = -1;
	}
	for (k = 0; k < m; k++)
	{
		scanf("%d %d %d", &type, &a, &b);
		p = find(a);
		q = find(b);
		if (type)
		{
			if (p != q)printf("NO\n");
			else printf("YES\n");
		}
		else
		{
			if (p != q) {
				set(a, p);
				head[q] = p;
				set(b, p);
			}
		}
	}
	return 0;

}