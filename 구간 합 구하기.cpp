#include <stdio.h>
typedef long long int ll;
int N, M, K;
ll tree[(1000000 * 3) + 1];
ll sum(int node,int start,int end,int L,int R)
{
	if (start > R || end < L)
		return 0;
	else if (L <= start && end <= R)
		return tree[node];
	else
		return sum(node * 2, start, (start + end) / 2, L, R) + sum(node * 2 + 1, (start + end) / 2 + 1, end, L, R);
}
ll update(int node, int start, int end, int edge,ll value)
{
	if (edge < start || edge > end)
		return tree[node];
	else if (start == edge &&  edge == end)
	{
		tree[node] = value;
		return tree[node];
	}
	else
	{
		tree[node] = update(node * 2, start, (start + end) / 2, edge, value) + update(node * 2 + 1, (start + end) / 2 + 1, end, edge, value);
		return tree[node];
	}
}
int main()
{
	int i;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < N; i++)
	{
		ll x;
		scanf("%lld", &x);
		update(1, 0, N - 1, i, x);
	}
	for (i = 0; i < M + K; i++)
	{
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1)
		{
			update(1, 0, N - 1, b - 1, c);
		}
		else
		{
			printf("%lld\n", sum(1, 0, N - 1, b - 1, c - 1));
		}
	}
	return 0;
}