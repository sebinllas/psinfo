#include "str.c"
#include <stdio.h>

/* cargar contenido del archivo */
char *load_proc_info(char *pid)
{
    char *path = calloc(14 + len_str(pid) + 1, 1);
    append_str(path, "/proc/");
    append_str(path, pid);
    append_str(path, "/status");

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

    return buf;
}

void print_proc_list(int pc, char *pid[])
{
    for (int i = 2; i < pc; i++)
    {
        char *buf = load_content_file(pid[i]);
        printf("%s", get_short_info(buf, pid[i]));
    }
}

// Mostrar información relacionada a un solo proceso
char *get_long_info(char *buf)
{
    char *info = calloc(300, 1);
    append_str(info, get_word(buf, 0, '\n'));
    append_str(info, "\n");
    append_str(info, get_word(buf, 2, '\n'));
    append_str(info, "\n");
    append_str(info, get_word(buf, 17, '\n'));
    append_str(info, "\n");
    append_str(info, get_word(buf, 27, '\n'));
    append_str(info, "\n");
    append_str(info, get_word(buf, 26, '\n'));
    append_str(info, "\n");
    append_str(info, get_word(buf, 28, '\n'));
    append_str(info, "\n");
    append_str(info, "context switches:");
    append_str(info, "\n");
    append_str(info, get_word(buf, 54, '\n'));
    append_str(info, "\n");
    append_str(info, get_word(buf, 55, '\n'));
    append_str(info, "\n");

    return info;
}

char *get_short_info(char *buf, char *pid)
{
    char *info = calloc(300, 1);
    append_str(info, "pid: ");
    append_str(info, pid);
    append_str(info, "\n");
    append_str(info, get_word(buf, 0, '\n'));
    append_str(info, "\n");
    append_str(info, "-----------\n");

    return info;
}