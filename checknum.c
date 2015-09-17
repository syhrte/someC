#include<string.h>
#include<stdio.h>

int luhn(const char **cc)
{
	const int m[] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
	int odd = 1, sum = 0;

	for (i = strlen(cc); i--; odd = !odd)
	{
		int digit = cc[i] - '0';
		sum += odd ? digit : m[digit];
	}
	return sum % 10 == 0;
}

int main()
{
	const char *cc[] = {
		"242435646",
		"353677568658567",
		"242657355353464575675",
		"1234567812345670"
	};
	int i;
	for (i = 0; cc[i]; i++)
		print("%16s\t%s\n", cc[i], luhn(cc[i]) ? "ok" : "not ok");
	return 0;
}