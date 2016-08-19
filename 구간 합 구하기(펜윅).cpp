#include <stdio.h>
#define max 1000000
typedef long long ll;
int N, M, K;
ll tree[max + 1];
ll data[max + 1];
void update(int idx,ll value)
{
	while (idx <= N)
	{
		tree[idx] += value;
		idx += (idx & -idx);
	}
}
ll sum(int idx)
{
	ll ret = 0;
	while (idx > 0)
	{
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}
int main()
{
	int i;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 0; i < N; i++)
	{
		ll x;
		scanf("%lld", &x);
		data[i + 1] = x;
		update(i + 1, x);
	}
	for (i = 0; i < M + K; i++)
	{
		int a, b,c;
		ll v;
		scanf("%d", &a);
		if (a == 1)
		{
			scanf("%d %lld", &b, &v);
			update(b,v - data[b]);
			data[b] = v;
		}
		else
		{
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(c) - sum(b-1));
		}
	}
	return 0;
}