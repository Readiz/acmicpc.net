#include <stdio.h>
char list[10][9];
int length[10];
int num[26];
int stack[10];
int use[10];
char Text[10];
int top;
int ret;
int n;
int max(int a, int b)
{
	return a > b ? a : b;
}
void len(int i)
{
	int index = 0;
	while (list[i][index] != '\0')index++;
	length[i] = index;
}
void f(int index)
{
	if (index == top)
	{
		for (int i = 0; i < index; i++)
		{
			num[Text[i] - 'A'] = stack[i];
		}
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int ten = 1,bsum = 0;
			if (!num[list[i][0] - 'A'])return;
			for (int j = length[i] - 1; j >= 0; j --)
			{
				bsum += ten * num[list[i][j] - 'A'];
				ten = ten * 10;
			}
			sum += bsum;
		}
		ret = max(ret, sum);
		return;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (use[i] == -1)
			{
				use[i] = 1;
				stack[index] = i;
				f(index + 1);
				use[i] = -1;
			}
		}
	}
}
int main()
{
	int check[26] = { 0, };

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", list[i]);
		len(i);
		for (int j = 0; j < length[i]; j++)
		{
			if (!check[list[i][j] - 'A'])
			{
				check[list[i][j] - 'A'] = 1;
				Text[top++] = list[i][j];
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		use[i] = -1;
	}
	f(0);
	printf("%d", ret);
	return 0;
}