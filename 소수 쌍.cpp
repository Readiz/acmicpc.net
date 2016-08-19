#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define SOURCE 0
#define TARGET 51
#define EVEN 25
typedef struct Node {
	int v;
	int w;
}Node;
int N;
int prime[2000] = { 1,1,0 };
int weight[52][52];
int even[25];
int odd[25];
int ecnt, ocnt;
int front, rear;
int queue[52];
int prv[52];
int result[25];
int rcnt;
int range;
vector <int> con[52];
void insert(int a, int b)
{
	con[a].push_back(b);
}
void init(int k)
{
	int i, j;
	for (i = 1; i <= range; i++)
	{
		weight[SOURCE][i] = 1;
		weight[i][SOURCE] = 0;
	}
	for (i = 1; i <= range; i++)
	{
		weight[EVEN + i][TARGET] = 1;
		weight[TARGET][EVEN + i] = 0;
	}
	for (i = 1; i <= range; i++)
	{
		for (j = 1; j <= range; j++)
		{
			weight[EVEN + j][i] = 0;
			if (i == 1)
			{
				if (j != k)
				{
					weight[i][EVEN + j] = 0;
				}
				else
				{
					weight[i][EVEN + j] = 1;
				}
			}
			else
			{
				if (j != k)
				{
					weight[i][EVEN + j] = 1;
				}
				else
				{
					weight[i][EVEN + j] = 0;
				}
			}
		}
	}
}
int main()
{
	int i, j;
	for (i = 2; i <= 50; i++)
	{
		if (!prime[i])
		{
			for (j = 2; i * j <= 2000; j++)
			{
				prime[i*j] = 1;
			}
		}
	}
	scanf("%d", &N);
	int type = 0;
	for (i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		if (num & 1)
		{
			odd[ocnt++] = num;
			if (i == 0) type = 1;
		}
		else
		{
			even[ecnt++] = num;
			if (i == 0) type = 0;
		}
	}
	if (ecnt != ocnt)
	{
		printf("-1");
		return 0;
	}
	range = ecnt;

	for (i = 1; i <= range; i++)
	{
		insert(SOURCE, i);
		insert(i, SOURCE);
		for (j = 1; j <= range; j++)
		{
			if (type)
			{
				if (!prime[odd[i - 1] + even[j - 1]])
				{
					insert(i, EVEN + j);
					insert(EVEN + j, i);
				}
			}
			else
			{
				if (!prime[even[i - 1] + odd[j - 1]])
				{
					insert(i, EVEN + j);
					insert(EVEN + j, i);
				}
			}
		}
	}
	for (i = 1; i <= range; i++)
	{
		insert(EVEN + i, TARGET);
		insert(TARGET, EVEN + i);
	}
	for (i = 1; i <= range; i++)
	{
		init(i);
		int cnt = 0;
		while (1)
		{
			int check[52] = { 1, };
			front = rear = 0;
			queue[rear++] = SOURCE;
			while (front != rear)
			{
				int p = queue[front++];
				if (p == TARGET)
				{
					break;
				}
				for (j = 0; j < con[p].size(); j++)
				{
					int q = con[p][j];
					if (!check[q] && weight[p][q])
					{
						check[q] = 1;
						queue[rear++] = q;
						prv[q] = p;
					}
				}
			}
			if (check[TARGET])
			{
				int p = TARGET;
				int q = prv[p];
				cnt = cnt + 1;
				while (p)
				{
					weight[q][p] -= 1;
					weight[p][q] += 1;
					p = q;
					q = prv[q];
				}
			}
			else
				break;
		}
		if (cnt == range)
		{
			if (type)
			{
				result[rcnt++] = even[i - 1];
			}
			else
			{
				result[rcnt++] = odd[i - 1];
			}
		}
	}
	if (rcnt)
	{
		sort(result, result + rcnt);
		for (i = 0; i < rcnt; i++)
		{
			printf("%d ", result[i]);
		}
	}
	else
	{
		printf("-1");
	}

	return 0;
}