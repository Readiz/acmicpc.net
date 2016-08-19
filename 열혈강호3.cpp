#include <stdio.h>
using namespace std;
#include <vector>
#define SOURCE 0
#define FIR 1
#define SEC 2
#define PEOPLE 3
#define JOB 1003
#define TARGET 2004
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
	int i, j, a, t,k;
	scanf("%d %d %d", &N, &M, &k);
	push(SOURCE, FIR, N);
	push(FIR, SOURCE, 0);
	push(SOURCE, SEC, k);
	push(SEC, SOURCE, 0);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &a);
		push(FIR, PEOPLE + i, 1);
		push(PEOPLE + i, FIR, 0);
		push(SEC, PEOPLE + i, 1);
		push(PEOPLE + i, SEC, 0);
		for (j = 0; j < a; j++)
		{
			scanf("%d", &t);
			push(PEOPLE + i, JOB + t, 1);
			push(JOB + t, PEOPLE + i, 0);
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