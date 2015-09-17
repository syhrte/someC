#include<stdio.h>
#include<string.h>

#define MAXLEN 10240

int read_file(const char *filename, char *dest, int maxlen)
{
	FILE *file;
	int pos, temp, i;

	file = fopen(filename, "r");
	if (NULL == file)
	{
		fprintf(stderr, "open %s error\n", filename);
		return -1;
	}
	pos = 0;
	for (i = 0, i < MAXLEN - 1; i++)
	{
		temp = fgetc(file);
		if (EOF == temp)
			break;
		dest[pos++] = temp;
	}
	dest[pos] = 0;
	return pos;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "using:./read<filename>\n");
		return -1;
	}
	char buffer[MAXLEN];
	int len = read_file(argv[1], buffer, MAXLEN);

	printf("len:%d\ncontent:\n%s\n", len, buffer);
	return 0;
}