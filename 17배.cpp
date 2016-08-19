#include <stdio.h>
#define MAX(a,b) (a>b)?(a):(b);
char A[1010];
int B[1010];
void length(int *p)
{
	while (A[*p] != '\0')(*p)++;
}
int main()
{
	int n;
	int i, j,l = 0;
	scanf("%s", A);
	length(&l);
	int sl=0,el = 0;
	for (i = l - 1; i >= 0 ; i--)
	{
		if (A[i]=='1')
		{
			B[l - (i + 1)] += 1;
			B[l - i + 3] += 1;
			sl = l - i + 3;
		}
	}
	for (i = 0; i <= sl; i++)
	{
		el = MAX(el, i);
		if (B[i])
		{
			if (B[i] / 2)
			{
				B[i + (B[i] / 2)] += 1;
				el = MAX(el, i + (B[i] / 2));
			}
			B[i] = B[i] % 2;
			
		}
	}
	while (!B[el] && el>=0)el--;
	if (el < 0)printf("0");
	while (el>=0)
	{
		printf("%d", B[el--]);
	}
	return 0;
}