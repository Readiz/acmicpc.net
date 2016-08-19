#include <stdio.h>
int main()
{
	long long int arr[100];
	long long int N;
	int K, Q;
	long long int p = 1;
	int index = 0;
	long long int turn;
	scanf("%lld %d %d", &N, &K, &Q);
	turn = K;
	while (1)
	{
		arr[index] = p;
		if (p > N)break;
		index++;
		p = p + turn;
		turn = turn * K;
	}
	long long int x, y;
	for (int q = 0; q < Q; q++)
	{
		scanf("%lld %lld", &x, &y);
		int layer1 = 0, layer2 = 0, c1 = 0, c2 = 0;
		while (arr[layer1] < x) { layer1++; }
		while (arr[layer2] < y) { layer2++; }
		while (1)
		{
			if (layer1 == layer2)
			{
				if (x == y)
				{
					printf("%d\n", c1 + c2);
					break;
				}
				else
				{
					c1++, c2++;
					layer1--, layer2--;
					x = (x + (K - 2)) / K;
					y = (y + (K - 2)) / K;
				}
			}
			else if (layer1 > layer2)
			{
				c1++, layer1--;
				x = (x + (K - 2)) / K;
			}
			else
			{
				c2++, layer2--;
				y = (y + (K - 2)) / K;
			}
		}
	}
	return 0;
}