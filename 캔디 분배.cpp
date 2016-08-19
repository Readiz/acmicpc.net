#include <stdio.h>
typedef long long int ll;
ll gcd(ll a, ll b)
{
	if (b != 0)
		return gcd(b, a%b);
	else
		return a;
}
int main()
{
	int testcase;
	int iCount;
	int i, j;
	scanf("%d", &testcase);
	for (iCount = 0; iCount < testcase; iCount++)
	{
		ll a, b;
		scanf("%lld %lld", &a, &b);
		if (gcd(a, b) != 1)
		{
			printf("IMPOSSIBLE\n");
		}
		else if (b == 1)
		{
			printf("%lld\n", a + 1);
		}
		else if (a == 1)
		{
			printf("%lld\n", b);
		}
		else
		{
			ll r1, r2, r=0, s1, s2, s, t1, t2, t;
			r1 = a, r2 = b;
			s1 = t2 = 1;
			s2 = t1 = 0;
			while (1)
			{
				ll mok = r1 / r2;
				r = r1 - (mok * r2);
				s = s1 - (mok * s2);
				t = t1 - (mok * t2);
				r1 = r2;
				r2 = r;
				s1 = s2;
				s2 = s;
				t1 = t2;
				t2 = t;
				if (r2 == 1)break;
			}
			while (t <= 0)
			{
				t += a;
			}
			if (t > 1000000000 || t <= 0)
				printf("IMPOSSIBLE\n");
			else
				printf("%lld\n", t);
		}
	}
	return 0;
}