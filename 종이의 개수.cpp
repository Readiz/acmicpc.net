#include <stdio.h>
int N;
int arr[2187][2187];
int c[3];
void f(int sx, int sy, int ex, int ey)
{
	int flag = 1;
	for (int i = sx; i < ex; i++)
	{
		for (int j = sy; j < ey; j++)
		{
			if (arr[sx][sy] != arr[i][j])
			{
				flag = 0;
				break;
			}
		}
	}
	if (flag)
	{
		c[arr[sx][sy] + 1] ++;
	}
	else
	{
		int xs = (ex - sx) / 3;
		int ys = (ey - sy) / 3;
		f(sx, sy, sx + xs, sy + ys);
		f(sx, sy + ys, sx + xs, ey - ys);
		f(sx, ey - ys, sx + xs, ey);

		f(sx + xs, sy, sx + 2 * xs, sy + ys);
		f(sx + xs, sy + ys, sx + 2 * xs, ey - ys);
		f(sx + xs, ey - ys, sx + 2 * xs, ey);

		f(ex - xs, sy, ex, sy + ys);
		f(ex - xs, sy + ys, ex, ey - ys);
		f(ex - xs, ey - ys, ex, ey);
	}
}
int main()
{
	int i,j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	f(0, 0, N, N);
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", c[i]);
	}
	return 0;
}