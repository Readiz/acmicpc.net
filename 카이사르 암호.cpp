#include <stdio.h>
int main()
{
	char Text[1001];
	scanf("%s", Text);
	for (int i = 0; Text[i] != 0; i++)
	{
		printf("%c", (Text[i]-'A' + 23) % 26 + 'A');
	}
	return 0;
}