#include <stdio.h>
int main()
{
	char temp;
	while (scanf("%c", &temp) != EOF)
	{
		if (temp == '\n')break;
		if ((temp < '0' || temp > '9') && temp != ' ')
		{
			if (temp >= 'a' && temp <= 'z')
				temp = (temp - 'a' + 13) % 26 + 'a';
			else
				temp = (temp - 'A' + 13) % 26 + 'A';
		}
		printf("%c", temp);
	}
	return 0;
}