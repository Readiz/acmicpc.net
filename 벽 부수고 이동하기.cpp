#include <stdio.h>
typedef struct Node {
	int x;
	int y;
	int c;
	int flag;
}Node;
int n, m;
int arr[1002][1002];
int check[1002][1002][2];
int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
int front, rear;
Node queue[1000002];
void push(int x, int y, int c, int flag)
{
	queue[rear].x = x;
	queue[rear].y = y;
	queue[rear].c = c;
	queue[rear++].flag = flag;
}
void pop(int *x, int *y, int *c, int *flag)
{
	*x = queue[front].x;
	*y = queue[front].y;
	*c = queue[front].c;
	*flag = queue[front++].flag;
}
int result(int a, int b)
{
	if (a && b)
		return a < b ? a : b;
	else if (a)
		return a;
	else if (b)
		return b;
	else
		return -1;
}
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	for (i = 0; i <= n + 1; i++)
	{
		arr[i][0] = arr[i][m + 1] = 2;
	}
	for (j = 0; j <= m + 1; j++)
	{
		arr[0][j] = arr[n + 1][j] = 2;
	}
	push(1, 1, 1, 0);
	check[1][1][0] = check[1][1][1] = 1;
	while (front != rear)
	{
		int x, y, c, flag;
		pop(&x, &y, &c, &flag);
		for (int k = 0; k < 4; k++)
		{
			if (arr[x + dir[k][0]][y + dir[k][1]] != 2) //갈 수 있는 점
			{
				if (arr[x + dir[k][0]][y + dir[k][1]] && !flag && !check[x + dir[k][0]][y + dir[k][1]][1])
				{
					check[x + dir[k][0]][y + dir[k][1]][1] = c + 1;
					push(x + dir[k][0], y + dir[k][1], c + 1, 1);
				}
				else if (!arr[x + dir[k][0]][y + dir[k][1]])
				{
					if (!flag)
					{
						if (!check[x + dir[k][0]][y + dir[k][1]][0])
						{
							check[x + dir[k][0]][y + dir[k][1]][0] = c + 1;
							push(x + dir[k][0], y + dir[k][1], c + 1, 0);
						}
					}
					else 
					{
						if (!check[x + dir[k][0]][y + dir[k][1]][1])
						{
							check[x + dir[k][0]][y + dir[k][1]][1] = c + 1;
							push(x + dir[k][0], y + dir[k][1], c + 1, 1);
						}
					}
				}
			}
		}
	}
	printf("%d", result(check[n][m][0], check[n][m][1]));
	return 0;
}