#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue <int> pq;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t)
			pq.push(t);
		else
		{
			if (pq.size())
			{
				printf("%d\n",pq.top());
				pq.pop();
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}