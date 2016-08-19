#include <stdio.h>
#define MIN(a,b) (a<b)?(a):(b)
#define DST(a,b) (a>b)?(a-b):(b-a)
int main()
{
	int dp[256][256] = { 0, };  //[i][j] i ~ j 까지 토너먼트경기를 했을 때 가장 최소 비용을 저장
	int who[256][256] = { 0, }; //[i][j] i ~ j 사이 가장 랭킹이 높은 번호를 저장
	int N;
	int i, j, k;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &who[i][i]);
	}
	for (i = 0; i < N; i++) //대각선순서로 볼 때 간격의 크기
	{
		for (j = 0; j + i < N; j++) // dp[j][i+j] // j 부터 i + j 까지 팀이 있을때의 최적값
		{
			for (k = 0; k < i; k++) // dp[j][i + j] 의 최적값을 찾기 위해 [j][j + k] ~ [j + k + 1][i + j] (k 값에 변화를 주어 중간의 값을 다 탐색함)
			{
				int p = DST(who[j][j + k], who[j + k + 1][i + j]); // 두쪽 토너먼트에서 올라온 사람끼리 붙었을 때 발생하는 비용
				if (!who[j][i+j] || dp[j][i + j] > dp[j][j + k] + dp[j + k + 1][i + j] + p) // 아직 경기 비교해본적이 없거나 비용이 더 작을 경우(who[j][i+j]의 조건은
				{																			// 최초 dp[j][i+j]의 값이 초기화 되어있기 때문에
					dp[j][i + j] = dp[j][j + k] + dp[j + k + 1][i + j] + p;					// 최적일 경우 갱신
					who[j][i + j] = MIN(who[j][j + k], who[j + k + 1][i + j]);				// 랭킹이 높은 번호 저장
				}
			}
		}
	}
	printf("%d", dp[0][N - 1]);
	return 0;
}