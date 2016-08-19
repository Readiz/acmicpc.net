//#include <stdio.h>
//#include <vector>
//using namespace std;
//int V, E;
//typedef struct Node {
//	int vertex;
//	int dir;
//}Node;
//vector <Node> con[500001];
//int group[500001];
//int check[500001];
//int selected[500001];
//int top;
//int G;
//void insert(int a, int b,int dir)
//{
//	Node temp;
//	temp.vertex = b;
//	temp.dir = dir;
//	con[a].push_back(temp);
//}
//void f(int index,int dir)
//{
//	check[index] = dir;
//	for (int i = 0; i < con[index].size(); i++)
//	{
//		Node p = con[index][i];
//		if (check[p.vertex]!=dir && p.dir == dir)
//		{
//			f(p.vertex, dir);
//		}
//	}
//	if (dir)
//		selected[top++] = index;
//	else
//		group[index] = G;
//}
//int main()
//{
//	int i, j;
//	scanf("%d %d", &V, &E);
//	for (i = 0; i < E; i++)
//	{
//		int a, b;
//		scanf("%d %d", &a, &b);
//		insert(a, b, 1);
//		insert(b, a, 0);
//	}
//	for (i = 1; i <= V; i++)
//	{
//		if (!check[i])
//		{
//			f(i, 1);
//		}
//	}
//	for (i = 0; i < V; i++)
//	{
//		int p = selected[V - i - 1];
//		if (check[p])
//		{
//			G++;
//			f(p, 0);
//		}
//	}
//	printf("%d\n", G);
//	for (i = 1; i <= V; i++)
//	{
//		if (!check[i])
//		{
//			for (j = i; j <= V; j++)
//			{
//				if (group[i] == group[j])
//				{
//					check[j] = 1;
//					printf("%d ", j);
//				}
//			}
//			printf("-1\n");
//		}
//	}
//	return 0;
//}