#include <stdio.h>
#include <vector>
#define NOT 10000
using namespace std;
int N, M;
typedef struct Node {
	int vertex;
	int dir;
}Node;
vector <Node> con[20001];
int group[20001];
int check[20001];
int selected[20001];
int top;
int G;
int abs(int a)
{
	return a > 0 ? a : -a;
}
void insert(int a, int b, int dir)
{
	Node temp;
	temp.vertex = b;
	temp.dir = dir;
	con[a].push_back(temp);
}
void f(int index, int dir)
{
	check[index] = dir;
	for (int i = 0; i < con[index].size(); i++)
	{
		Node p = con[index][i];
		if (check[p.vertex] != dir && p.dir == dir)
		{
			f(p.vertex, dir);
		}
	}
	if (dir)
		selected[top++] = index;
	else
		group[index] = G;
}
int chg(int p)
{
	if (p < 0)
		return abs(p);
	else
		return abs(p) + NOT;
}
int org(int p)
{
	if (p < 0)
		return abs(p) + NOT;
	else
		return abs(p);
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b); // a or b => a-> b
		insert(chg(a), org(b), 1);
		insert(org(b), chg(a), 0);
		insert(chg(b), org(a), 1);
		insert(org(a), chg(b), 0);
	}
	for (i = 1; i <= N; i++)
	{
		if (!check[i])
		{
			f(i, 1);
		}
	}
	for (i = 1; i <= N; i++)
	{
		if (!check[NOT + i])
		{
			f(NOT + i, 1);
		}
	}
	for (i = 0; i < 2 * N; i++)
	{
		int p = selected[2 * N - i - 1];
		if (check[p])
		{
			G++;
			f(p, 0);
		}
	}
	int flag = 1;
	for (i = 1; i <= N; i++)
	{
		if (group[i] == group[NOT + i])
		{
			flag = 0;
			break;
		}
	}
	printf("%d", flag);
	return 0;
}