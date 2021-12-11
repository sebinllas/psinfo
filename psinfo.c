#include <stdio.h>
#include <stdlib.h>
#include "str.c"

//main function
int main(int argc, char *argv[])
{

	enum STATE
	{
		RUNNING = 'R',
		SLEEPING = 'S',
		WAITING = 'D',
		ZOMBIE = 'Z'
	};
	if (argc == 2)
	{

		if (argv[1][0] == '-')
		{
			if ((argv[1][1] == 'l') | (argv[1][1] == 'r'))
			{
				fputs("you must give PID or a list of PIDs\n", stderr);
				exit(1);
			}
			else if (argv[1][1] == 'h')
			{
				printf("Ayuda para el comando\n");
				exit(0);
			}
			else
			{
				printf("invalid option -- %c\n", argv[1][1]);
				exit(0);
			}
		}

		char *path = calloc(14 + len_str(argv[1]) + 1, 1);
		append_str(path, "/proc/");
		append_str(path, argv[1]);
		append_str(path, "/status");
		printf("Getting process data from: %s\n", path);

		FILE *fp;
		fp = fopen(path, "r");
		if (fp == NULL)
		{
			fputs("File error or non-existent process\n", stderr);
			exit(1);
		}

		char *buf = calloc(1500, 1);
		//fgets(buf, 1500, fp);
		fread(buf, 1500, 1, fp);

		printf("file opnened succesfullt!\n");

		//printf("buf : \n%s\n", buf);
		printf("%s\n", get_word(buf, 0, '\n'));
		printf("pid: %s\n", argv[1]);
		printf("%s\n \n", get_word(buf, 2, '\n'));
		printf("%s\n", get_word(buf, 17, '\n'));
		printf("	%s\n", get_word(buf, 27, '\n'));
		printf("	%s\n", get_word(buf, 26, '\n'));
		printf("	%s\n \n", get_word(buf, 28, '\n'));
		printf("%s\n", "context switches:");
		printf("	%s\n", get_word(buf, 54, '\n'));
		printf("	%s\n", get_word(buf, 55, '\n'));
	}

	return 0;
}
