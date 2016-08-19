#include <stdio.h>
#include <vector>
using namespace std;
#define SOURCE 0
#define TARGET 5001
#define REV 2500
int n;
int arr[100][100];
int mine[100][100];
int group[100][100][2];
int weight[5002][5002];
int front, rear;
int queue[5001];
int check[5001];
int prv[10001];
int G[2] = { 1,1 };
int dir[2][2] = { 1,1,1,-1 };
vector <int>con[5002];
void insert(int a, int b, int w)
{
	con[a].push_back(b);
	weight[a][b] = w;
}
void label(int x, int y, int k)
{
	while (x >= 0 && y >= 0 && x < n && y < n)
	{
		if (group[x][y][k] || mine[x][y])break;

		group[x][y][k] = G[k];
		x = x + dir[k][0];
		y = y + dir[k][1];
	}
	if (k)
	{
		insert(REV + G[k], TARGET, 1);
		insert(TARGET, REV + G[k], 0);
	}
	else
	{
		insert(SOURCE, G[k], 1);
		insert(G[k], SOURCE, 0);
	}
	G[k]++;
}
void enque(int p)
{
	queue[rear++] = p;
}
void deque(int *p)
{
	*p = queue[front++];
}
int main()
{
	int m;
	int i, j;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		mine[x - 1][y - 1] = 1;//장애물이 있음
	}
	for (int k = 0; k < 2; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (!mine[i][j] && !group[i][j][k])
					label(i, j, k);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (!mine[i][j])
			{
				insert(group[i][j][0], REV + group[i][j][1], 1);
				insert(REV + group[i][j][1], group[i][j][0], 0);
			}
		}
	}
	int step = 0, result = 0;
	while (1)
	{
		int flag = 0, p;
		front = rear = 0;
		enque(0);
		step = step + 1;
		check[0] = step;
		while (front != rear)
		{
			deque(&p);
			if (p == TARGET)
			{
				flag = 1;
				break;
			}
			for (i = 0; i < con[p].size(); i++)
			{
				int q = con[p][i];
				if (check[q] != step && weight[p][q])
				{
					check[q] = step;
					enque(q);
					prv[q] = p;
				}
			}
		}
		if (!flag)
			break;
		else
		{
			result++;
			int q = prv[p];
			while (p)
			{
				weight[q][p] -= 1;
				weight[p][q] += 1;
				p = q;
				q = prv[q];
			}
		}
	}
	printf("%d", result);
	return 0;
}