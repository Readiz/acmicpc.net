#include <stdio.h>
int main()
{
	int head[101] = { 0, };
	int N,M;
	int i, j;
	int a, b;
	scanf("%d", &N);
	scanf("%d %d", &a, &b);
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		head[q] = p;
	}
	int dst[101] = { 0, };
	int amove = 0, bmove = 0;
	int p = a, q = b;
	while (head[p]) // a�� ����鿡 ���� �̵��� �Ÿ��� ��� ���
	{
		p = head[p];
		dst[p] = ++amove;
		if (p == b)
		{
			printf("%d", amove);
			return 0;
		}
	} // p ���� ���� b�� ������ ���Ͽ���
	while (head[q])
	{
		q = head[q];
		bmove++;
		if (dst[q] || q == a) //b�� ������ a �̰ų� b�� ����� a�� ���������� ������ ��(������ �Ǵ� ��� �� ������ �ִܰŸ� ����)
		{
			printf("%d", dst[q] + bmove);
			return 0;
		}
	}
	printf("-1");
	return 0;
}