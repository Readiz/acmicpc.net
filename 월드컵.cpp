#include <stdio.h>
int arr[6][6];
int score[6][3];
int f(int);
int pick(int,int,int,int);
int f(int index)
{
	int win = 0, lose = 0;
	for (int i = 0; i < 6; i++)
	{
		if (arr[i][index])lose++;
		if (arr[index][i])win++;
	}
	if (win > score[index][0] || lose > score[index][2])return 0;
	if (score[index][0] + score[index][1] + score[index][2] != 5)return 0;
	if (index == 5)
	{
		lose = win = 0;
		for (int i = 0; i < 6; i++)
		{
			win = lose = 0;
			for (int j = 0; j < 6; j++)
			{
				if (arr[i][j])win++;
				if (arr[j][i])lose++;
			}
			if (score[i][0] != win || score[i][2] != lose)return 0;
		}
		return 1;
		return 1;
	}

	int mwin = score[index][0] - win;
	int mlose = score[index][2] - lose;
	if (pick(index, mwin, mlose, 0))
		return 1;

	return 0;
}
int pick(int index, int count,int count2,int type)
{
	for (int i = index + 1; i < 6; i++)
	{
		if (!type) //win
		{
			if ((!arr[index][i] && !arr[i][index]) || !count)
			{
				if(count)arr[index][i] = 1;
				if (count <= 1)
				{
					if (pick(index, 0, count2, 1))
						return 1;
				}
				else
				{
					if (pick(index, count - 1, count2, type))
						return 1;
				}
				arr[index][i] = 0;
			}
		}
		else
		{
			if ((!arr[index][i] && !arr[i][index]) || !count2)
			{
				if(count2)arr[i][index] = 1;
				if (count2 <= 1)
				{
					if (f(index + 1))
						return 1;
				}
				else
				{
					if (pick(index, count, count2 - 1, type))
						return 1;
				}
				arr[i][index] = 0;
			}
		}
	}
	return 0;
}
int main()
{
	int i, j, k;
	for (k = 0; k < 4; k++)
	{
		for (i = 0; i < 6; i++)
		{
			for (j = 0; j < 6; j++)
			{
				arr[i][j] = 0;
			}
			for (j = 0; j < 3; j++)
			{
				scanf("%d", &score[i][j]);
			}
		}
		printf("%d ", f(0));
	}
	return 0;
}