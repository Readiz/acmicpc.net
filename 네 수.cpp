#include <stdio.h>
typedef long long int ll;
ll t(ll n)
{
	ll ten = 1;
	while (n)
	{
		n = n / 10;
		ten = ten * 10;
	}
	return ten;
}
int main()
{
	ll a, b, c, d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	printf("%lld", (a *t(b) + b) + (c *t(d) + d));
	return 0;
}