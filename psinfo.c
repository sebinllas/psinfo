#include <stdio.h>
#include <stdlib.h>
#include "str.c"

//main function
int main(int argc, char *argv[])
{
	char *dir = calloc(12 + len_str(argv[1]) + 1, 1);
	append_str(dir, "/proc/");
	append_str(dir, argv[1]);
	append_str(dir, "/stat");
	printf("Getting process data from: %s\n", dir);

	FILE *fp;
	fp = fopen(dir, "r");
	if (fp == NULL)
	{
		fputs("File error or non-existent process", stderr);
		exit(1);
	}
	printf("file opnened succesfullt!\n");

	char *buf = calloc(511, 1);
	fgets(buf, 511, fp);

	replace_str(buf, ' ', ',');
	printf("line : %s\n. size: %d\n", buf, len_str(buf));
	printf("line : %s\n", get_word(buf, 0, ','));
	fclose(fp);

	return 0;
}
