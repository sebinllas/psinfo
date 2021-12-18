#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.c"
#include "adminFile.c"

//Flujo principal
int main(int argc, char *argv[])
{

	/* 
	validación de número de parametros para indentificar la operación que se quiere realizar
	*/
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
	return 0;
}
