#include <stdio.h>
#define INF 987654321
#include <queue>
#include <vector>
typedef struct Node {
	int e;
	int w;
}Node;
bool operator<(const Node&a, const Node&b)
{
	return a.w>b.w;
}
using namespace std;
int N, M;
int main()
{
	int testcase;
	int iCount;
	int i, j;
	scanf("%d", &testcase);
	for (iCount = 0; iCount < testcase; iCount++)
	{
		scanf("%d %d", &N, &M);
		vector <Node> con[1001];
		vector <int>selected(N + 1, 0);
		for (i = 0; i < M; i++)
		{
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			Node temp;
			temp.e = b;
			temp.w = w;
			con[a].push_back(temp);
			temp.e = a;
			con[b].push_back(temp);
		}
		for (i = 1; i <= N; i++) // 정점 i에 대해서
		{
			vector <int>dst(N + 1, INF); // 거리 무한대
			vector <int>cnt[1001];
			dst[i] = 0;
			priority_queue<Node> pq;
			Node temp;
			temp.e = i;
			temp.w = 0;
			pq.push(temp);
			while (!pq.empty())
			{
				Node cur = pq.top();
				pq.pop();
				if (cur.w > dst[cur.e])continue;
				for (j = 0; j < con[cur.e].size(); j++)
				{
					Node target = con[cur.e][j];
					if (dst[cur.e] + target.w < dst[target.e])
					{
						dst[target.e] = dst[cur.e] + target.w;
						cnt[target.e].clear();
						cnt[target.e].push_back(cur.e);

						temp.e = target.e;
						temp.w = dst[target.e];
						pq.push(temp);
					}
					else if (dst[cur.e] + target.w == dst[target.e])
					{
						cnt[target.e].push_back(cur.e);
					}
				}
			}
			for (j = 1; j <= N; j++)
			{
				for (int r = 0; r < cnt[j].size(); r++)
				{
					if (i != cnt[j][r])
					{
						selected[cnt[j][r]] = 1;
					}
				}
			}
		}
		int ret = 0;
		for (i = 1; i <= N; i++)
		{
			if (!selected[i])
				ret++;
		}
		printf("Case #%d\n", iCount + 1);
		if (ret)
		{
			printf("%d ", ret);
			for (i = 1; i <= N; i++)
			{
				if (!selected[i])
					printf("%d ", i);
			}
		}
		else
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}