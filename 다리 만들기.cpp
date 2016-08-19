#include <stdio.h>
#define INF 987654321
int n;
int arr[102][102];
int check[102][102];
int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
int result;
typedef struct Node {
	int x;
	int y;
	int count;
}Node;
Node queue[10000];
int front, rear;
int min(int a, int b)
{
	return a < b ? a : b;
}
void label(int x, int y,int group)
{
	for (int k = 0; k < 4; k++)
	{
		int p = x + dir[k][0];
		int q = y + dir[k][1];
		if (!check[p][q] && arr[p][q] == 1)
		{
			check[p][q] = group;
			label(p, q, group);
		}
	}
}
void push(int x, int y, int count)
{
	queue[rear].x = x;
	queue[rear].y = y;
	queue[rear++].count = count;
}
Node pop()
{
	return queue[front++];
}
int main()
{
	int i,j,g = 1;
	result = INF;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i <= n + 1; i++)
	{
		arr[i][0] = arr[i][n + 1] = arr[0][i] = arr[n + 1][i] = 2;
	}//Å×µÎ¸®
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (arr[i][j] == 1 && !check[i][j])
			{
				check[i][j] = g;
				label(i, j,g++);
			}
		}
	}
	int step = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (!arr[i][j])
			{
				int flag = 0,G;
				for (int k = 0; k < 4; k++)
				{
					if (arr[i + dir[k][0]][j + dir[k][1]] == 1)
					{
						flag = 1;
						G = check[i + dir[k][0]][j + dir[k][1]];
						break;
					}
				}
				if (flag)
				{
					step++;
					int sflag = 0;
					front = rear = 0;
					push(i, j, 1);
					while (front != rear)
					{
						Node p = pop();
						for (int k = 0; k < 4; k++)
						{
							if (arr[p.x + dir[k][0]][p.y + dir[k][1]] == 1 && check[p.x + dir[k][0]][p.y + dir[k][1]] != G)
							{
								result = min(result, p.count);
								sflag = 1;
								break;
							}
							else if (!arr[p.x + dir[k][0]][p.y + dir[k][1]] && check[p.x + dir[k][0]][p.y + dir[k][1]] != step)
							{
								check[p.x + dir[k][0]][p.y + dir[k][1]] = step;
								push(p.x + dir[k][0], p.y + dir[k][1], p.count + 1);
							}
						}
						if (sflag)break;
					}
				}
			}
		}
	}
	printf("%d", result);
	return 0;
}