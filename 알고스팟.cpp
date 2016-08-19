#include <stdio.h>
#include <stdlib.h>
#define INF 987654321
typedef struct Node {
	int x;
	int y;
	int w;
	struct Node *link;
}Node;
Node *queue;
int arr[102][102];
int check[102][102];
int dir[4][2] = { -1,0,0,-1,1,0,0,1 };
int n, m;
void insert(int x, int y, int w)
{
	Node *NewNode = (Node*)malloc(sizeof(Node));
	NewNode->x = x;
	NewNode->y = y;
	NewNode->w = w;
	NewNode->link = NULL;
	Node *p = queue;
	while (p->link)
	{
		if (p->link->w > w)
		{
			NewNode->link = p->link;
			p->link = NewNode;
			return;
		}
		p = p->link;
	}
	p->link = NewNode;
}
int main()
{
	int i, j;
	scanf("%d %d", &m, &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	queue = (Node*)malloc(sizeof(Node));
	queue->w = 0;
	queue->link = NULL;
	for (i = 0; i <= m + 1; i++)
	{
		arr[0][i] = arr[n + 1][i] = INF;
	}
	for (i = 0; i <= n + 1; i++)
	{
		arr[i][0] = arr[i][m + 1] = INF;
	}
	insert(1, 1, arr[1][1]);
	check[1][1] = 1;
	Node * p = queue->link;
	while (queue->link)
	{
		p = queue->link;
		queue->link = p->link;
		int x = p->x;
		int y = p->y;
		int w = p->w;
		
		if (x == n && y == m)
		{
			printf("%d", w);
			break;
		}
		for (i = 0; i < 4; i++)
		{
			int X = x + dir[i][0];
			int Y = y + dir[i][1];
			if (!check[X][Y])
			{
				check[X][Y] = 1;
				if (arr[X][Y] != INF)
				{
					insert(X, Y, arr[X][Y]+w);
				}
			}
		}
	}
	return 0;
}