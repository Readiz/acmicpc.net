#include <stdio.h>
using namespace std;
#include <vector>
#define SOURCE 0
#define JOB 1000
#define TARGET 2001
int N, M;
int check[TARGET + 1];
int wt[TARGET + 1][TARGET + 1];
vector<int> con[TARGET + 1];
void push(int a, int b, int w)
{
	wt[a][b] = w;
	con[a].push_back(b);
}
int f(int cur, int step)
{
	check[cur] = step;
	if (cur == TARGET)return 1;
	for (int i = 0; i < con[cur].size(); i++)
	{
		int p = con[cur][i];
		if (check[p] != step && wt[cur][p])
		{
			if (f(p, step))
			{
				wt[cur][p]--;
				wt[p][cur]++;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int i, j,a,t;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &a);
		push(SOURCE, i, 2);
		push(i, SOURCE, 0);
		for (j = 0; j < a; j++)
		{
			scanf("%d", &t);
			push(i, JOB + t, 1);
			push(JOB + t, i, 0);
		}
	}
	for (i = 1; i <= M; i++)
	{
		push(JOB + i, TARGET, 1);
		push(TARGET, JOB + i, 0);
	}
	int ans = 0;
	while (f(0, ans + 1))
	{
		ans++;
	}
	printf("%d", ans);
	return 0;
}