#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.c"
#include "adminFile.c"

// enum ERROR_CODES
// {
// 	BAD_ARGUMENT = 400,
// 	PROC_NOT_FOUND = 404,
// 	BAD_FLAG = 401,
// };
//main function
int main(int argc, char *argv[])
{

	if (argc == 2)
	{
		if (atoi(argv[1]) == 0)
		{
			fprintf(stderr, "Error:%d\n", BAD_ARGUMENT);
			printf("Invalid option: %s\n", argv[1]);
			printf("Maybe you wanted to do some of the following: \n");
			printf("* Enter a process code in numeric format \n ");
			printf("* Add a PID or a list of PIDs to the following command options:\n	 -l for list mode or -r for report mode  \n");
			exit(BAD_ARGUMENT);
		}
		char *buf = load_content_file(argv[1]);
		printf("%s", show_description_only_process(buf));
	}
	if (argc > 2)
	{
		if (compare_str(argv[1], "-l"))
		{
			printf("%s", list_info(argc, argv));
		}
		else if (compare_str(argv[1], "-r"))
		{
			write_file(argc, argv);
		}
		else
		{
			fprintf(stderr, "Error:%d\n", BAD_FLAG);
			printf("invalid option %s\n", argv[1]);
			printf("you can use -l for list mode or -r for report mode \n");
			exit(BAD_FLAG);
		}
	}

	// if (argc > 2)
	// {
	// 	if (argv[1][0] == '-')
	// 	{
	// 		if ((argv[1][1] == 'l'))
	// 		{
	// 			printf("%s", list_info(argc, argv));
	// 		}
	// 		else if (argv[1][1] == 'r')
	// 		{
	// 			write_file(argc, argv);
	// 		}
	// 		// else if (argv[1][1] == 'h')
	// 		// {
	// 		// 	printf("Ayuda para el comando\n");
	// 		// 	exit(0);
	// 		// }
	// 		else
	// 		{
	// 			printf("invalid option -- %c\n", argv[1][1]);
	// 			printf("you can use -l for list mode or -r for report mode \n");
	// 			fprintf(stderr, "Error:%d\n", BAD_ARGUMENT);
	// 			exit(2);
	// 		}
	// 	}
	// }

	// if(argc == 2)
	// {

	// 	// Mostrar información de un solo proceso (CASO 1)
	// 	char *buf = load_content_file(argv[1]);
	// 	printf("%s", show_description_only_process(buf));
	// }

	return 0;
}
