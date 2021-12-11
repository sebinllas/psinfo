#include <stdio.h>
#include <stdlib.h>
#include "str.c"
#include "adminFile.c"

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

	if (argc > 2)
	{
		if (argv[1][0] == '-')
		{
			if ((argv[1][1] == 'l'))
			{
				print_list(argc, argv);
			}
			else if(argv[1][1] == 'r'){
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
	}else{
		// Mostrar información de un solo proceso (CASO 1)
		char *buf = load_content_file(argv[1]);
		printf("%s", show_description_only_process(buf));
	}

	return 0;
}
