#include <stdio.h>
int n;
char arr[7][7];
int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
int check[7][7];
typedef struct Node {
	int x;
	int y;
};
Node A[7];
Node queue[7];
int front, rear;
int use[7][7];
int step;
void push(int x, int y)
{
	queue[rear].x = x;
	queue[rear].y = y;
	rear++;
}
void pop(int *x, int *y)
{
	*x = queue[front].x;
	*y = queue[front].y;
	front++;
}
int count;
void f(int index,int c,int Y)
{
	if (Y > 3)return;
	if (c == 7)
	{
		front = rear = 0;
		step++;
		push(A[0].x, A[0].y);
		use[A[0].x][A[0].y] = step;
		while (front != rear)
		{
			int p, q;
			pop(&p, &q);
			use[p][q] = step;
			for (int k = 0; k < 4; k++)
			{
				if (check[p + dir[k][0]][q + dir[k][1]] == 1 && use[p + dir[k][0]][q + dir[k][1]] != step)
				{
					use[p + dir[k][0]][q + dir[k][1]] = step;
					push(p + dir[k][0], q + dir[k][1]);
				}
			}
		}
		if (rear == 7)
		{
			count++;
		}
		return;
	}
	for (index; index < 25; index++)
	{
		int p = (index / 5) + 1;
		int q = (index % 5) + 1;
		if(!check[p][q])
		{
			check[p][q] = 1;
			A[c].x = p;
			A[c].y = q;
			f(index + 1, c + 1, Y + (arr[p][q] == 'Y'));
			check[p][q] = 0;
		}
		if (!c)check[p][q] = 2;
	}
	return;
}
int main()
{
	int i;
	n = 5;
	for (i = 1; i <= 5; i++)
	{
		arr[i][0] = ' ';
		scanf("%s", arr[i]+1);
	}
	f(0, 0, 0);
	printf("%d", count);
	return 0;
}