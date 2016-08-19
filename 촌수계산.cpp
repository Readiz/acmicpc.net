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
	while (head[p]) // a의 조상들에 대해 이동한 거리를 모두 기록
	{
		p = head[p];
		dst[p] = ++amove;
		if (p == b)
		{
			printf("%d", amove);
			return 0;
		}
	} // p 진행 도중 b를 만나지 못하였음
	while (head[q])
	{
		q = head[q];
		bmove++;
		if (dst[q] || q == a) //b의 조상이 a 이거나 b의 조상과 a의 공통조상을 만났을 때(만나게 되는 즉시 그 조상은 최단거리 조상)
		{
			printf("%d", dst[q] + bmove);
			return 0;
		}
	}
	printf("-1");
	return 0;
}