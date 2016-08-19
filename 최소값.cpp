#include <stdio.h>
#define MAX 100000
#define max(a,b) (a>b)?(a):(b)
#define min(a,b) (a<b)?(a):(b)
#define INF 1000000001
int tree[MAX * 3];
int N, M;
void update(int node, int start, int end, int edge, int value)
{
	if (edge < start || end < edge)
		return;
	else if (start == end && start == edge)
	{
		tree[node] = value;
	}
	else
	{
		update(node * 2, start, (start + end) / 2, edge, value);
		update(node * 2 + 1, (start + end) / 2 + 1, end, edge, value);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}
int get(int node, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return INF;
	else if (left <= start && end <= right)
		return tree[node];
	else
	{
		int a = get(node * 2, start, (start + end) / 2, left, right);
		int b = get(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
		return min(a,b);
	}
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		int p;
		scanf("%d", &p);
		update(1, 0, N - 1, i, p);
	}
	for (i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", get(1,0,N-1,a-1,b-1));
	}
	return 0;
}