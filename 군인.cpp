#include <stdio.h>
#define MAX 500000
int arr[MAX];
int N, M;

int main()
{
	int i, j,sum = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		int type,who,x;
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d %d", &who, &x);
			sum += x;
			arr[who-1] += x;
		}
		else
		{
			scanf("%d", &x);
			x = x % sum;
			if (x)
			{
				int c = 0;
				for (j = 0; j < N; j++)
				{
					if (c + arr[j] >= x)
					{
						printf("%d\n", j + 1);
						break;
					}
					else
					{
						c += arr[j];
					}
				}
			}
			else
			{
				printf("%d\n", N);
			}
		}
	}
	return 0;
}