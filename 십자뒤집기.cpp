#include <stdio.h>
#define INF 987654321
char state[16][16];
int chgcount[16][16];
int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
int min;
int N;
int MIN(int a, int b)
{
	return a < b ? a : b;
}
int check(int c)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (state[i][j] == '*')return 0;
		}
	}
	min = MIN(c, min);
	return 1;
}
int inpoint(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N)
		return 1;
	else
		return 0;
}
void stchange(int i, int j, int w)
{
	state[i][j] = state[i][j] == '*' ? '.' : '*';
	chgcount[i][j] = chgcount[i][j] + w;
}
int isOk(int i, int j)
{
	if (state[i][j] == '*')return 1;
	if (chgcount[i][j] >= 2)return 0;
	for (int k = 0; k < 4; k++)
	{
		if (inpoint(i + dir[k][0], j + dir[k][1]))
		{
			if (state[i + dir[k][0]][j + dir[k][1]] == '*')return 1;
			else if (chgcount[i + dir[k][0]][j + dir[k][1]] >= 2) return 0;
		}
	}
	return 0;
}
void change(int i, int j, int w)
{
	stchange(i, j, w);
	for (int k = 0; k < 4; k++)
	{
		if (inpoint(i + dir[k][0], j + dir[k][1]))
		{
			stchange(i + dir[k][0], j + dir[k][1], w);
		}
	}
}
void f(int index, int count)
{
	if (index == N*N)
	{
		check(count);
		return;
	}
	f(index + 1, count);

	if (isOk(index / N, index % N))
	{
		change(index / N, index % N, 1);
		f(index + 1, count + 1);
		change(index / N, index % N, -1);
	}
}
int main()
{
	int testcase;
	int iCount;
	scanf("%d", &testcase);
	for (iCount = 0; iCount < testcase; iCount++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%s", state[i]);
		}
		min = INF;
		if (N <= 10)f(0, 0);
		printf("#testcase%d\n", iCount + 1);
		printf("%d\n", min);
	}
	return 0;
}