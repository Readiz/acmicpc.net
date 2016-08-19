#include <stdio.h>
#define max 1000000
typedef long long int ll;
int N, M, K;
ll tree[(max * 3) + 1];
ll lazy[(max * 3) + 1];
void update_lazy(int node, int start, int end, int L, int R)
{
	if (lazy[node] != 0)
	{
		tree[node] += ((end - start + 1) * lazy[node]);
		if (start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
ll sum(int node, int start, int end, int L, int R)
{
	update_lazy(node, start, end, L, R);
	if (start > R || end < L)
		return 0;
	else if (L <= start && end <= R)
	{
		return tree[node];
	}
	else
	{
		return sum(node * 2, start, (start + end) / 2, L, R) + sum(node * 2 + 1, ((start + end) / 2) + 1, end, L, R);
	}
}
void update(int node, int start, int end, int L, int R, ll value)
{
	update_lazy(node, start, end, L, R);
	if (start > R || end < L)
		return;
	else if (L <= start && end <= R)
	{
		tree[node] += (value * (end - start + 1));
		if (start != end)
		{
			lazy[node * 2] += value;
			lazy[node * 2 + 1] += value;
		}
		return;
	}
	else
	{
		update(node * 2, start, (start + end) / 2, L, R, value);
		update(node * 2 + 1, (start + end) / 2 + 1, end, L, R, value);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		return;
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
		update(1, 0, N - 1, i, i, x);
	}
	for (i = 0; i < M + K; i++)
	{
		int a, b, d;
		ll c;
		scanf("%d ", &a);
		if (a == 1)
		{
			scanf("%d %d %lld", &b, &d, &c);
			update(1, 0, N - 1, b - 1, d - 1, c);
		}
		else
		{
			scanf("%d %d", &b, &d);
			printf("%lld\n", sum(1, 0, N - 1, b - 1, d - 1));
		}
	}
	return 0;
}