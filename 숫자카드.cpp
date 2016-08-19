#include <stdio.h>
#include <algorithm>
#define INF 10000000
using namespace std;
int N,M;
int A[500000];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A, A + N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int t;
		scanf("%d", &t);
		int L = 0, R = N,flag = 0;
		while (L <= R)
		{
			int mid = (L + R) / 2;
			if (A[mid] == t)
			{
				flag = 1;
				break;
			}
			else if (A[mid] < t)
			{
				L = mid + 1;
			}
			else
			{
				R = mid - 1;
			}
		}
		printf("%d ", flag);
	}
	return 0;
}