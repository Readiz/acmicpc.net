#include <stdio.h>
int a, b, N, k;
int main()
{
	setbuf(stdout, NULL);
	int iCount = 0;
	int testcase;
	int i = 0, j = 0;
	int c = 0, mok = 0, temp = 0, flag = 0;
	scanf("%d", &testcase);
	for (iCount = 0; iCount < testcase; iCount++)
	{
		scanf("%d %d %d", &a, &b, &c);
		printf("Case #%d\n", iCount + 1);
		for (i = 0; i < c; i++)
		{
			int flag = 0;
			scanf("%d %d", &N, &k);
			for (j = 1; j <= b; j++)
			{
				for (int r = a + b*k; r <= a*k + b; r++) // a가 운용 가능한 숫자
				{
					int tmp = (N - j) % r;
					if (a <= tmp && tmp <= a*k) // a차례에 tmp만큼을 만들 수 있다
					{
						flag = 1;
						break;
					}
				}
				if (flag)break;
			}
			printf("%c", flag ? 'a' : 'b');
		}
		printf("\n");
	}
	return 0;
}