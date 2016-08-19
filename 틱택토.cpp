#include <stdio.h>
int arr[3][3];
char Text[10];
int comp[8][3][2] = { {{0,0},{1,1},{2,2}}, {{ 0,2 }, { 1,1 }, { 2,0 }}, {{ 0,0 }, { 0,1 }, {0,2}},{{1,0},{1,1},{1,2}},{{2,0},{2,1},{2,2}},
{{0,0},{1,0},{2,0}},{{0,1},{1,1},{2,1}},{{0,2},{1,2},{2,2}} };
int main()
{
	int n, i, j,X,O;
	while (1)
	{
		int st[2][3] = { 0, };
		scanf("%s", &Text);
		if (Text[0] == 'e')break;
		X = O = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (Text[i * 3 + j] == 'X')arr[i][j] = 0, X++;
				else if (Text[i * 3 + j] == 'O')arr[i][j] = 1,O++;
				else arr[i][j] = -1;
			}
		}
		int flag = 0;
		if (O == X || O == X - 1)
		{
			O = X = 0;
			for (int k = 0; k < 2; k++) {
				for (i = 0; i < 8; i++) {
					int cnt = 0;
					for (j = 1; j < 3; j++) {
						if (arr[comp[i][0][0]][comp[i][0][1]] == k && arr[comp[i][0][0]][comp[i][0][1]] == arr[comp[i][j][0]][comp[i][j][1]])cnt++;
					}
					if (cnt == 2) {
						if (k)O++;
						else X++;
					}
				}
			}
			if (O && X)flag = 0;
			else if (O || X)flag = 1;
		}
		printf("%s\n", flag ? "valid" : "invalid");
	}
	return 0;
}