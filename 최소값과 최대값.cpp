#include <stdio.h>
#define MAX 100000
#define max(a,b) (a>b)?(a):(b)
#define min(a,b) (a<b)?(a):(b)
#define INF 1000000001
typedef struct Node {
	int m;
	int M;
}Node;
Node tree[MAX * 3];
int N, M;
void update(int node, int start, int end, int edge,int value)
{
	if (edge < start || end < edge)
		return;
	else if (start == end && start == edge)
	{
		tree[node].m = tree[node].M = value;
	}
	else
	{
		update(node * 2, start, (start + end) / 2, edge, value);
		update(node * 2 + 1, (start + end) / 2 + 1, end, edge, value);
		tree[node].m = min(tree[node * 2].m, tree[node * 2 + 1].m);
		tree[node].M = max(tree[node * 2].M, tree[node * 2 + 1].M);
	}
}
Node get(int node, int start, int end, int left, int right)
{
	Node tmp;
	tmp.m = INF;
	tmp.M = 0;
	if (right < start || end < left)
		return tmp;
	else if (left <= start && end <= right)
		return tree[node];
	else
	{
		Node a = get(node * 2, start, (start + end) / 2, left, right);
		Node b = get(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
		tmp.m = min(a.m, b.m);
		tmp.M = max(a.M, b.M);
		return tmp;
	}
		
}
int main()
{
	int i, j;
	scanf("%d %d", &N,&M);
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
		Node tmp = get(1, 0, N - 1, a - 1, b - 1);
		printf("%d %d\n", tmp.m,tmp.M);
	}
	return 0;
}