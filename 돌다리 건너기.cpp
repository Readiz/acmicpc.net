#include <stdio.h>
char base[21];
char A[2][101];
int dp[2][21][101];
int bl, tl;
void length(char *x, int *l)
{
	while (x[*l] != '\0')(*l)++;
}
int main()
{
	int i, j, k;
	scanf("%s", base);
	scanf("%s", A[0]);
	scanf("%s", A[1]);
	length(base, &bl);
	length(A[0], &tl);
	for (i = 0; i < bl; i++)
	{
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < tl; k++)
			{
				if (A[j][k] == base[i])
				{
					if (i == 0)
					{
						dp[j][i][k] = 1;
					}
					if (dp[j][i][k] && i != bl -1)
					{
						int p = (j + 1) % 2;
						for (int r = k + 1; r < tl; r++)
						{
							if (A[p][r] == base[i + 1])
							{
								dp[p][i + 1][r] += dp[j][i][k];
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (i = 0; i < tl; i++)
	{
		for (j = 0; j < 2; j++)
		{
			ans += dp[j][bl - 1][i];
		}
	}
	printf("%d", ans);
	return 0;
}