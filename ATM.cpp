#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int V, E, P, S;
typedef struct Node {
	int vertex;
	int dir;
}Node;
typedef struct node {
	int vertex;
	int dis;
}node;
bool operator<(const node&a, const node b)
{
	return a.dis < b.dis;
}
vector <Node> con[500001];
vector <Node> sub[500001];
int group[500001];
int check[500001];
int selected[500001];
int top;
int G;
int cost[500001];
int Gcost[500001];
int rest[500001];
int Grest[500001];
int result;
void insert(int a, int b,int dir)
{
	Node temp;
	temp.vertex = b;
	temp.dir = dir;
	con[a].push_back(temp);
}
void subinsert(int a, int b)
{
	Node temp;
	temp.vertex = b;
	temp.dir = Gcost[b];
	sub[a].push_back(temp);
}
int max(int a, int b)
{
	return a > b ? a : b;
}
void f(int index,int dir)
{
	check[index] = dir;
	for (int i = 0; i < con[index].size(); i++)
	{
		Node p = con[index][i];
		if (check[p.vertex]!=dir && p.dir == dir)
		{
			f(p.vertex, dir);
		}
	}
	if (dir)
		selected[top++] = index;
	else
	{
		group[index] = G;
		Gcost[G] += cost[index];
		if (rest[index])Grest[G] = 1;
	}
}
int main()
{
	int i, j;

	scanf("%d %d", &V, &E);
	for (i = 0; i < E; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		insert(a, b, 1);
		insert(b, a, 0);
	}
	for (i = 1; i <= V; i++)
	{
		scanf("%d", &cost[i]);
	}
	scanf("%d %d", &S, &P);
	for (i = 0; i < P; i++)
	{
		int p;
		scanf("%d", &p);
		rest[p] = 1;
	}
	for (i = 1; i <= V; i++)
	{
		if (!check[i])
		{
			f(i, 1);
		}
	}
	for (i = 0; i < V; i++)
	{
		int p = selected[V - i - 1];
		if (check[p])
		{
			f(p, 0);
			G++;
		}
	}
	for (i = 1; i <= V; i++)
	{
		for (j = 0; j < con[i].size(); j++)
		{
			Node p = con[i][j];
			if (p.dir && group[i] != group[p.vertex])
			{
				subinsert(group[i], group[p.vertex]);
			}
		}
	}
	priority_queue<node> pq;
	vector<int>dist(G, 0);
	node temp;
	temp.vertex = group[S];
	temp.dis = 0;
	pq.push(temp);
	while (!pq.empty())
	{
		temp = pq.top();
		pq.pop();
		if (temp.dis < dist[temp.vertex])continue;
		for (i = 0; i < sub[temp.vertex].size(); i++)
		{
			Node cur = sub[temp.vertex][i];
			if (dist[cur.vertex] < dist[temp.vertex] + cur.dir)
			{
				dist[cur.vertex] = dist[temp.vertex] + cur.dir;
				node temp;
				temp.vertex = cur.vertex;
				temp.dis = dist[cur.vertex];
				pq.push(temp);
			}
		}
	}
	for (i = 0; i < G; i++)
	{
		if (Grest[i])
		{
			result = max(result, dist[i]);
		}
	}
	printf("%d", result + Gcost[group[S]]);
	return 0;
}