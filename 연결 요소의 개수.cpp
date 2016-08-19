#include <stdio.h>
#include <vector>
using namespace std;
int N, M;
vector <int>con[1001];
vector <int>check(1001);
void f(int p)
{
	check[p] = 1;
	for (int i = 0; i < con[p].size(); i++)
	{
		int q = con[p][i];
		if (!check[q])
			f(q);
	}
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		con[a].push_back(b);
		con[b].push_back(a);
	}
	int ret = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!check[i])
		{
			f(i);
			ret++;
		}
	}
	printf("%d", ret);
	return 0;
}