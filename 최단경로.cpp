#include <stdio.h>
using namespace std;
#include <queue>
#include <vector>
#define INF 987654321
int V, E, K;
typedef struct Node{
	int e;
	int w;
}Node;
vector <Node> con[20001];
bool operator<(const Node&a, const Node&b)
{
	return a.w > b.w;
}
void insert(int a, int b, int w)
{
	Node temp;
	temp.e = b;
	temp.w = w;
	con[a].push_back(temp);
}
int main()
{
	int i, j;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (i = 0; i < E; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		insert(a, b, w);
	}
	priority_queue <Node> pq;
	vector<int> dst(V + 1, INF);
	Node cur;
	cur.e = K;
	cur.w = 0;
	dst[K] = 0;
	pq.push(cur);
	while (!pq.empty())
	{
		cur = pq.top();
		pq.pop();
		if (dst[cur.e] < cur.w)continue;
		for (i = 0; i < con[cur.e].size(); i++)
		{
			Node q = con[cur.e][i];
			if (dst[q.e] > dst[cur.e] + q.w)
			{
				dst[q.e] = dst[cur.e] + q.w;
				Node temp;
				temp.e = q.e;
				temp.w = dst[q.e];
				pq.push(temp);
			}
		}
	}
	for (i = 1; i <= V; i++)
	{
		if (dst[i] == INF)
		{
			printf("INF\n");
		}
		else
		{
			printf("%d\n", dst[i]);
		}
	}
	return 0;
}