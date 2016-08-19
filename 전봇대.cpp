#include <stdio.h>
#define INF 1000000000
typedef long long int ll;
int N;
int arr[100000];
ll dst(ll a, ll b)
{
	return a > b ? a - b : b - a;
}
ll MIN(ll a, ll b)
{
	return a < b ? a : b;
}
ll subsum(ll itv)
{
	ll sum = 0;
	ll p = itv;
	for (int i = 1; i < N; i++)
	{
		sum += dst(arr[i], p);
		p = p + itv;
	}
	return sum;
}
int main()
{
	int i;
	ll ret = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	ll l = 1, r = INF + 1;
	ret = subsum(r);
	while (l <= r)
	{
		ll msum, msum2;
		ll mid = (l + r) / 2;
		msum = subsum(mid);
		msum2 = subsum(mid + 1);
		if (msum < msum2)
			r = mid - 1;
		else
			l = mid + 1;
		ret = MIN(ret, MIN(msum,msum2));
	}
	printf("%lld", ret);
	return 0;
}